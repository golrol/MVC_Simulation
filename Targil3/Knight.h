#ifndef Knight_h
#define Knight_h

#include "Agent.h"

class Knight : public Agent{
public:
    Knight(const string& name, const Point& location);
    virtual ~Knight(){};
    
    void update(){}
    void broadcast_current_State() const;
    
    
    void updateDeg(const double& deg);
    
private:
    
};

#endif /* Knight_h */
