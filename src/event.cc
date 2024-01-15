#include "event.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

MyEventAction::MyEventAction(MyRunAction*)
{
    fEdep = 0.;
    fEdep1 = 0.;
    fEdep_2 = 0.;
    fEdep_3 = 0.;
    fEdep_4 = 0.;
    fEdep_5 = 0.;
    thickness_count = 0.;
 

}

MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{
    fEdep = 0.;
    fEdep1 = 0.;
    fEdep_2 = 0.;
    fEdep_3 = 0.;
    fEdep_4 = 0.;
    fEdep_5 = 0.;
    thickness_count = 0.;
}

void MyEventAction::EndOfEventAction(const G4Event*)
{
    //G4cout << "Energy deposition: " << fEdep*MeV << G4endl;
   // G4cout << "  Detector positions: " << fPosition.getX()*cm << " " << fPosition.getY()*cm << " " << fPosition.getZ()*cm << G4endl;
       G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
       G4int numberOfEvents = G4RunManager::GetRunManager()->GetCurrentRun()->GetNumberOfEventToBeProcessed();
       G4int count = 0;

       G4AnalysisManager *man = G4AnalysisManager::Instance();

       if (fEdep > 0.0) {
          G4cout << "Number of events: " << evt << G4endl;
          G4cout << "Energy deposition: " << fEdep*MeV << G4endl;
          man->FillNtupleDColumn(1, 0, fEdep*MeV);
          //man->FillNtupleDColumn(1,1,fEdep_2*MeV);
          //man->AddNtupleRow(1);
          man->FillNtupleDColumn(0, 0, evt);
          //man->FillNtupleDColumn(0, 1, fPosition.getX()*cm);
          //man->FillNtupleDColumn(0, 2, fPosition.getY()*cm);
          //man->FillNtupleDColumn(0, 3, fPosition.getZ()*cm);
       //man->FillNtupleDColumn(0, 4, time);
          man->AddNtupleRow(0);
          theCollID.push_back(evt);
          G4int Ncol = theCollID.size();
          G4cout << "total number events for this thickness:"<< Ncol << G4endl;

       }
       if (fEdep_2 > 0.0){
          man->FillNtupleDColumn(1,1,fEdep_2*MeV);

       }
       if (fEdep_3 > 0.0){
          man->FillNtupleDColumn(1,2,fEdep_3*MeV);

       }
       if (fEdep_4 > 0.0){
          man->FillNtupleDColumn(1,3,fEdep_4*MeV);

       }
       if (fEdep_5 > 0.0){
          man->FillNtupleDColumn(1,4,fEdep_5*MeV);
          man->AddNtupleRow(1);

       }


       if (fEdep1 > 0.0){
          man->FillNtupleDColumn(2, 0, fEdep1*MeV);
          man->AddNtupleRow(2);
       }
           // count thickness histogram
//       man->FillNtupleDColumn(0, thickness);
  //     man->AddNtupleRow(3);
}
