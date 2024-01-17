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
    man->CreateNtupleDColumn("fX");
    man->CreateNtupleDColumn("fY");
    man->CreateNtupleDColumn("fZ");
   // man->CreateNtupleDColumn("fT");
   

    man->FinishNtuple(0);

    // Set axis titles

    man->CreateNtuple("Scoring", "Scoring");
    man->CreateNtupleDColumn("Edep");
    man->FinishNtuple(1);

    man->CreateNtuple("Scoring_2", "Scoring_2");   
    man->CreateNtupleDColumn("Edep_2");
    man->FinishNtuple(2);

    man->CreateNtuple("Scoring_3", "Scoring_3");
    man->CreateNtupleDColumn("Edep_3");
    man->FinishNtuple(3);

    man->CreateNtuple("Scoring_4", "Scoring_4");
    man->CreateNtupleDColumn("Edep_4");
    man->FinishNtuple(4);

    man->CreateNtuple("Scoring_5", "Scoring_5");
    man->CreateNtupleDColumn("Edep_5");
    man->FinishNtuple(5);

    man->CreateNtuple("Scoring_6", "Scoring_6");
    man->CreateNtupleDColumn("Edep_6");
    man->FinishNtuple(6);

    man->CreateNtuple("Scoring_7", "Scoring_7");
    man->CreateNtupleDColumn("Edep_7");
    man->FinishNtuple(7);

    man->CreateNtuple("Scoring_8", "Scoring_8");
    man->CreateNtupleDColumn("Edep_8");
    man->FinishNtuple(8);

    man->CreateNtuple("Scoring_9", "Scoring_9");
    man->CreateNtupleDColumn("Edep_9");
    man->FinishNtuple(9);

    man->CreateNtuple("Scoring_10", "Scoring_10");
    man->CreateNtupleDColumn("Edep_10");
    man->FinishNtuple(10);

    man->CreateNtuple("scoring1","scoring1");
    man->CreateNtupleDColumn("E_silicon");
    man->FinishNtuple(11);

    man->CreateH2("xy ","xy", 100, -400, 100, 100, -700., 100.0);



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
