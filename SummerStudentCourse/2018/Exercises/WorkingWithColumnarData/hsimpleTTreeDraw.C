{
   TFile f("hsimple.root");
   TNtuple *ntuple;
   f.GetObject("ntuple", ntuple);

   TH1F h("xysum", "XY Sum;The Sum;Number of Entries", 64, -10, 10);

   ntuple->Draw("px + py >> xysum", "abs(pz)<2");

   h.Draw();
}
