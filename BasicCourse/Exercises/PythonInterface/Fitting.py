
import ROOT

# Define functions for fitting 
# Quadratic background function
ROOT.gInterpreter.ProcessLine('''
double background(double *x, double *par) {
  return par[0] + par[1]*x[0] + par[2]*x[0]*x[0];
}
''')

# Lorenzian Peak function
ROOT.gInterpreter.ProcessLine('''
double lorentzianPeak(double *x, double *par) {
  return (0.5*par[0]*par[1]/TMath::Pi()) /
    TMath::Max(1.e-10,(x[0]-par[2])*(x[0]-par[2])
    + .25*par[1]*par[1]);
}
''')

# Sum of background and peak function
ROOT.gInterpreter.ProcessLine('''
double fitFunction(double *x, double *par) {
  return background(x, par) + lorentzianPeak(x, &par[3]);
}
''')

# Construct and fill a histogram with the following bin content data
nbins = 60
data = [ 6,1,10,12,6,13,23,22,15,21,
         23,26,36,25,27,35,40,44,66,81,
         75,57,48,45,46,41,35,36,53,32,
         40,37,38,31,36,44,42,37,32,32,
         43,44,35,33,33,39,29,41,32,44,
         26,39,29,35,32,21,21,15,25,15 ]
xlow = 0
xup = 3

histo = ROOT.TH1F('histo', 'Lorentzian Peak on Quadratic Background', nbins, xlow, xup)

for i in range(nbins):
   histo.SetBinContent(i+1, data[i])
  
# Create a TF1 with the range from 0 to 3 and 6 parameters
nparams = 6
fitFcn = ROOT.TF1('fitFcn', ROOT.fitFunction, xlow, xup, nparams)

# Try to fit the function with the histogram without setting any parameter
histo.Fit(fitFcn)

# Set parameters and fit again, draw histogram with error bars
fitFcn.SetParameter(4, 0.2); # width
fitFcn.SetParameter(5, 1);   # peak
histo.Fit(fitFcn)
histo.Draw('E')

# Construct a TF1 for the background and Lorentzian functions and draw them in the same canvas
# We save the fit results and set the parameters of the functions accordingly
pars = fitFcn.GetParameters()
backFcn = ROOT.TF1('backFcn', ROOT.background, xlow, xup, 3)
backFcn.SetLineColor(ROOT.kGreen)
backFcn.Draw('Same')
backFcn.SetParameters(pars[0], pars[1], pars[2])

signalFcn = ROOT.TF1('signalFcn', ROOT.lorentzianPeak, xlow, xup, 3)
signalFcn.SetLineColor(ROOT.kBlue)
signalFcn.SetParameters(pars[3], pars[4], pars[5])
signalFcn.Draw('Same')

# Draw a legend
legend = ROOT.TLegend(0.6, 0.65, 0.88, 0.85)
legend.SetTextFont(72)
legend.SetTextSize(0.04)
legend.AddEntry(histo, 'Data', 'LE')
legend.AddEntry(backFcn, 'Background fit', 'L')
legend.AddEntry(signalFcn, 'Signal fit', 'L')
legend.AddEntry(fitFcn, 'Global Fit', 'L')
legend.Draw('Same')
