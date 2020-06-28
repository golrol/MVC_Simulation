#ifndef Peasant_h
#define Peasant_h

#include "Agent.h"

class Peasant : public Agent{
public:
    Peasant(const string& name, const Point& location);
    virtual ~Peasant(){};
    
//    void updateDeg(const double &deg);
    void broadcast_current_State() const;
    void loadBoxes();
    void unloadBoxes();
    void goToNextDestination();
//    void position(const Point& location, const double& speed);
    void startWorking(const string& farmName, const Point& farmLocation, const string& castleName, const Point& castleLocation);
    
private:
    int inventory;
    Point source;
    //Point destination;
};

#endif /* Peasant_h */
