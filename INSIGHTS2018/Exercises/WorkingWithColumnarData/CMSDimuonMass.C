int CMSDimuonMass()
{
   // Let's first create a TDF that will read from the CSV file.
   // The types of the columns will be automatically inferred.
   auto fileName = "tdf014_CsvDataSource_MuRun2010B.csv";
   auto tdf = ROOT::Experimental::TDF::MakeCsvDataFrame(fileName);
   // Now we will apply a first filter based on two columns of the CSV,
   // and we will define a new column that will contain the invariant mass.
   // Note how the new invariant mass column is defined from several other
   // columns that already existed in the CSV file.
   auto chargeF = [](int Q1, int Q2){return Q1 * Q2 == -1;};
   auto filteredEvents =
      tdf.Filter(chargeF, {"Q1", "Q2"})
         .Define("m", "sqrt(pow(E1 + E2, 2) - (pow(px1 + px2, 2) + pow(py1 + py2, 2) + pow(pz1 + pz2, 2)))");
   // Next we create a histogram to hold the invariant mass values and we draw it.
   auto invMass =
      filteredEvents.Histo1D({"invMass", "CMS Opendata: #mu#mu mass;#mu#mu mass [GeV];Events", 512, 2, 110}, "m");
   auto c = new TCanvas();
   c->SetLogx();
   c->SetLogy();
   invMass->DrawClone();

   return 0;
}
