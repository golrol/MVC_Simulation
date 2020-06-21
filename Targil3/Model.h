#ifndef Model_h
#define Model_h

#include <vector>
#include "Agent.h"
#include "Structure.h"

class Model{
public:
    Model();
    ~Model();
    void addAgent();
    vector<shared_ptr<Agent>>::const_iterator findAgentByName(const string& name) const;
    vector<shared_ptr<Structure>>::const_iterator findStructureByName(const string& name) const;
    
private:
    vector<shared_ptr<Agent> > agentsVec;
    vector<shared_ptr<Structure> > structuresVec;
    int time;
    
};

#endif /* Model_h */
