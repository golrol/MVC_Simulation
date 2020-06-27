#ifndef Knight_h
#define Knight_h

#include "Agent.h"
#include "Structure.h"
#include <queue>

class Knight : public Agent{
public:
    Knight(const string& name, const Point& location);
    virtual ~Knight(){};
    
    void broadcast_current_State() const;
    void position(const Point& location);
    void destination(const string& StructureName, const Point& StructureLocation);
    void addToQueue(const shared_ptr<Structure>& structure);
    void goToNextDestination();
    
    
    void updateDeg(const double& deg);
    
private:
    queue<shared_ptr<Structure> > structures;
    
};

#endif /* Knight_h */
