void figure007()
{
   TF1 f1{"f1", "gaus", -4.0, 4.0};

   TH1D h1("h1", "x", 64, -4.0, 4.0);
   TH1D h2("h2", "x", 64, -4.0, 4.0);
   TH1D h3("h3", "x", 64, -4.0, 4.0);

   THStack hs("hs","");
   hs.SetTitle(";x;Events");

   std::vector<TH1D*> histos{&h1, &h2, &h3};
   std::vector<int> colors{46, 30, 38};

   for(int i = 0; i < histos.size(); ++i) {
       TH1D & h = *histos[i];
       f1.SetParameters(1.0, i - 1, 1.0);
       h.FillRandom("f1", 100000);
       h.SetFillColor(colors[i]);
       hs.Add(&h);
   }

   hs.Draw();

   gPad->SaveAs("figure-007.pdf");
}
