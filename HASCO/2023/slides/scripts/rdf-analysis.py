import ROOT

ROOT.gROOT.SetBatch(True)

lumi = 11.58 * 1000.0 # fb^-1
scale_factor_zz = 1.386
sample_weights = {
    "ZZTo4mu" :  0.077 / 1499064.0 * scale_factor_zz * lumi,
    "ZZTo4e" :  0.077 / 1499093.0 * scale_factor_zz * lumi,
    "ZZTo2e2mu" : 0.18 / 1497445.0 * scale_factor_zz * lumi
}


ROOT.gInterpreter.Declare("""
using ROOT::VecOps::RVec;
using namespace ROOT::Math;

auto makeP4(RVec<Float_t>& pt, RVec<Float_t>& eta, RVec<Float_t>& phi, RVec<Float_t>& mass) {
    std::vector<LorentzVector<PtEtaPhiM4D<float> >> out;
    for(std::size_t i = 0; i < pt.size(); ++i) {
        out.emplace_back(pt[i], eta[i], phi[i], mass[i]);
    }
    return out;
}
""")

rdf = ROOT.RDataFrame("Events", "*_DoubleElectron.root");
# rdf = rdf.Range(0, 100000)
rdf = rdf.Filter("nElectron == 2")
rdf = rdf.Define("Electron_p4", "makeP4(Electron_pt, Electron_eta, Electron_phi, Electron_mass)")
rdf = rdf.Define("Dielectron_mass", "(Electron_p4[0] + Electron_p4[1]).mass()")
h = rdf.Histo1D(("Dielectron_mass", "Dielectron mass;m_{ee} (GeV);N_{Events}", 1000, 0, 200), "Dielectron_mass")

model = ROOT.TF1("model","NSUM(expo, gaus)", 60, 120)

n_events = rdf.Count().GetValue()
print(n_events)
model.SetParameters(1000, n_events, -0.01, 90, 10)

h.Fit(model, "", "", 60, 120)

h.Draw("E")

ROOT.gStyle.SetOptFit(1111)

ROOT.gPad.SaveAs("histo.png")
ROOT.gPad.SaveAs("histo.pdf")
