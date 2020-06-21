#ifndef Model_h
#define Model_h

#include <vector>
#include "Agent.h"
#include "Structure.h"

class Model{
public:
    Model();
    ~Model();
    
private:
    vector<Agent> agentsVec;
    vector<Structure> structuresVec;
    int time;
    
};

#endif /* Model_h */
