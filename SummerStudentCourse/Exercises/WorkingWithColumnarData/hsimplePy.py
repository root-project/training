import ROOT

c = ROOT.TCanvas()
c.Divide(2,1)

# Old way
h = ROOT.TH1F("xysum", "XY Sum;The Sum;Number of Entries", 64, -10, 10)

f = ROOT.TFile("hsimple.root")
for evt in f.ntuple:
    if abs(evt.pz) < 2:
      h.Fill(evt.px + evt.py)

c.cd(1)
h.Draw()


# New way
from ROOT.ROOT import RDataFrame
df = RDataFrame("ntuple", "hsimple.root")
h2 = df.Filter("fabs(pz) < 2")\
       .Define("pxpy", "px+py")\
       .Histo1D(("xysum", "XY Sum;The Sum;Number of Entries", 64, -10, 10), "pxpy")

c.cd(2)
h2.Draw()
