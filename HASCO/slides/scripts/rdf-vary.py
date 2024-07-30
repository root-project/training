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

using RVecF = ROOT::VecOps::RVec<float>;
using RVecD = ROOT::VecOps::RVec<double>;

auto makeP4(RVecF& pt, RVecF& eta, RVecF& phi, RVecF& mass) {
    std::vector<LorentzVector<PtEtaPhiM4D<float> >> out;
    for(std::size_t i = 0; i < pt.size(); ++i) {
        out.emplace_back(pt[i], eta[i], phi[i], mass[i]);
    }
    return out;
}
""")

ROOT.gInterpreter.Declare("""
auto varyPtCut(double ptCut) {
    return RVecD{ptCut - 5, ptCut + 5};
}
""")

def analyze(filename):
    rdf = ROOT.RDataFrame("Events", filename);
    # rdf = rdf.Range(0, 100000)
    rdf = rdf.Filter("nElectron == 2")
    rdf = rdf.Define("Electron_p4", "makeP4(Electron_pt, Electron_eta, Electron_phi, Electron_mass)")
    rdf = rdf.Define("Dielectron_mass", "(Electron_p4[0] + Electron_p4[1]).mass()")
    rdf = rdf.Define("ptCut", "10.0")
    rdf = rdf.Vary("ptCut", "varyPtCut(ptCut)", ("down", "up"))
    rdf = rdf.Filter("Electron_pt[0] > ptCut && Electron_pt[1] > ptCut")
    return rdf.Histo1D(("Dielectron_mass", "Dielectron mass;m_{ee} (GeV);N_{Events}", 1000, 0, 200), "Dielectron_mass")

h = analyze("*_DoubleElectron.root")
hvars = ROOT.RDF.Experimental.VariationsFor(h)

h1 = hvars["nominal"]
h2 = hvars["ptCut:down"]
h3 = hvars["ptCut:up"]

h2.SetLineColor(ROOT.kRed)
h3.SetLineColor(ROOT.kGreen)

h1.SetLineWidth(2)
h2.SetLineWidth(2)
h3.SetLineWidth(2)

# h1.SetName("h1")
h2.SetName("h2")
h3.SetName("h3")

h1.Draw("")
h2.Draw("SAME")
h3.Draw("SAME")

legend = ROOT.TLegend(0.1,0.7,0.38,0.9)
legend.AddEntry(h2.GetName(),"p_T > 10 GeV","l")
legend.AddEntry(h1.GetName(),"p_T > 15 GeV","l")
legend.AddEntry(h3.GetName(),"p_T > 20 GeV","l")
legend.Draw()

ROOT.gStyle.SetOptFit(1111)

ROOT.gPad.SaveAs("histo.png")
ROOT.gPad.SaveAs("histo.pdf")
