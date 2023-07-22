void figure005()
{
   TGraph g;
   for (auto i : {0,1,2,3,4}) {
       g.SetPoint(i,i,i*i);
   }
   g.Draw("APL");

   g.SetMarkerStyle(kFullTriangleUp);
   g.SetMarkerSize(3);
   g.SetMarkerColor(kAzure);
   g.SetLineColor(kRed - 2);
   g.SetLineWidth(2);
   g.SetLineStyle(3);
   g.SetTitle("My Graph;The X;My Y");
   gPad->SetGrid();
   auto txt = "#color[804]{#mu {}^{40}_{20}Ca}";
   TLatex l(.2, 10, txt);
   l.Draw();
   gPad->SetLogy();;

   gPad->SaveAs("figure-005.pdf");
}
