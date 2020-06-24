#ifndef Thug_h
#define Thug_h

#include "Agent.h"

class Thug : public Agent{
public:
    Thug(const string& name, const Point& location);
    virtual ~Thug();
    
    void update(){}
    void broadcast_current_State() const{}
    
    void updateDegAndSpeed(const pair<double, double>& degAndSpeed);
    
private:
    
};

#endif /* Thug_h */
