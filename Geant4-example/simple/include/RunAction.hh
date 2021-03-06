#ifndef RunAction_h
#define RunAction_h 1

#include "ParamManager.hh"
#include "Analysis.hh"

#include "G4UserRunAction.hh"
#include "globals.hh"

class G4Run;

class RunAction : public G4UserRunAction
{
  public:
    RunAction(Analysis *analysismanager);
    virtual ~RunAction();

    virtual void BeginOfRunAction(const G4Run* aRun);
    virtual void   EndOfRunAction(const G4Run* aRun);

  private:
    ParamManager *paramMan;
    Analysis *anaMan;
};

#endif
