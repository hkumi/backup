#ifndef EVENT_HH
#define EVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"

#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "run.hh"

class MyEventAction : public G4UserEventAction
{
public:
    MyEventAction(MyRunAction*);
    ~MyEventAction();

    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);

    void AddEdep(G4double edep) { fEdep += edep; }
    void AddEdep1(G4double edep1) { fEdep1 += edep1; }
    void SetPosition(G4ThreeVector p) { fPosition = p; }
 
 
private:
    G4double fEdep;
    G4ThreeVector fPosition;
    G4double fEdep1;
};

#endif
