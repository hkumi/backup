#include <iostream>

#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "QGSP_BERT_HP.hh"
#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "Randomize.hh"
#include "G4GeneralParticleSource.hh"

#include "construction.hh"
#include "physics.hh"
#include "FTFP_BERT.hh"
#include "action.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4OpticalPhysics.hh"

int main(int argc, char** argv)
{
    G4RunManager *runManager = new G4RunManager();
    runManager->SetUserInitialization(new DetectorConstruction());
     // Physics list
    runManager->SetUserInitialization(new PhysicsList());   
//      runManager->SetUserInitialization(new QGSP_BERT_HP());

    runManager->SetUserInitialization(new MyActionInitialization());
    //runManager->Initialize();
    G4UIExecutive *ui = 0;
    if (argc ==1)
    {
       ui = new G4UIExecutive(argc,argv);
    }
    G4VisManager *visManager = new G4VisExecutive();
    G4UImanager *UImanager =  G4UImanager::GetUIpointer();

    visManager->Initialize();
    if (ui)
    {
       //UImanager->ApplyCommand("/control/execute vis.mac");
       UImanager->ApplyCommand("/control/execute run.mac");
     
      
       ui->SessionStart();
    }
    else
    {
       G4String command = "/control/execute";
       G4String fileName = argv[1];
       UImanager->ApplyCommand(command + fileName);
    }
    //job termination
    delete visManager;
    delete runManager;

}
