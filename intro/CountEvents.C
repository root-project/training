#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

void CountEvents()
{
   // Variables used to store the data
   Int_t totalSize = 0; // Sum of data size (in bytes) of all events

   // open the file
   TFile *f = TFile::Open("http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root");
   if (f == 0) {
      // if we cannot open the file, print an error message and return immediatly
      printf("Error: cannot open http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root!\n");
      return;
   }

   // Create a tree reader (of type Int_t) on the branch "fEventSize"
   TTreeReader myReader("EventTree", f);
   TTreeReaderValue<Int_t> eventSize(myReader, "fEventSize");

   // Loop over all entries of the TTree or TChain.
   while (myReader.Next()) {
      // Get the data from the current TTree entry by getting
      // the value from the connected reader (eventSize):
      totalSize += *eventSize;
   }

   Int_t sizeInMB = totalSize/1024/1024;
   printf("Total size of all events: %d MB\n", sizeInMB);
}

