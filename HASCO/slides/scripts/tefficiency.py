import ROOT

ROOT.gROOT.SetBatch(True)

h_pass = ROOT.TH1D("h_pass", "My histogram", 50, 0, 100.0)
h_total = ROOT.TH1D("h_total", "My histogram", 50, 0, 100.0)

f_gaus = ROOT.TF1("f_gaus", "gaus", 0, 100.0)

f_gaus.SetParameters(1.0, 56.0, 20.0)
h_pass.FillRandom("f_gaus", 40000)
h_pass.SetLineColor(ROOT.kRed)
f_gaus.SetParameters(1.0, 50.0, 20.0)
h_total.FillRandom("f_gaus", 100000)

teff = ROOT.TEfficiency(h_pass,h_total)

c1 = ROOT.TCanvas()
h_total.Draw()
h_pass.Draw("SAME")
c1.SaveAs("tefficiency_1.pdf")

c2 = ROOT.TCanvas()
teff.Draw()
c2.SaveAs("tefficiency_2.pdf")
