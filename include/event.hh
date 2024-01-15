#ifndef EVENT_HH
#define EVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"

#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "run.hh"
#include "G4UserSteppingAction.hh"
#include "construction.hh"

class MyEventAction : public G4UserEventAction
{
public:
    MyEventAction(MyRunAction*);
    ~MyEventAction();

    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);

    void AddEdep(G4double edep) { fEdep += edep; }
    void AddEdep1(G4double edep1) { fEdep1 += edep1; }
    void AddEdep_2(G4double edep_2) { fEdep_2 += edep_2; }
    void AddEdep_3(G4double edep_3) { fEdep_3 += edep_3; }
    void AddEdep_4(G4double edep_4) { fEdep_4 += edep_4; }
    void AddEdep_5(G4double edep_5) { fEdep_5 += edep_5; }
    void SetPosition(G4ThreeVector p) { fPosition = p; }
    void Count_thickness(G4double current_thickness)  {thickness_count += current_thickness;}


private:
    G4double fEdep;
    G4ThreeVector fPosition;
    G4double fEdep1;
    G4double fEdep_2;
    G4double fEdep_3;
    G4double fEdep_4;
    G4double fEdep_5;
    G4double thickness_count;
    std::vector<G4int> theCollID;
};

#endif
