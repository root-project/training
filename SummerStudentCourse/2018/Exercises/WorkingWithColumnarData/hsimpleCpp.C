{

   // Old way
   auto c = new TCanvas();
   c->Divide(3,1);

   TFile f("hsimple.root");
   TNtuple *ntuple;
   f.GetObject("ntuple", ntuple);

   TH1F h("xysum", "XY Sum;The Sum;Number of Entries", 64, -10, 10);

   auto nRows = ntuple->GetEntries();
   for (auto iRow : ROOT::TSeqI(nRows)) {
      ntuple->GetEntry(iRow);
      auto row = ntuple->GetArgs();
      auto px = row[0];
      auto py = row[1];
      auto pz = row[2];
      if (std::abs(pz) < 2) h.Fill(px + py);
   }

   c->cd(1);
   h.DrawCopy();

   // New way jitted
   auto df = ROOT::RDataFrame("ntuple", "hsimple.root");
   auto h2 = df.Filter("fabs(pz) < 2")
               .Define("pxpy", "px+py")
               .Histo1D({"xysum", "XY Sum;The Sum;Number of Entries", 64, -10, 10}, "pxpy");

   c->cd(2);
   h2->DrawCopy();

   // New way compiled
   auto df2 = ROOT::RDataFrame("ntuple", "hsimple.root");
   auto h3 = df2.Filter([](float pz){return fabs(pz) < 2;}, {"pz"})
                .Define("pxpy", [](float px, float py){return px+py;}, {"px", "py"})
                .Histo1D({"xysum", "XY Sum;The Sum;Number of Entries", 64, -10, 10}, "pxpy");

   c->cd(3);
   h3->DrawCopy();

}
