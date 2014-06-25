#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderArray.h"

void AnalyzeTree()
{
   // Variables used to store the data
   TH1F *hPosX;  // X position of the particles

   // open the file
   TFile *f = TFile::Open("http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root");
   if (f == 0) {
      // if we cannot open the file, print an error message and return immediatly
      printf("Error: cannot open http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root!\n");
      return;
   }

   // Create tyhe tree reader and its data containers
   TTreeReader myReader("EventTree", f);
   // The branch "fPosX" contains doubles; access them as particlesPosX.
   TTreeReaderArray<Double_t> particlesPosX(myReader, "fParticles.fPosX");
   // The branch "fMomentum" contains doubles, too; access those as particlesMomentum.
   TTreeReaderArray<Double_t> particlesMomentum(myReader, "fParticles.fMomentum");

   // create the TH1F histogram
   hPosX = new TH1F("hPosX", "Position in X", 20, -5, 5);
   // enable bin errors:
   hPosX->Sumw2();

   // Loop over all entries of the TTree or TChain.
   while (myReader.Next()) {
      // Do the analysis...
      for (int iParticle = 0; iParticle < particlesPosX.GetSize(); ++iParticle) {
         if (particlesMomentum[iParticle] > 40.0)
            hPosX->Fill(particlesPosX[iParticle]);
      }
   }

   // Fit the histogram:
   hPosX->Fit("pol2");
   // and draw it:
   hPosX->Draw();
}

