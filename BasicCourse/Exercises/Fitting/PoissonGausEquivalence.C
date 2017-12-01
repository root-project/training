{

auto mean = 20.;

TF1 p1("p1", "TMath::Poisson(x, 1)", 0, 40);
p1.SetTitle("Poisson-Gauss Comparison;x;P(x)");
p1.SetLineColor(kBlue);
p1.Draw("PLC");
p1.GetYaxis()->SetRangeUser(0, .2);


TF1 p5("p5", "TMath::Poisson(x, 5)", 0, 40);
p5.SetLineColor(kBlue);
p5.Draw("Same PLC");

TF1 p10("p10", "TMath::Poisson(x, 10)", 0, 40);
p10.SetLineColor(kBlue);
p10.Draw("Same PLC");

TF1 p20("p20", "TMath::Poisson(x, 20)", 0, 40);
p20.SetLineColor(kBlue);
p20.Draw("Same PLC");

for (auto f : {&p1, &p5, &p10, &p20}) f->SetLineWidth(11);

TF1 g("g", ".09* TMath::Gaus(x, 20, sqrt(20))", 0, 40);
g.SetLineColor(kRed);
g.SetLineWidth(11);
g.DrawClone("SAME");

TLatex lp(20, .16, "#color[600]{P(x;#mu) = e^{-#mu} #frac{#mu^{x}}{x!}}");
lp.Draw();

TLatex mu5(7, .18, "#color[600]{#mu = 5}");
mu5.Draw();

TLatex mu10(12, .14, "#color[600]{#mu = 10}");
mu10.Draw();

TLatex mu20(27, .07, "#color[600]{#mu = 20}");
mu20.Draw();

TLatex mg2020(27, .05, "#color[2]{#mu = 20, #sigma = #sqrt{20}}");
mg2020.Draw();



TLatex lg(20, .12, "#color[2]{G(x;#mu,#sigma) = #frac{1}{#sqrt{2#pi#sigma}} e^{-#frac{(x-#mu)^{2}}{2#sigma^{2}}}}");
lg.Draw();


}
