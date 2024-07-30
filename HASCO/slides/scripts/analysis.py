import ROOT

rdf = ROOT.RDataFrame("Events", "Run*.root");

# rdf = rdf.Range(0, 100000)
rdf = rdf.Range(0, 1000000)

rdf = rdf.Filter("nElectron == 2")

# ROOT.gInterpreter.Declare("""

# double get

# """)

rdf = rdf.Define("Dielectron_mass", "InvariantMass(Electron_pt, Electron_eta, Electron_phi, Electron_mass)")

h = rdf.Histo1D(("Dielectron_mass", "Dielectron mass;m_{ee} (GeV);N_{Events}", 1000, 0, 200), "Dielectron_mass")


# fit_func = ROOT.TF1("fit_func", "gaus")
model = ROOT.TF1("model","NSUM(expo, gaus)", 60, 120)

model.SetParameters(1000, 5000, -0.01, 90, 10)

# model.Print()

h.Fit(model, "L", "", 60, 120)

h.Draw()
# model.Draw("SAME")

ROOT.gPad.SaveAs("histo.png")
