import ROOT

h = ROOT.TH1F("xysum", "XY Sum;The Sum;Number of Entries", 64, -10, 10)

f = ROOT.TFile("hsimple.root")
for evt in f.ntuple:
    if abs(evt.pz) < 2:
      h.Fillt(evt.px + evt.py)

h.Draw()
