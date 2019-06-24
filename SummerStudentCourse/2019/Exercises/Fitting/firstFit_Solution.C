// This macro allows us to study the result of a fit
{

  // --------------------------------------------------------------------------
  // Preparation of the histogram to fit

  // Create First an empty histogram with 50 bins with range [-10,10]
  TH1D h1("h1", "h1", 50, -10, 10);

  // Fill the histogram with 10000 Gaussian Random number with mean=1 and
  // sigma=2
  // Hint: Find the TRandom3 documentation.
  // Hint 2: If you don't find what you are looking for, check also the TRandom functions on TRandom3's
  // documentation
  TRandom3 randomGenerator(1);
  for (int i = 0; i < 1000; ++i) {
    h1.Fill(randomGenerator.Gaus(1, 2));
  }

  // Let's now draw the histogram
  h1.Draw();

  // --------------------------------------------------------------------------
  // Before Fitting we need to create the fitting function and set its initial
  // parameter values.

  auto f1 = new TF1("f1", "gaus", -10,
                    10); // We use new to have this surviving the scope
  f1->SetParameters(100, 0, 1);

  // We fit now the histogram using the Fit method in ROOT. By default the
  // least-square method is used. For likelihood fits we need to use the option
  // "L". The option "S" is used to create a TFitResult object that is returned
  // to the user. If we want to compute the error using MINOS, we use the "E"
  // option We want to change also the default Minimization engine. We will use
  // Minuit2

  ROOT::Math::MinimizerOptions::SetDefaultMinimizer("Minuit2");

  auto res = h1.Fit(f1, "L S E");

  res->Print();

  // ****************************************
  // Minimizer is Minuit2 / Migrad
  // Chi2                      =      35.8313
  // NDf                       =           29
  // Edm                       =  1.53927e-06
  // NCalls                    =           61
  // Constant                  =      74.0249   +/-   3.02719
  // Mean                      =      1.02272   +/-   0.0685141
  // Sigma                     =      2.08778   +/-   0.0545989 (limited)

  // We now get the correlation matrix of the fit from the TFitResult class

  auto corrMatrix = res->GetCorrelationMatrix();

  corrMatrix.Print();

  // 3x3 matrix is as follows

  //      |      0    |      1    |      2    |
  // --------------------------------------------
  //    0 |          1    0.007831     -0.6162
  //    1 |   0.007831           1    -0.02075
  //    2 |    -0.6162    -0.02075           1

  std::cout << "Gaussian sigma = " << f1->GetParameter("Sigma") << "  +/- "
            << f1->GetParError(f1->GetParNumber("Sigma")) << std::endl;

  // Gaussian sigma = 2.08778  +/- 0.0
}
