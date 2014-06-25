// This class is derived from the ROOT class TSelector. 
// For more information on the TSelector framework see 
// $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The file for this selector can be found at
// http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root
// i.e run
//   root [0] f = TFile::Open("http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root");
//   root [1] EventTree->Process("EventDataSelector.C+")

// The following methods are defined in this file:
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers, a convenient place to create your histograms.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("EventDataSelector.C")
// Root > T->Process("EventDataSelector.C","some options")
// Root > T->Process("EventDataSelector.C+")
//

#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TSelector.h"
#include "TProofServ.h"
#include "TH1.h"
#include "TStyle.h"

const Int_t kMaxfParticles = 1293;

class EventDataSelector : public TSelector {
public :

   // Declaration of leaf types
   Int_t        fNParticles;
   Double_t     fParticlesPosX[kMaxfParticles];       //[fNParticles]
   Double_t     fParticlesMomentum[kMaxfParticles];   //[fNParticles]

   // List of branches
   TBranch     *fNParticlesBranch;
   TBranch     *fParticlesPosXBranch;
   TBranch     *fParticlesMomentumBranch;

   EventDataSelector(TTree * = 0) { }

   virtual ~EventDataSelector() { }
   virtual void    Init(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    Terminate();
   virtual Int_t   Version() const { return 2; }

   ClassDef(EventDataSelector,0);
};

void EventDataSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // To use SetBranchAddress() with simple types (e.g. double, int)
   // instead of objects (e.g. std::vector&lt;Particle&gt;).
   tree->SetMakeClass(1);

   // Connect the branches with their member variables.
   tree->SetBranchAddress("fParticles", &fNParticles, &fNParticlesBranch);
   tree->SetBranchAddress("fParticles.fPosX", fParticlesPosX, &fParticlesPosXBranch);
   tree->SetBranchAddress("fParticles.fMomentum", fParticlesMomentum, &fParticlesMomentumBranch);
}

void EventDataSelector::SlaveBegin(TTree *tree)
{
   // SlaveBegin() is a good place to create histograms. 
   // For PROOF, this is called for each worker.
   // The TTree* is there for backward compatibility; e.g. PROOF passes 0.

}

Bool_t EventDataSelector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree to be 
   // processed. The entry argument specifies which entry in the currently
   // loaded tree is to be processed.
   // It can be passed to either EventSelector::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the TTree.
   //
   // This function should contain the "body" of the analysis: select relevant
   // tree entries, run algorithms on the tree entry and typically fill histograms.

   // *** 1. *** Tell the tree to load the data for this entry:
   // We only need the number of particles...
   fNParticlesBranch->GetEntry(entry);
   // ... and their position in X...
   fParticlesPosXBranch->GetEntry(entry);
   // ... and their momentum
   fParticlesMomentumBranch->GetEntry(entry);

   // *** 2. *** Do the actual analysis

   return kTRUE;
}

void EventDataSelector::Terminate()
{
   // The Terminate() function is the last function to be called during the
   // analysis of a tree with a selector. It always runs on the client, it can
   // be used to present the results graphically or save the results to file.

}
