{

TH1D h("myHist", "myTitle", 64, -4.0, 4.0);
h.FillRandom("gaus");
h.Draw();

gPad->SaveAs("figure-001.pdf");

}
