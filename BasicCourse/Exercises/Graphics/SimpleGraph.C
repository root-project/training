void SimpleGraph()
{
   TGraph g;

   // Set the points
   std::initializer_list<std::pair<float, float>> points = {{1,0}, {2,3}, {3,4}};
   int i = 0;
   for(auto &&point : points) {
      g.SetPoint(i++, point.first, point.second);
   }

   // Set the style
   g.SetTitle("My graph;my_{X};myY");
   g.SetLineColor(kOrange);
   g.SetLineWidth(2);
   g.SetMarkerStyle(kFullSquare);
   g.SetMarkerColor(kRed);
   
   // Draw. To avoid the graphics primitive to be deleted
   // at the end of the scope, we draw a clone of it.
   g.DrawClone("APL");
}
