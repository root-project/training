// This class is derived from the ROOT class TSelector. 
// For more information on the TSelector framework see 
// $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The file for this selector can be found at
// http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root
// i.e run
//   root [0] f = TFile::Open("http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root");
//   root [1] EventTree->Process("CountEventSelector.C+")

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
// Root > T->Process("CountEventSelector.C")
// Root > T->Process("CountEventSelector.C","some options")
// Root > T->Process("CountEventSelector.C+")
//

#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TSelector.h"

const Int_t kMaxfParticles = 1293;

class CountEventSelector : public TSelector {
public :

   Int_t        fTotalDataSize;    // Sum of data size (in bytes) of all events

   // Variables used to store the data
   Int_t        fCurrentEventSize; // Size of the current event

   // Tree branches
   TBranch     *fEventSizeBranch;  // Pointer to the event.fEventsize branch
   
   CountEventSelector(TTree * = 0): fTotalDataSize(0), fCurrentEventSize(0),
                                    fEventSizeBranch(0) { }
   virtual ~CountEventSelector() { }

   virtual void    Init(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    Terminate();
   virtual Int_t   Version() const { return 2; }

   ClassDef(CountEventSelector,0);
};

void CountEventSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.

   // To use SetBranchAddress() with simple types (e.g. double, int)
   // instead of objects (e.g. std::vector&lt;Particle&gt;).
   tree->SetMakeClass(1);

   // Connect the branch "fEventSize" with the variable 
   // fCurrentEventSize that we want to contain the data.
   // While we are at it, ask the tree to save the branch 
   // in fEventSizeBranch
   tree->SetBranchAddress("fEventSize", &fCurrentEventSize, &fEventSizeBranch);
}

void CountEventSelector::SlaveBegin(TTree *tree)
{
   // SlaveBegin() is a good place to create histograms. 
   // For PROOF, this is called for each worker.
   // The TTree* is there for backward compatibility; e.g. PROOF passes 0.

}

Bool_t CountEventSelector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree to be 
   // processed. The entry argument specifies which entry in the currently
   // loaded tree is to be processed.
   // It can be passed to either EventSelector::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the TTree.
   //
   // This function should contain the "body" of the analysis: select relevant
   // tree entries, run algorithms on the tree entry and typically fill histograms.
   
   // Load the data for TTree entry number "entry" from branch 
   // fEventSize into the connected data member (fCurrentEventSize):
   fEventSizeBranch->GetEntry(entry);

   // We can still print some informations about the current event
   //printf("Size of Event %ld = %d Bytes\n", entry, fCurrentEventSize);

   // compute the total size of all events
   fTotalDataSize += fCurrentEventSize;
   return kTRUE;
}

void CountEventSelector::Terminate()
{
   // The Terminate() function is the last function to be called during the
   // analysis of a tree with a selector. It always runs on the client, it can
   // be used to present the results graphically or save the results to file.

   int sizeInMB = fTotalDataSize/1024/1024;
   printf("Total size of all events: %d MB\n", sizeInMB);
}
