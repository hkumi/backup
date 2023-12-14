#include "construction.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
{

    fMessenger = new G4GenericMessenger(this, "/detector/", "myDetector Construction");
    fMessenger->DeclareProperty("cherenkov", isCherenkov, "Construct Cherenkov detector");
    fMessenger->DeclareProperty("scintillator", isScintillator, "Construct Scintillator");
    isCherenkov = false;
    isScintillator = true;
    DefineMaterials();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::DefineMaterials()
{

  G4NistManager *nist = G4NistManager::Instance();
  G4int ncomponents, natoms;
  G4double massfraction;

  G4double Vdens = 1.e-25*g/cm3;
  G4double Vpres = 1.e-19*pascal;
  G4double Vtemp = 0.1*kelvin;
  
  G4double a, z;
  G4Element* C = nist->FindOrBuildElement("C");

  // vacuum
  G4Material *Vacc = new G4Material("Galactic", z=1, a=1.01*g/mole, Vdens, kStateGas, Vtemp, Vpres);

  // pressurized water
  G4Element* H  = new G4Element("TS_H_of_Water" ,"H" , 1., 1.0079*g/mole);
  G4Element* O  = new G4Element("Oxygen"        ,"O" , 8., 16.00*g/mole);
  G4Material* H2O = 
  new G4Material("Water_ts", 1.000*g/cm3, ncomponents=2,
                         kStateLiquid, 593*kelvin, 150*bar);
  H2O->AddElement(H, natoms=2);
  H2O->AddElement(O, natoms=1);
  H2O->GetIonisation()->SetMeanExcitationEnergy(78.0*eV);


  // air
  G4Element* N = new G4Element("Nitrogen", "N", 7., 14.01*g/mole);
  Air = new G4Material("air", 1.290*mg/cm3, ncomponents=2, kStateGas, 293*kelvin, 1*atmosphere);
  Air->AddElement(N, massfraction=70.*perCent);
  Air->AddElement(O, massfraction=30.*perCent);

  // polyethilene
  G4Element* Hpe = new G4Element("TS_H_of_Polyethylene", "H", 1, 1.0079*g/mole);
  G4Element* Cpe = new G4Element("Carbon", "C", 6, 12.01*g/mole);
  polyethylene = new G4Material("polyethylene", 0.93*g/cm3, ncomponents=2, kStateSolid, 293*kelvin, 1*atmosphere);
  polyethylene->AddElement(Hpe, natoms=4);
  polyethylene->AddElement(Cpe, natoms=2);


 //...................................creating the optical detector material ...................................

  G4Material *SiO2 = new G4Material("SiO2", 2.201*g/cm3, 2);
  Aerogel = new G4Material("Aerogel", 0.200*g/cm3, 3);
  SiO2->AddElement(nist->FindOrBuildElement("Si"), 1);
  SiO2->AddElement(nist->FindOrBuildElement("O"), 2);
  Aerogel->AddMaterial(SiO2, 62.5*perCent);
  Aerogel->AddMaterial(H2O, 37.4*perCent);
  Aerogel->AddElement(C, 0.1*perCent);

  G4double energy[2] = {1.239841939*eV/0.9, 1.239841939*eV/0.2};
  G4double rindexAerogel[2] = {1.1, 1.1};
  G4double rindexWorld[2] = {1.0, 1.0};
  G4MaterialPropertiesTable *mptAerogel = new G4MaterialPropertiesTable();
  mptAerogel->AddProperty("RINDEX", energy, rindexAerogel, 2);
  Aerogel->SetMaterialPropertiesTable(mptAerogel);
  G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
  mptWorld->AddProperty("RINDEX", energy, rindexWorld, 2);
  Air->SetMaterialPropertiesTable(mptWorld);

  //............................End of optical detector material........................

//...............creating the materials for the scintillator..............................
  Na = nist->FindOrBuildElement("Na");
  I = nist->FindOrBuildElement("I");
  NaI = new G4Material("NaI", 3.67*g/cm3, 2);
  NaI->AddElement(Na, 1);
  NaI->AddElement(I, 1);


//....................End of scintillator material........................................
}


G4VPhysicalVolume *DetectorConstruction::Construct()
{

  fBoxSize = 1*m;


  sBox = new G4Box("world",                             //its name
                   fBoxSize/2,fBoxSize/2,fBoxSize/2);   //its dimensions

  fLBox = new G4LogicalVolume(sBox,                     //its shape
                             Air,                      //its material
                             "World");                  //its name

  fPBox = new G4PVPlacement(0,                          //no rotation
                            G4ThreeVector(),            //at (0,0,0)
                            fLBox,                      //its logical volume
                            "World",                    //its name
                            0,                          //its mother  volume
                            false,                      //no boolean operation
                            0);                         //copy number

  // shielding
  ShThick = 0.01*m;
  G4double ShSize = 1*m;
  G4double ShPos = 0.05*m;

  sShield = new G4Box("shield",
                    ShSize/2,ShSize/2,ShThick/2);

  fLShield = new G4LogicalVolume(sShield,
                                      polyethylene ,
                                      "Shield");

  fPShield = new G4PVPlacement(0,
                              G4ThreeVector(0.*cm,0.*cm,ShPos),
                              fLShield,
                              "Shield",
                              fLBox,
                              false,
                              0);
  
  if(isCherenkov)
    ConstructCherenkov();
  if(isScintillator)
    ConstructScintillator();


  return fPBox;
}

//...ooooooooooooooooo..................................oooooooooooooooooooo......
//...oooooooooooooooo...................................oooooooooooooooooooo.....
void DetectorConstruction::ConstructScintillator()
{
    solidScintillator = new G4Tubs("solidScintillator", 10*cm, 20*cm, 30*cm,0*deg,360*deg);

    logicScintillator = new G4LogicalVolume(solidScintillator, NaI, "logicalScintillator");
    fScoringVolume =  logicScintillator;


    physScintillator = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicScintillator, "physScintillator", fLBox, false, 0, true);

/*
    G4LogicalSkinSurface *skin = new G4LogicalSkinSurface("skin", logicWorld, mirrorSurface);

    fScoringVolume = logicScintillator;

    solidDetector = new G4Box("solidDetector", 1.*cm, 5.*cm, 6*cm);

    logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetector");

    for(G4int i = 0; i < 6; i++)
    {
        for(G4int j = 0; j < 16; j++)
        {
            G4Rotate3D rotZ(j*22.5*deg, G4ThreeVector(0,0,1));
            G4Translate3D transXScint(G4ThreeVector(5./tan(22.5/2*deg)*cm+5.*cm, 0.*cm, -40.*cm + i*15*cm));
            G4Transform3D transformScint = (rotZ)*(transXScint);

            G4Translate3D transXDet(G4ThreeVector(5./tan(22.5/2*deg)*cm+5.*cm+6.*cm, 0.*cm, -40.*cm + i*15*cm));
            G4Transform3D transformDet = (rotZ)*(transXDet);

            physScintillator = new G4PVPlacement(transformScint, logicScintillator, "physScintillator", logicWorld, false, 0, true);

            physDetector = new G4PVPlacement(transformDet, logicDetector, "physDetector", logicWorld, false, 0, true);
        }
    }*/
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void DetectorConstruction::ConstructCherenkov()

{

// scores
  G4double ScThick = 0.01*m;

  auto sScore = new G4Box("sScore",
                            0.4*m,0.4*m,ScThick);

  auto fLScore = new G4LogicalVolume(sScore,
                                      Aerogel,
                                      "fLScore");

  auto fPScore_r = new G4PVPlacement(0,
                                    G4ThreeVector(0.*m,0.*m,0.25*m),
                                    fLScore,
                                    "fPScore_r",
                                    fLBox,
                                    false,
                                    0,true);
  fScoringVolume = fLScore;

 auto solidDetector = new G4Box("solidDetector",0.005*m,0.005*m,0.01*m);
  auto logicDetector = new G4LogicalVolume(solidDetector, Air, "logicDetector");
  for (G4int i = 0; i < 100; i++)
  {   
      for (G4int j=0;j<100;j++)
      {
            G4VPhysicalVolume *physDetector = new G4PVPlacement(0,G4ThreeVector(-0.5*m +(i+0.5)*m/100, -0.5*m+(j+0.5)*m/100, 0.49*m), logicDetector, "physDetector", fLBox, false, j+i*100, true);

      }


  }  



}


void DetectorConstruction::ConstructSDandField()
{

     MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");

     if(logicDetector != NULL)
       logicDetector->SetSensitiveDetector(sensDet);
}
