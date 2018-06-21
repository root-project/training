void SimpleHistogram()
{
   // Create a histogram with 64 bins and an x axis ranging from 0 to 16
   auto h = new TH1F("myPyHisto", "Productivity;C++ Knowledge;Productivity", 64, 0, 16);

   // Fill it with random numbers distributed according to a linear function ("pol1")
   h->FillRandom("pol1");

   // Change its line width with a thicker one
   h->SetLineWidth(4);

   // Draw!
   h->Draw();
}
