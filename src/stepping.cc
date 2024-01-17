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

     G4LogicalVolume *fScoringVolume_1 = detectorConstruction->GetScoringVolume();
     G4LogicalVolume *fScoringVolume_2 = detectorConstruction->GetScoringVolume_2();
     G4LogicalVolume *fScoringVolume_3 = detectorConstruction->GetScoringVolume_3();
     G4LogicalVolume *fScoringVolume_4 = detectorConstruction->GetScoringVolume_4();
     G4LogicalVolume *fScoringVolume_5 = detectorConstruction->GetScoringVolume_5();
     G4LogicalVolume *fScoringVolume_6 = detectorConstruction->GetScoringVolume_6();
     G4LogicalVolume *fScoringVolume_7 = detectorConstruction->GetScoringVolume_7();
     G4LogicalVolume *fScoringVolume_8 = detectorConstruction->GetScoringVolume_8();
     G4LogicalVolume *fScoringVolume_9 = detectorConstruction->GetScoringVolume_9();
     G4LogicalVolume *fScoringVolume_10 = detectorConstruction->GetScoringVolume_10();

     G4LogicalVolume *fScoringVolume2 = detectorConstruction->GetScoringVolume1();

     //G4cout << "\n thickness of this material "<< detectorConstruction->GetMaterialThickness() << G4endl;
     G4double current_thickness = detectorConstruction->GetMaterialThickness();       
     
     //G4Track* theTrack = step->GetTrack();
     //G4int stepNumber = theTrack->GetCurrentStepNumber();
     //G4cout << "the step number:" << stepNumber; 
     G4double edep = step->GetTotalEnergyDeposit();
     G4double edep1 = step->GetTotalEnergyDeposit();
     G4double edep_2 = step->GetTotalEnergyDeposit();
     G4double edep_3 = step->GetTotalEnergyDeposit();
     G4double edep_4 = step->GetTotalEnergyDeposit();
     G4double edep_5 = step->GetTotalEnergyDeposit();
     G4double edep_6 = step->GetTotalEnergyDeposit();
     G4double edep_7 = step->GetTotalEnergyDeposit();
     G4double edep_8 = step->GetTotalEnergyDeposit();
     G4double edep_9 = step->GetTotalEnergyDeposit();
     G4double edep_10 = step->GetTotalEnergyDeposit();

     //G4cout << current_thickness << G4endl;
    // fEventAction->Count_thickness(current_thickness);

    	// If it's the first step in the volume, save the position. 
     if (step->IsFirstStepInVolume()) {
        fEventAction->SetPosition(step->GetPreStepPoint()->GetPosition());
     }

     if (volume == fScoringVolume_1){
        fEventAction->AddEdep(edep);

     }
     if (volume == fScoringVolume_2){
        fEventAction->AddEdep_2(edep_2);

     }
     if (volume == fScoringVolume_3){
        fEventAction->AddEdep_3(edep_3);

     }
     if (volume == fScoringVolume_4){
        fEventAction->AddEdep_4(edep_4);

     }
     if (volume == fScoringVolume_5){
        fEventAction->AddEdep_5(edep_5);

     }
     if (volume == fScoringVolume_6){
        fEventAction->AddEdep_6(edep_6);

     }
     if (volume == fScoringVolume_7){
        fEventAction->AddEdep_7(edep_7);

     }
     if (volume == fScoringVolume_8){
        fEventAction->AddEdep_8(edep_8);

     }
     if (volume == fScoringVolume_9){
        fEventAction->AddEdep_9(edep_9);

     }
     if (volume == fScoringVolume_10){
        fEventAction->AddEdep_10(edep_10);

     }


     if (volume == fScoringVolume2){
        fEventAction->AddEdep1(edep1);
     }
}
