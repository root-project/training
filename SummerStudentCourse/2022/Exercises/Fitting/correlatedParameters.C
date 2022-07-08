// Demonstrate how a poorly designed model can lead to inconsistent results

{
// We fill a histogram with exponentially distributed random numbers
TRandom3 rndm(1);
TH1D h("he","Exponential Distribution", 64, 0, 16);
for (auto i : ROOT::TSeqI(256)) { //TSeqI generates in integer sequence
  h.Fill(rndm.Exp(1));
}

// Now we prepare a fit model
TF1 f("expo", "[A] * exp(-([B] + x))");
f.SetParameter(0, 1);
f.SetParameter(1, 1);

auto fitRes = h.Fit(&f, "S");

fitRes->GetCorrelationMatrix().Print();

std::cout << "Question:\n\tWhy is there such a high correlation between the parameters A and B?" << std::endl;
}
