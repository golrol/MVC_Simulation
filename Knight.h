#ifndef Knight_h
#define Knight_h

#include "Agent.h"
#include "Structure.h"
#include <queue>

class Knight : public Agent{
public:
    Knight(const string& name, const Point& location);
    virtual ~Knight();
    /*no need for operator=, copy c'tor and move c'tor- using unly pointers*/
    
    /* inherited functions */
    void broadcast_current_State() const;
    /*when arriving to a Structure keep patroling to the next Structure in the queue*/
    void goToNextDestination();
    
    /* personal functions */
    /*start patroling to a given Structure*/
    void destination(const string& StructureName, const Point& StructureLocation);
    /*add a given Structure to the patrol queue*/
    void addToQueue(const shared_ptr<Structure>& structure);
    /*change the agent's direction*/
    void updateDeg(const double& deg);
    
private:
    queue<shared_ptr<Structure> > structures;
    
};

#endif /* Knight_h */
