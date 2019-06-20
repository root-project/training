{

// First we create and draw the histogram in the default canvas
TH1F h("myHist", "myTitle", 64, -4, 4);
h.FillRandom("gaus");
h.Draw();

// Then the function
TF1 f("g", "gaus", -8, 8);
f.SetParameters(250, 0, 1);
f.Draw("Same");

}
