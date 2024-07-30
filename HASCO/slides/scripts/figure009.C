void drawLine(double xmin, double ymin, double xmax, double ymax)
{
    auto line = new TLine(xmin, ymin, xmax, ymax);
    line->SetLineColor(kRed);
    line->SetLineStyle(kDashed);
    line->SetLineWidth(3);
    line->Draw();
}

void figure009()
{
    using namespace RooFit; // for the command arguments like Bins(), Range(), etc.

    // Construct the model
    RooWorkspace ws("ws");

    ws.factory("Gaussian::g1(x[-20,20],mean[-10,10],sigma_g1[3, 0.1, 10.0])");
    ws.factory("Gaussian::g2(x,mean,sigma_g2[4,3,6])");
    ws.factory("SUM::model(frac[0.5,0,1]*g1,g2)");

    RooRealVar *x = ws.var("x");
    RooRealVar *frac = ws.var("frac");
    RooAbsPdf *model = ws.pdf("model");

    // Generate 1000 events
    std::unique_ptr<RooDataSet> data{model->generate(*x, 120)};

    // We set sigma_g1 constant to simplify the fit
    ws.var("sigma_g1")->setConstant();

    // Create a likelihood function
    std::unique_ptr<RooAbsReal> nll{model->createNLL(*data)};

    //// Minimize the likelihood
    std::unique_ptr<RooFitResult> result{model->fitTo(*data, PrintLevel(-1), Save(), Minos(RooArgSet{*frac}))};
    result->Print();
    frac->Print();
    std::cout << frac->getErrorLo() << std::endl;
    std::cout << frac->getErrorHi() << std::endl;

    double xMin = 0.2;
    double xMax = 0.95;

    // Plot a likelihood scan in parameter frac
    RooPlot *frame1 = frac->frame(Bins(10), Range(xMin, xMax), Title("-log profile likelihood ratio"));
    nll->plotOn(frame1, ShiftToZero());

    frame1->GetYaxis()->SetTitle("-log L");
    frame1->GetXaxis()->SetTitle("#theta");

    auto c1 = new TCanvas{"c1", "", 300, 300};

    frame1->Draw();

    drawLine(xMin,0.5,xMax,0.5);

    drawLine(0.41,0.0,0.41,0.5);
    drawLine(0.813,0.0,0.813,0.5);

    c1->Draw();

    c1->SaveAs("figure-009.pdf");
}
