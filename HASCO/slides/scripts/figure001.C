{

TCanvas c1;

TH1D h("myHist", "myTitle", 64, -4.0, 4.0);
h.FillRandom("gaus");
h.Draw();

c1.SaveAs("figure-001.pdf");

}
