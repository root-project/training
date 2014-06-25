#define ProofEventSelector_cxx
// The class definition in ProofEventSelector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("ProofEventSelector.C")
// Root > T->Process("ProofEventSelector.C","some options")
// Root > T->Process("ProofEventSelector.C+")
//

#include "ProofEventSelector.h"
#include "TH1.h"
#include "TStyle.h"


void ProofEventSelector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   fPosX = new TH1F("hPosX", "Position in X", 20, -5, 5);
   // enable bin errors:
   fPosX->Sumw2();
   // Add to output list (needed for PROOF)
   GetOutputList()->Add(fPosX);
}

Bool_t ProofEventSelector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree to be 
   // processed. The entry argument specifies which entry in the currently
   // loaded tree is to be processed.
   // It can be passed to either EventSelector::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the TTree.
   //
   // This function should contain the "body" of the analysis: select relevant
   // tree entries, run algorithms on the tree entry and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   // *** 1. *** Tell the tree to load the data for this entry:
   // We only need the number of particles...
   fNParticlesBranch->GetEntry(entry);
   // ... and their position in X...
   fParticlesPosXBranch->GetEntry(entry);
   // ... and their momentum
   fParticlesMomentumBranch->GetEntry(entry);

   // *** 2. *** Do the actual analysis
   for (int iParticle = 0; iParticle < fNParticles; ++iParticle) {
      if (fParticlesMomentum[iParticle] > 40.0)
         fPosX->Fill(fParticlesPosX[iParticle]);
   }

   return kTRUE;
}

void ProofEventSelector::Terminate()
{
   // The Terminate() function is the last function to be called during the
   // analysis of a tree with a selector. It always runs on the client, it can
   // be used to present the results graphically or save the results to file.

   // Fit the histogram:
   fPosX->Fit("pol2");

   // and draw it:
   fPosX->Draw();
}
