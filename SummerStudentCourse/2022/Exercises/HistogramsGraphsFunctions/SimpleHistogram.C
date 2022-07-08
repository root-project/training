void SimpleHistogram()
{
   // Create a histogram with 50 bins and an x axis ranging from 0 to 10
   auto h = new TH1D("myHisto", "Exponential distribution; Observed events;time", 50, 0, 10);

   // Fill it with random numbers distributed according to an Exponential distribution
   // Use the global ROOT TRandom instance for generating random numbers 
   double rate = 0.5;
   for (int i = 0; i < 1000; i++)
      h->Fill(gRandom->Exp(1./rate));

   // Change its line width with a thicker one
   h->SetLineWidth(3);

   // Draw!
   h->Draw();
}
