{
TCanvas c1;

TF1 f2("f2","[0]*sin([1]*x)/x",0.,10.);
f2.SetParameters(1,1);
f2.Draw();

c1.SaveAs("figure-002.pdf");
}
