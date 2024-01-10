#include "event.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

MyEventAction::MyEventAction(MyRunAction*)
{
    fEdep = 0.;
    fEdep1 = 0.;
 

}

MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{
    fEdep = 0.;
    fEdep1 = 0.;
}

void MyEventAction::EndOfEventAction(const G4Event*)
{
    //G4cout << "Energy deposition: " << fEdep*MeV << G4endl;
   // G4cout << "  Detector positions: " << fPosition.getX()*cm << " " << fPosition.getY()*cm << " " << fPosition.getZ()*cm << G4endl;

       G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
       G4AnalysisManager *man = G4AnalysisManager::Instance();
       if (fEdep > 0.0) {
          G4cout << "Energy deposition: " << fEdep*MeV << G4endl;
          man->FillNtupleDColumn(2, 0, fEdep*MeV);
         // man->AddNtupleRow(2);
          man->FillNtupleIColumn(0, 0, evt);
          man->FillNtupleDColumn(0, 1, fPosition.getX()*cm);
          man->FillNtupleDColumn(0, 2, fPosition.getY()*cm);
          man->FillNtupleDColumn(0, 3, fPosition.getZ()*cm);
       //man->FillNtupleDColumn(0, 4, time);
          man->AddNtupleRow(0);
          man->FillH1(0,fEdep*MeV);
       }
       if (fEdep1 > 0.0){
          man->FillNtupleDColumn(2, 1, fEdep1*MeV);
          man->AddNtupleRow(2);
       }
           // count thickness histogram
//       man->FillNtupleDColumn(0, thickness);
  //     man->AddNtupleRow(3);
}
