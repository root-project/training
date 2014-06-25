// Creates the ROOT file for the introductory tutorials at
// http://root.cern.ch/drupal/
//
// Axel, 2010-07-08

// Prefer compiled:
#include "EventData.h+"

void createTree(ULong64_t numEvents = 200) {
   TFile* f = new TFile("eventdata.root", "RECREATE");
   TTree* tree = new TTree("EventTree", "Tutorial tree");
   tree->SetAutoSave(0); // to not confuse people with "EventTree;2" keys

   EventData* event = new EventData();
   tree->Branch("event", &event);

   Particle p;

   for (ULong64_t i = 0; i < numEvents; ++i) {
      event->Clear();
      int nParticles = 10 * gRandom->Exp(10.);
      if (i == 0) nParticles = 1200; // to have a large value for TSelector's array size
      for (int ip = 0; ip < nParticles; ++ip) {
         do {
            p.fPosX = gRandom->Gaus(gRandom->PoissonD(0.1), 1.)
               + gRandom->BreitWigner(0.1, 0.1);;
         } while (fabs(p.fPosX) > 10.);
         p.fPosY = gRandom->Gaus(gRandom->PoissonD(0.01), .7);
         p.fPosZ = gRandom->Gaus(gRandom->PoissonD(10), 19.);

         p.fMomentum = gRandom->Exp(12);
         p.fMomentumPhi = gRandom->Uniform(2*TMath::Pi());
         do {
            p.fMomentumEta = gRandom->BreitWigner(0.01, 10.);
         } while (fabs(p.fMomentumEta) > 12.);

         event->AddParticle(p);
      }
      event->SetSize();

      tree->Fill();

      if (i % (numEvents/50) == 0) {
         printf("*");
         fflush(stdout);
      }
   }
   printf("\n");
   tree->Write();
   delete f;
}
