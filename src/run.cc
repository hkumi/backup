#include "run.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
MyRunAction::MyRunAction()
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man->SetNtupleMerging(true);
    man->SetVerboseLevel( 1 );
    man->CreateNtuple("Photons", "Photons");
    man->CreateNtupleDColumn("TCount");
   // man->CreateNtupleDColumn("fT");

    man->FinishNtuple(0);

    // Set axis titles

    man->CreateNtuple("Scoring", "Scoring");
    man->CreateNtupleDColumn("Edep");
    man->CreateNtupleDColumn("Edep_2");
    man->CreateNtupleDColumn("Edep_3");
    man->CreateNtupleDColumn("Edep_4");
    man->CreateNtupleDColumn("Edep_5");
    man->FinishNtuple(1);
    man->CreateNtuple("scoring1","scoring1");
    man->CreateNtupleDColumn("E_silicon");
    man->FinishNtuple(2);


}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run* run)
{

     
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    G4int runID = run->GetRunID();

    std::stringstream strRunID;
    strRunID << runID;

    man->OpenFile("output"+strRunID.str()+".root");
}
void MyRunAction::EndOfRunAction(const G4Run*)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    man->Write();
    man->CloseFile();
}
