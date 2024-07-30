void figure010()
{

   TH1D h("myHist", "Example histogram", 64, -4.0, 4.0);
   h.FillRandom("gaus");

   TF1 f1("f1","gaus");
   h.Fit(&f1,"","",-1.5,1.5);

   gStyle->SetOptFit(1111);


   gPad->SaveAs("figure-010.pdf");

}
