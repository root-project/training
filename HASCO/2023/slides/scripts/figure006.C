void figure006()
{

   TH1D h("myHist", "Example histogram", 64, -4.0, 4.0);
   h.FillRandom("gaus");

   TF1 f1("f1","gaus");
   h.Fit(&f1);

   gStyle->SetOptFit(1111);


   gPad->SaveAs("figure-006.pdf");

}
