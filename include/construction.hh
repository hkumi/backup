#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4GenericMessenger.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"

//#include "detector.hh"
class G4LogicalVolume;
class G4Material;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:

    DetectorConstruction();
   ~DetectorConstruction();

    G4LogicalVolume *GetScoringVolume() const {return fScoringVolume_1;}
    G4LogicalVolume *GetScoringVolume_2() const {return fScoringVolume_2;}
    G4LogicalVolume *GetScoringVolume_3() const {return fScoringVolume_3;}
    G4LogicalVolume *GetScoringVolume_4() const {return fScoringVolume_4;}
    G4LogicalVolume *GetScoringVolume_5() const {return fScoringVolume_5;}
    G4LogicalVolume *GetScoringVolume1() const {return fScoringVolume2;}
    G4double GetMaterialThickness()  const{return fhThick;}  
    virtual G4VPhysicalVolume* Construct();
    void ConstructOPPAC_1(G4double Pos_PPAC_1);
    void ConstructOPPAC_2(G4double Pos_PPAC_2);
    void ConstructOPPAC_3(G4double Pos_PPAC_3);
    void ConstructOPPAC_4(G4double Pos_PPAC_4);
    void ConstructOPPAC_5(G4double Pos_PPAC_5);
    void ConstructSilicon_detector(G4double Pos_Silicon);
    void CreateAndPlaceShield(G4double thickness, G4double size, G4double position, G4LogicalVolume* motherVolume) ;
  
private:
     G4Box  *sBox,*FoShield, *TShield,*fShield,*sShield,*sScore,*solidDetector;
     G4Box *fShield1;
     G4Tubs *solidScintillator;
     G4VPhysicalVolume *ffPShield, *FoPShield,*fPShield,*TPShield;
     G4VPhysicalVolume *fPShield1;
     G4LogicalVolume   *fLBox,*ffLShield, *FoLShield,*fLShield,*TLShield,*fLScore, *logicScintillator;
     G4LogicalVolume   *fLShield1;
     G4LogicalVolume*   logicDetector;
     G4LogicalVolume   *fScoringVolume_1,*fScoringVolume_2,*fScoringVolume_3,*fScoringVolume_4;
     G4LogicalVolume   *fScoringVolume2,*fScoringVolume_5;
     G4double       mat_thickness;
     
     G4VPhysicalVolume *fPBox, *physScintillator;

     G4double           ShThick,ThThick,FohThick;
     G4double            fhThick,fhThick1;
         
     G4double           fBoxSize;
     G4Material*        fMaterial;     
     G4Material *Air, *Aerogel,  *polyethylene, *NaI, *CF4 ;
     G4Material *siliconMaterial;
     G4Element  *Na, *I, *C,*N,*O,*F;     
         
     void DefineMaterials();
     virtual void ConstructSDandField();
     G4GenericMessenger *fMessenger;
     G4bool isPPAC, isScintillator;   
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


#endif

