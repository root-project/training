{
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

   h.Draw();
}
