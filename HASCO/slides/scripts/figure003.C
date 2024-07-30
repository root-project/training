void figure003()
{

   TH1D h("myHist", "myTitle", 64, -4, 4);
   h.FillRandom("gaus");
   h.Draw();
   TF1 f("g", "gaus", -8, 8);
   f.SetParameters(250, 0, 1);
   f.Draw("Same");

   gPad->SaveAs("figure-003.pdf");

}
