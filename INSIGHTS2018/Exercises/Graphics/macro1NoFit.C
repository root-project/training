// First example presented in "The ROOT graphics functionalities"

void macro1NoFit() {
   // The values and the errors on the Y axis
   const int n_points=10;
   double x_vals[n_points] = {1,2,3,4,5,6,7,8,9,10};
   double y_vals[n_points] = {6,12,14,20,22,24,35,45,44,53};
   double y_errs[n_points] = {5,5,4.7,4.5,4.2,5.1,2.9,4.1,4.8,5.43};

   // Instance of the graph
   auto graph = new TGraphErrors(n_points,x_vals,y_vals,nullptr,y_errs);
   graph->SetTitle("Measurement XYZ;length [cm];Arb.Units");

   // Make the plot esthetically better
   graph->SetMarkerStyle(kOpenCircle);
   graph->SetMarkerColor(kBlue);
   graph->SetLineColor(kBlue);

   // The canvas on which we'll draw the graph
   auto  mycanvas = new TCanvas();

   // Draw the graph !
   graph->Draw("APE");

   // Define a linear function
   auto f = new TF1("Linear law","-1+x*5",.5,10.5);
   f->SetLineColor(kRed);
   f->SetLineStyle(2);
   f->Draw("Same");

   // Build and Draw a legend
   auto legend = new TLegend(.1,.7,.3,.9,"Lab. Lesson 1");
   legend->AddEntry(graph,"Exp. Points","PE");
   legend->AddEntry(f,"Th. Law", "L");
   legend->Draw();

   // Draw an arrow on the canvas
   auto arrow = new TArrow(8,8,6.2,23,0.02,"|>");
   arrow->SetLineWidth(2);
   arrow->Draw();

   // Add some text to the plot and highlight the 3rd label
   auto text = new TLatex(8.2,7.5,"#splitline{Maximum}{Deviation}");
   text->Draw();
   graph->GetXaxis()->ChangeLabel(3,-1,-1,-1,kRed);
}
