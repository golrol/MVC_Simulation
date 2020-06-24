#ifndef Model_h
#define Model_h

#include <vector>
#include "skeleton_View.h"
#include "Agent.h"
#include "Structure.h"
#include "Knight.h"
#include "Peasant.h"
#include "Thug.h"
#include "Validation.h"

class Model{
public:
    static shared_ptr<Model> getInstance();
    ~Model();
    Model(const Model&) = delete;
    Model(const Model&&) = delete;
    Model& operator=(const Structure&) = delete;
    Model& operator=(const Structure&&) = delete;
    
    void addAgent(const vector<string>& vec);
    vector<shared_ptr<Agent>>::const_iterator findAgentByName(const string& name) const;
    vector<shared_ptr<Structure>>::const_iterator findStructureByName(const string& name) const;
    
    void updateAgentDegAndSpeed(const vector<shared_ptr<Agent>>::const_iterator& agent, const pair<int,int>& degAndSpeed);
    
    void setViewPtr(shared_ptr<View> view_ptr);
    void go();
    
private:
    static shared_ptr<Model> inst;
    shared_ptr<View> view_ptr;
    
    vector<shared_ptr<Agent> > agentsVec;
    vector<shared_ptr<Structure> > structuresVec;
    int time;
    
    Model();
};

#endif /* Model_h */
