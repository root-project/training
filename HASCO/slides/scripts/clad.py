import ROOT
import numpy as np

ROOT.gROOT.SetBatch()

ROOT.gInterpreter.Declare("""
#include "clad/Differentiator/Differentiator.h"

double myfunc(double x) {
  return x*x;
}

auto myfunc_dx_clad = clad::differentiate(myfunc, "x");

double myfunc_dx(double x) {
  return myfunc_dx_clad.execute(x);
}

""")

gr = ROOT.TGraph()
gr_dx = ROOT.TGraph()
for i, x in enumerate(np.linspace(-2, 2, 200)):
    gr.SetPoint(i, x, ROOT.myfunc(x))
    gr_dx.SetPoint(i, x, ROOT.myfunc_dx(x))

gr.SetLineWidth(2)
gr_dx.SetLineWidth(2)

gr.SetLineColor(ROOT.kBlue)
gr_dx.SetLineColor(ROOT.kRed)

c1 = ROOT.TCanvas()
gr_dx.Draw("APL")
gr.Draw("SAME")
c1.Draw()
c1.SaveAs("clad.pdf")
