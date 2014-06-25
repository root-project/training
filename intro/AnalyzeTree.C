#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TH1F.h"

const Int_t kMaxfParticles = 1293;

void AnalyzeTree()
{
   // Variables used to store the data
   Int_t     totalSize = 0;         // Sum of data size (in bytes) of all events
   Int_t     eventSize = 0;         // Size of the current event
   TH1F     *hPosX;                 // X position of the particles

   // List of branches
   TBranch  *nParticlesBranch;
   TBranch  *particlesPosXBranch;
   TBranch  *particlesMomentumBranch;

   // Declaration of leaf types
   Int_t     nParticles;
   Double_t  particlesPosX[kMaxfParticles];
   Double_t  particlesMomentum[kMaxfParticles];

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

   // Connect the branches with their member variables.
   tree->SetBranchAddress("fParticles", &nParticles, &nParticlesBranch);
   tree->SetBranchAddress("fParticles.fPosX", particlesPosX, &particlesPosXBranch);
   tree->SetBranchAddress("fParticles.fMomentum", particlesMomentum, &particlesMomentumBranch);

   // create the TH1F histogram
   hPosX = new TH1F("hPosX", "Position in X", 20, -5, 5);
   // enable bin errors:
   hPosX->Sumw2();

   Long64_t nentries = tree->GetEntries();
   for (Long64_t i=0;i<nentries;i++) {
      // We only need the number of particles...
      nParticlesBranch->GetEntry(i);
      // ... and their position in X...
      particlesPosXBranch->GetEntry(i);
      // ... and their momentum
      particlesMomentumBranch->GetEntry(i);
      // *** 2. *** Do the actual analysis
      for (int iParticle = 0; iParticle < nParticles; ++iParticle) {
         if (particlesMomentum[iParticle] > 40.0)
            hPosX->Fill(particlesPosX[iParticle]);
      }
   }
   // Fit the histogram:
   hPosX->Fit("pol2");
   // and draw it:
   hPosX->Draw();
}

