#include "stepping.hh"

MySteppingAction::MySteppingAction(MyEventAction *eventAction)
{
    fEventAction = eventAction;
}

MySteppingAction::~MySteppingAction()
{}

void MySteppingAction::UserSteppingAction(const G4Step *step)
{
//  if (step->GetTrack()->GetDefinition()->GetParticleName() == "proton") {    
     const DetectorConstruction *detectorConstruction = static_cast<const DetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
     G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

     G4LogicalVolume *fScoringVolume = detectorConstruction->GetScoringVolume();
     G4LogicalVolume *fScoringVolume2 = detectorConstruction->GetScoringVolume1();

     G4double edep = step->GetTotalEnergyDeposit();
     G4double edep1 = step->GetTotalEnergyDeposit();

    	// If it's the first step in the volume, save the position. 
     if (step->IsFirstStepInVolume()) {
        fEventAction->SetPosition(step->GetPreStepPoint()->GetPosition());
     }

     if (volume == fScoringVolume){
        fEventAction->AddEdep(edep);
     }

     if (volume == fScoringVolume2){
        fEventAction->AddEdep1(edep1);
     }
}
