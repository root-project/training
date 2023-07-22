void figure008()
{
   using namespace RooFit;

// Observable:
   RooRealVar mes("mes","m_{ES} (GeV)",5.20,5.30);

// Parameters:
   RooRealVar sigmean("sigmean","B^{#pm} mass",5.28,5.20,5.30);
   RooRealVar sigwidth("sigwidth","B^{#pm} width",0.0027,0.001,1.);

// Build a Gaussian PDF:
   RooGaussian signalModel("signal","signal PDF",mes,sigmean,sigwidth);

// Build Argus background PDF:
   RooRealVar argpar("argpar","argus shape parameter",-20.0,-100.,-1.);
   RooArgusBG background("background","Argus PDF",mes,RooConst(5.291),argpar);

// Construct a signal and background PDF:
   RooRealVar nsig("nsig","#signal events",200,0.,10000);
   RooRealVar nbkg("nbkg","#background events",800,0.,10000);
   RooAddPdf model("model","g+a",RooArgList(signalModel,background),RooArgList(nsig,nbkg));

// The PDF is used to generate an un-binned toy data set, then the PDF is fit to that data set using an un-binned maximum likelihood fit.
// Then the data are visualized with the PDF overlaid.

// Generate a toy MC sample from composite PDF:
   RooDataSet *data = model.generate(mes, 2000);

// Perform extended ML fit of composite PDF to toy data:
   model.fitTo(*data);

// Plot toy data and composite PDF overlaid:
   RooPlot* mesframe = mes.frame();
   data->plotOn(mesframe);
   model.plotOn(mesframe);
   model.plotOn(mesframe, Components(background), LineStyle(ELineStyle::kDashed));

   mesframe->Draw();

   gPad->SaveAs("figure-008.pdf");
}
