//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jul 12 16:48:19 2011 by ROOT version 5.31/01
// from TTree EventTree/Tutorial tree
// found on file: http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root
//////////////////////////////////////////////////////////

#ifndef ProofEventSelector_h
#define ProofEventSelector_h

#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TSelector.h"
#include "TProofServ.h"
#include "TH1.h"

const Int_t kMaxfParticles = 1293;

class ProofEventSelector : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   TH1         *fPosX; // X position of the particles

   // Declaration of leaf types
   Int_t        fNParticles;
   Double_t     fParticlesPosX[kMaxfParticles];       //[fNParticles]
   Double_t     fParticlesMomentum[kMaxfParticles];   //[fNParticles]

   // List of branches
   TBranch     *fNParticlesBranch;
   TBranch     *fParticlesPosXBranch;
   TBranch     *fParticlesMomentumBranch;

   ProofEventSelector(TTree * = 0): fPosX(0) { }
   virtual ~ProofEventSelector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    Terminate();

   ClassDef(ProofEventSelector,0);
};

#endif

#ifdef ProofEventSelector_cxx
void ProofEventSelector::Init(TTree *tree)
{
   // SlaveBegin() is a good place to create histograms. 
   // For PROOF, this is called for each worker.

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   // To use SetBranchAddress() with simple types (e.g. double, int)
   // instead of objects (e.g. std::vector<Particle>).
   fChain->SetMakeClass(1);

   // Connect the branches with their member variables.
   tree->SetBranchAddress("fParticles", &fNParticles, &fNParticlesBranch);
   tree->SetBranchAddress("fParticles.fPosX", fParticlesPosX, &fParticlesPosXBranch);
   tree->SetBranchAddress("fParticles.fMomentum", fParticlesMomentum, &fParticlesMomentumBranch);
}

Bool_t ProofEventSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef ProofEventSelector_cxx
