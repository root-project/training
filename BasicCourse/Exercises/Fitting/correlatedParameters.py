import ROOT

'''
Demonstrate how a poorly designed model can lead to inconsistent results
'''

# We fill a histogram with exponentially distributed random numbers
rndm = ROOT.TRandom3(1)
h = ROOT.TH1F("he","Exponential Distribution", 64, 0, 16)
for i in range(256):
    h.Fill(rndm.Exp(1))

# Now we prepare a fit model
f = ROOT.TF1("expo", "[A] * exp(-([B] + x))")
f.SetParameter(0, 1)
f.SetParameter(1, 1)

fitRes = h.Fit(f, "S")

fitRes.GetCorrelationMatrix().Print()

print("Why such a high correlation between the A and B paramerters?")



