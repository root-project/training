{
   double x = .5;
   int N = 30;
   double gs = 0;

   for (int i=0;i<N;++i) gs += pow(x,i);

   auto diff = std::abs(gs - (1/(1-x)));

   std::cout << "The difference is " << diff << std::endl;

}
