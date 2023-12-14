#include "generator.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
    fParticleGun = new G4ParticleGun(1);

    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName = "neutron";
    G4ParticleDefinition *particle = particleTable->FindParticle("neutron");
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticleEnergy(2*MeV);
    fParticleGun->SetParticlePosition(G4ThreeVector(0.*cm,0.*cm,-40.*cm));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.*cm,0.*cm,1.*cm));
    

}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
    G4ThreeVector gunDirection = G4ThreeVector(0, 0, 1);
    gunDirection += 0.2 * G4ThreeVector(G4UniformRand() - 0.5, G4UniformRand() - 0.5, 0);
    fParticleGun->SetParticleMomentumDirection(gunDirection);

    fParticleGun->GeneratePrimaryVertex(anEvent);

}
