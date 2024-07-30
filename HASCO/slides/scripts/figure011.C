void figure011() {

using namespace RooFit;

// observables
RooRealVar x{"x", "x", 0, 0, 10};

// parameters
RooRealVar mu{"mu", "mu", 4, 0, 10};
RooRealVar sigma{"sigma", "sigma", 1, 0.01, 10};
RooRealVar c{"c", "c", -0.1, -10, -0.001};

// model components
RooGaussian gauss{"gauss", "gauss", x, mu, sigma};
RooExponential expo{"expo", "expo", x, c};
RooAddPdf model{"model", "0.2 * gauss + 0.8 * expo",
                {gauss, expo}, {RooConst(0.2)}};

// toy data generation
std::unique_ptr<RooDataSet> data{model.generate(x, 10000)};

// fitting
model.fitTo(*data);

model.graphVizTree("model.dot");

{
// plotting
TCanvas c1;
RooPlot* frame = x.frame();
model.plotOn(frame);
frame->Draw();
c1.SaveAs("figure-011a.pdf");
}

{
// plotting
TCanvas c1;
RooPlot* frame = x.frame();
data->plotOn(frame);
model.plotOn(frame);
frame->Draw();
c1.SaveAs("figure-011.pdf");
}

}
