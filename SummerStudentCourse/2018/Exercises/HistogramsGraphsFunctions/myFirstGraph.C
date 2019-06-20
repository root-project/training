{
// We create a canvas holding the graphics primitives 
// without relying on the default one root provides
TCanvas c;
c.SetGrid();
c.SetLogy();

TGraph g;
for (auto i : {0,1,2,3,4}) g.SetPoint(i,i,i*i);

// Now the style
g.SetMarkerStyle(kFullTriangleUp);
g.SetMarkerSize(3);
g.SetMarkerColor(kAzure);
g.SetLineColor(kRed - 2);
g.SetLineWidth(11);
g.SetLineStyle(3);
g.SetTitle("My Graph;The X;My Y");
g.Draw("APL");
txt = "#color[804]{My text #mu {}^{40}_{20}Ca}";
TLatex l(.2, 10, txt);
l.Draw();

}
