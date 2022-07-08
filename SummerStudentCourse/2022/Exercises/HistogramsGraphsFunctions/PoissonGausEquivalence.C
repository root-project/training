void PoissonGausEquivalence() {
   auto *p5 = new TF1("p5", "TMath::PoissonI(x, 5)", 0, 40);
   auto *p10 = new TF1("p10", "TMath::PoissonI(x, 10)", 0, 40);
   auto *p20 = new TF1("p20", "TMath::PoissonI(x, 20)", 0, 40);

   

   for (auto f : {p5, p10, p20}) {
      f->SetNpx(40);
      f->SetLineWidth(6);
   }

   p5->SetLineColor(kYellow+3);
   p10->SetLineColor(kGreen+2);
   p20->SetLineColor(kBlue);


   p5->GetHistogram()->Draw();
   p5->GetYaxis()->SetRangeUser(0, .2);
   p5->SetTitle("Poisson vs Gauss distribution");
   p10->GetHistogram()->Draw("SAME");
   p20->GetHistogram()->Draw("SAME");


   auto *g = new TF1("g", ".09* TMath::Gaus(x, 20, sqrt(20))", 0, 40);
   g->SetLineColor(kRed);
   g->SetLineWidth(6);
   g->Draw("SAME");

   auto *lp = new TLatex(20, .16, "#color[600]{P(x;#mu) = e^{-#mu} #frac{#mu^{x}}{x!}}");
   lp->Draw();
   auto *mu5 = new TLatex(7, .18, "#color[403]{#mu = 5}");     // 403 is for kYellow + 3
   mu5->Draw();
   auto *mu10 = new TLatex(12, .14, "#color[418]{#mu = 10}");    // 418 is for Green +2
   mu10->Draw();
   auto *mu20 = new TLatex(27, .07, "#color[600]{#mu = 20}");    // 600 is for kBlue
   mu20->Draw();
   auto *mg2020 = new TLatex(27, .05, "#color[2]{#mu = 20, #sigma = #sqrt{20}}");
   mg2020->Draw();
   auto *lg = new TLatex(20, .12, "#color[2]{G(x;#mu,#sigma) = #frac{1}{#sqrt{2#pi#sigma}} e^{-#frac{(x-#mu)^{2}}{2#sigma^{2}}}}");
   lg->Draw();
}
