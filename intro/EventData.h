#include "TVector3.h"
#include <vector>

class Particle {
public:
   Particle() {memset(fTags, 0, sizeof(fTags)); }
   double fPosX,fPosY,fPosZ; // particle position nearest to interaction point
   double fMomentum; // particle momentum
   double fMomentumPhi; // particle direction (phi)
   double fMomentumEta; // particle direction (eta)
   Long64_t fTags[128]; // particle tags
};

class EventData {
public:
   std::vector<Particle> fParticles; // particles of the event
   int fEventSize; // size (in bytes) of the event

   void SetSize() {
      fEventSize = sizeof(EventData) + fParticles.size() * sizeof(Particle);
   }
   void Clear() {
      fParticles.clear();
   }
   void AddParticle(const Particle& p) { fParticles.push_back(p); }

   ClassDef(EventData,1); // Data for an event
};
