#ifndef Model_h
#define Model_h

#include <vector>
#include "Agent.h"

class Model{
public:
    Model();
    ~Model();
    
private:
    vector<Agent> agentsVec;
    
};

#endif /* Model_h */
