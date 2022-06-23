void SimpleGraph()
{
   // Create the graph on the heap (with 'new') so that it survives the end of the macro
   auto g = new TGraph();

   // Set the points
   std::initializer_list<std::pair<float, float>> points = {{1,0}, {2,3}, {3,4}};
   int i = 0;
   for(auto &&point : points) {
      g->SetPoint(i++, point.first, point.second);
   }

   // Set the style
   g->SetTitle("My graph;my_{X};my_{Y}");
   g->SetLineColor(kOrange);
   g->SetLineWidth(2);
   g->SetMarkerStyle(kFullSquare);
   g->SetMarkerColor(kRed);
   
   // Draw!
   g->Draw("APL");
}
