#ifndef Thug_h
#define Thug_h

#include "Agent.h"

class Thug : public Agent{
public:
    Thug(const string& name, const Point& location);
    virtual ~Thug();
    /*no need for operator=, copy c'tor and move c'tor- using unly pointers*/
    
    /* inherited functions */
    void broadcast_current_State() const;
    /*stop when arriving to destination*/
    void goToNextDestination();
    
    /* personal functions */
    /*change the agent's direction and speed*/
    void updateDegAndSpeed(const pair<double, double>& degAndSpeed);
    
private:
    
};

#endif /* Thug_h */
