#ifndef Model_h
#define Model_h

#include <vector>
#include "Agent.h"
#include "Structure.h"

class Model{
public:
    static shared_ptr<Model> getInstance();
    ~Model();
    Model(const Model&) = delete;
    Model(const Model&&) = delete;
    Model& operator=(const Structure&) = delete;
    Model& operator=(const Structure&&) = delete;
    
    void addAgent();
    vector<shared_ptr<Agent>>::const_iterator findAgentByName(const string& name) const;
    vector<shared_ptr<Structure>>::const_iterator findStructureByName(const string& name) const;
    
private:
    static shared_ptr<Model> inst;
    
    vector<shared_ptr<Agent> > agentsVec;
    vector<shared_ptr<Structure> > structuresVec;
    int time;
    
    Model();
};

#endif /* Model_h */
