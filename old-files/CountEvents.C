#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"

void CountEvents()
{
   // Variables used to store the data
   Int_t     totalSize = 0;        // Sum of data size (in bytes) of all events
   Int_t     eventSize = 0;        // Size of the current event
   TBranch  *eventSizeBranch = 0;  // Pointer to the event.fEventsize branch

   // open the file
   TFile *f = TFile::Open("http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root");
   if (f == 0) {
      // if we cannot open the file, print an error message and return immediatly
      printf("Error: cannot open http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root!\n");
      return;
   }
   // get a pointer to the tree
   TTree *tree = (TTree *)f->Get("EventTree");
   // To use SetBranchAddress() with simple types (e.g. double, int)
   // instead of objects (e.g. std::vector<Particle>).
   tree->SetMakeClass(1);

   // Connect the branch "fEventSize" with the variable
   // eventSize that we want to contain the data.
   // While we are at it, ask the tree to save the branch
   // in eventSizeBranch
   tree->SetBranchAddress("fEventSize", &eventSize, &eventSizeBranch);

   // First, get the total number of entries
   Long64_t nentries = tree->GetEntries();
   // then loop over all of them
   for (Long64_t i=0;i<nentries;i++) {
      // Load the data for TTree entry number "i" from branch
      // fEventSize into the connected variable (eventSize):
      eventSizeBranch->GetEntry(i);
      totalSize += eventSize;
   }
   Int_t sizeInMB = totalSize/1024/1024;
   printf("Total size of all events: %d MB\n", sizeInMB);
}

