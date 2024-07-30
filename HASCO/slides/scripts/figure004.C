{
TGraph g;
for (auto i : {0,1,2,3,4}) {
    g.SetPoint(i,i,i*i);
}
g.Draw("APL");

gPad->SaveAs("figure-004.pdf");
}
