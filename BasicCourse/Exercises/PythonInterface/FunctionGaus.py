
from ROOT import TH1F, TF1

# Create, fill and draw histogram
h = TH1F("myHist", "myTitle", 64, -4, 4)
h.FillRandom("gaus")
h.Draw()

# Create and draw function in the same canvas
f = TF1("g", "gaus", -8, 8)
f.SetParameters(250, 0, 1)
f.Draw("Same")

