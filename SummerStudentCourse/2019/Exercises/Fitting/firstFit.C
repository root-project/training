// This macro allows us to study the result of a fit
{

  // --------------------------------------------------------------------------
  // Preparation of the histogram to fit

  // Create First an empty histogram with 50 bins with range [-10,10]
  TH1D h1("h1", "h1", 50, -10, 10);

  // Fill the histogram with 10000 Gaussian Random numbers with mean=1 and
  // sigma=2
  // Hint: Find the TRandom3 documentation.
  // Hint 2: If you don't find what you are looking for, check also the TRandom functions on TRandom3's
  // documentation
  TRandom3 randomGenerator(1);
  Your code here

  // Let's now draw the histogram
  Your code here

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

  // print the result
  Your code here

  // We now get the correlation matrix of the fit from the TFitResult object and print it
  Your code here


  std::cout << "Gaussian sigma = " << f1->GetParameter("Sigma") << "  +/- "
            << f1->GetParError(f1->GetParNumber("Sigma")) << std::endl;

  // Gaussian sigma = 2.08778  +/- 0.0
}
