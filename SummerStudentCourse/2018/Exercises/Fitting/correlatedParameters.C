// Demonstrate how a poorly designed model can lead to inconsistent results

{
// We fill a histogram with exponentially distributed random numbers
TRandom3 rndm(1);
TH1F h("he","Exponential Distribution", 64, 0, 16);
for (auto i : ROOT::TSeqI(256)) h.Fill(rndm.Exp(1));

// Now we prepare a fit model
TF1 f("expo", "[A] * exp(-([B] + x))");
f.SetParameter(0, 1);
f.SetParameter(1, 1);

auto fitRes = h.Fit(&f, "S");

fitRes->GetCorrelationMatrix().Print();

std::cout << "Why such a high correlation between the A and B paramerters?" << std::endl;
}
