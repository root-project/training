// This class is derived from the ROOT class TSelector. 
// For more information on the TSelector framework see 
// $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The file for this selector can be found at
// http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root
// i.e run
//   root [0] f = TFile::Open("http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root");
//   root [1] EventTree->Process("FullEventDataSelector.C+")

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
// Root > T->Process("FullEventDataSelector.C")
// Root > T->Process("FullEventDataSelector.C","some options")
// Root > T->Process("FullEventDataSelector.C+")
//

#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TSelector.h"
#include "TProofServ.h"
#include "TH1.h"
#include "TStyle.h"
#include "TTreeReader.h"
#include "TTreeReaderArray.h"

class FullEventDataSelector : public TSelector {
public :

   TH1   *fPosX;  // X position of the particles

   // Variables used to access and store the data
   TTreeReader fReader;                            // The tree reader
   TTreeReaderArray<Double_t> fParticlesPosX;      // particles position in X
   TTreeReaderArray<Double_t> fParticlesMomentum;  // particles momentum

   FullEventDataSelector(TTree * = 0): fPosX(0), fParticlesPosX(fReader, "fParticles.fPosX"),
                                       fParticlesMomentum(fReader, "fParticles.fMomentum") { }
   virtual ~FullEventDataSelector() { }
   virtual void    Init(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    Terminate();
   virtual Int_t   Version() const { return 2; }

   ClassDef(FullEventDataSelector,0);
};

void FullEventDataSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Associate the reader and the tree 
   fReader.SetTree(tree);
}

void FullEventDataSelector::SlaveBegin(TTree *tree)
{
   // SlaveBegin() is a good place to create histograms. 
   // For PROOF, this is called for each worker.
   // The TTree* is there for backward compatibility; e.g. PROOF passes 0.

   fPosX = new TH1F("hPosX", "Position in X", 20, -5, 5);
   // enable bin errors:
   fPosX->Sumw2();
   // Add to output list (needed for PROOF)
   GetOutputList()->Add(fPosX);
}

Bool_t FullEventDataSelector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree to be 
   // processed. The entry argument specifies which entry in the currently
   // loaded tree is to be processed.
   // It can be passed to either EventSelector::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the TTree.
   //
   // This function should contain the "body" of the analysis: select relevant
   // tree entries, run algorithms on the tree entry and typically fill histograms.

   // *** 1. *** Tell the reader to load the data for this entry:
   fReader.SetEntry(entry);

   // *** 2. *** Do the actual analysis
   for (unsigned int iParticle = 0; iParticle < fParticlesPosX.GetSize(); ++iParticle) {
      if (fParticlesMomentum[iParticle] > 40.0)
         fPosX->Fill(fParticlesPosX[iParticle]);
   }

   return kTRUE;
}

void FullEventDataSelector::Terminate()
{
   // The Terminate() function is the last function to be called during the
   // analysis of a tree with a selector. It always runs on the client, it can
   // be used to present the results graphically or save the results to file.

   // Fit the histogram:
   fPosX->Fit("pol2");

   // and draw it:
   fPosX->Draw();
}
