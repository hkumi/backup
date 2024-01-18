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
    man->CreateNtupleDColumn("fX1");
    man->CreateNtupleDColumn("fY1");
    man->CreateNtupleDColumn("fZ1");
   // man->CreateNtupleDColumn("fT");
   

    man->FinishNtuple(0);

    // Set axis titles

    man->CreateNtuple("Scoring", "Scoring");
    man->CreateNtupleDColumn("Edep");
    man->FinishNtuple(1);

    man->CreateNtuple("Scoring_2", "Scoring_2");   
    man->CreateNtupleDColumn("Edep_2");
    man->CreateNtupleDColumn("fX2");
    man->CreateNtupleDColumn("fY2");
    man->CreateNtupleDColumn("fZ2");
    man->FinishNtuple(2);

    man->CreateNtuple("Scoring_3", "Scoring_3");
    man->CreateNtupleDColumn("Edep_3");
    man->CreateNtupleDColumn("fX3");
    man->CreateNtupleDColumn("fY3");
    man->CreateNtupleDColumn("fZ3");
    man->FinishNtuple(3);

    man->CreateNtuple("Scoring_4", "Scoring_4");
    man->CreateNtupleDColumn("Edep_4");
    man->CreateNtupleDColumn("fX4");
    man->CreateNtupleDColumn("fY4");
    man->CreateNtupleDColumn("fZ4");
    man->FinishNtuple(4);

    man->CreateNtuple("Scoring_5", "Scoring_5");
    man->CreateNtupleDColumn("Edep_5");
    man->CreateNtupleDColumn("fX5");
    man->CreateNtupleDColumn("fY5");
    man->CreateNtupleDColumn("fZ5");
    man->FinishNtuple(5);

    man->CreateNtuple("Scoring_6", "Scoring_6");
    man->CreateNtupleDColumn("Edep_6");
    man->CreateNtupleDColumn("fX6");
    man->CreateNtupleDColumn("fY6");
    man->CreateNtupleDColumn("fZ6");
    man->FinishNtuple(6);

    man->CreateNtuple("Scoring_7", "Scoring_7");
    man->CreateNtupleDColumn("Edep_7");
    man->CreateNtupleDColumn("fX7");
    man->CreateNtupleDColumn("fY7");
    man->CreateNtupleDColumn("fZ7");
    man->FinishNtuple(7);

    man->CreateNtuple("Scoring_8", "Scoring_8");
    man->CreateNtupleDColumn("Edep_8");
    man->CreateNtupleDColumn("fX8");
    man->CreateNtupleDColumn("fY8");
    man->CreateNtupleDColumn("fZ8");
    man->FinishNtuple(8);

    man->CreateNtuple("Scoring_9", "Scoring_9");
    man->CreateNtupleDColumn("Edep_9");
    man->CreateNtupleDColumn("fX9");
    man->CreateNtupleDColumn("fY9");
    man->CreateNtupleDColumn("fZ9");
    man->FinishNtuple(9);

    man->CreateNtuple("Scoring_10", "Scoring_10");
    man->CreateNtupleDColumn("Edep_10");
    man->CreateNtupleDColumn("fX10");
    man->CreateNtupleDColumn("fY10");
    man->CreateNtupleDColumn("fZ10");
    man->FinishNtuple(10);

    man->CreateNtuple("scoring1","scoring1");
    man->CreateNtupleDColumn("E_silicon");
    man->FinishNtuple(11);

    man->CreateH2("xy1 ","xy1", 1000, -2, 2, 1000, -2., 2.0);
    man->CreateH2("xy2 ","xy2", 1000, -2, 2, 1000, -2., 2.0);
    man->CreateH2("xy3 ","xy3", 1000, -2, 2, 1000, -2., 2.0);
    man->CreateH2("xy4 ","xy4", 1000, -2, 2, 1000, -2., 2.0);
    man->CreateH2("xy5 ","xy5", 1000, -2, 2, 1000, -2., 2.0);
    man->CreateH2("xy6 ","xy6", 1000, -2, 2, 1000, -2., 2.0);
    man->CreateH2("xy7 ","xy7", 1000, -2, 2, 1000, -2., 2.0);
    man->CreateH2("xy8 ","xy8", 1000, -2, 2, 1000, -2., 2.0);
    man->CreateH2("xy9 ","xy9", 1000, -2, 2, 1000, -2., 2.0);
    man->CreateH2("xy10 ","xy10", 1000, -2, 2, 1000, -2., 2.0);



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
