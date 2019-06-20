
void SimpleFunction()
{
   // Create a function with formula "cos(x)" and draw it
   auto f1 = new TF1("f1", "cos(x)", 0., 10.);
   f1->Draw();

   // Create another function based on "cos(x)" with a parameter
   auto f2 = new TF1("f2", "cos(x/[0])", 0., 10.);
   f2->SetParameter(0, 2);
   f2->SetLineColor(kBlue);
   f2->Draw("Same");
}
