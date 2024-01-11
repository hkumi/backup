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

     //G4cout << "\n thickness of this material "<< detectorConstruction->GetMaterialThickness() << G4endl;
     G4double current_thickness = detectorConstruction->GetMaterialThickness();       


     G4double edep = step->GetTotalEnergyDeposit();
     G4double edep1 = step->GetTotalEnergyDeposit();
     //G4cout << current_thickness << G4endl;
    // fEventAction->Count_thickness(current_thickness);

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
