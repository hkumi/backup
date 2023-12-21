#include "stepping.hh"

MySteppingAction::MySteppingAction(MyEventAction *eventAction)
{
    fEventAction = eventAction;
}

MySteppingAction::~MySteppingAction()
{}

void MySteppingAction::UserSteppingAction(const G4Step *step)
{  
//    if (step->GetTrack()->GetDefinition()->GetParticleName() == "proton") {    
    G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

    const DetectorConstruction *detectorConstruction = static_cast<const DetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());

    G4LogicalVolume *fScoringVolume = detectorConstruction->GetScoringVolume();
    //collect energy deposition. 
    if(volume != fScoringVolume)
       return; 
    	// If it's the first step in the volume, save the position. 
    if (step->IsFirstStepInVolume()) {
        fEventAction->SetPosition(step->GetPreStepPoint()->GetPosition());
    }
    G4double edep = step->GetTotalEnergyDeposit();
    fEventAction->AddEdep(edep);
  // }
}
