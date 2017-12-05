void PoissonGausEquivalence() {
   auto *p5 = new TF1("p5", "TMath::PoissonI(x, 5)", 0, 40);
   auto *p10 = new TF1("p10", "TMath::PoissonI(x, 10)", 0, 40);
   auto *p20 = new TF1("p20", "TMath::PoissonI(x, 20)", 0, 40);

   

   for (auto f : {p5, p10, p20}) {
      f->SetNpx(40);
      f->SetLineWidth(11);
      f->SetLineColor(kBlue);
   }

   // need to use GetHistogram() in 6.12. Fixed in master
   // option HIST + SAME
   p5->GetHistogram()->Draw();
   p5->GetYaxis()->SetRangeUser(0, .2);
   p5->SetTitle("Poisson vs Gauss distribution");
   p10->GetHistogram()->Draw("SAME");
   p20->GetHistogram()->Draw("SAME");

   auto *g = new TF1("g", ".09* TMath::Gaus(x, 20, sqrt(20))", 0, 40);
   g->SetLineColor(kRed);
   g->SetLineWidth(11);
   g->Draw("SAME");

   auto *lp = new TLatex(20, .16, "#color[600]{P(x;#mu) = e^{-#mu} #frac{#mu^{x}}{x!}}");
   lp->Draw();
   auto *mu5 = new TLatex(7, .18, "#color[600]{#mu = 5}");
   mu5->Draw();
   auto *mu10 = new TLatex(12, .14, "#color[600]{#mu = 10}");
   mu10->Draw();
   auto *mu20 = new TLatex(27, .07, "#color[600]{#mu = 20}");
   mu20->Draw();
   auto *mg2020 = new TLatex(27, .05, "#color[2]{#mu = 20, #sigma = #sqrt{20}}");
   mg2020->Draw();
   auto *lg = new TLatex(20, .12, "#color[2]{G(x;#mu,#sigma) = #frac{1}{#sqrt{2#pi#sigma}} e^{-#frac{(x-#mu)^{2}}{2#sigma^{2}}}}");
   lg->Draw();
}
