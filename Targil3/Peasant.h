#ifndef Peasant_h
#define Peasant_h

#include "Agent.h"

class Peasant : public Agent{
public:
    Peasant(const string& name, const Point& location);
    virtual ~Peasant(){};
    
private:
    int inventory;
    Point source;
    //Point destination;
};

#endif /* Peasant_h */
