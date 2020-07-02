#ifndef Agent_h
#define Agent_h

#include "Sim_object.h"
using namespace std;

enum{DEAD, STOPPED, MOVING_TO_DESTINATION, MOVING_ON_COURSE, LOADING, UNLOADING, PEASANT_SPEED=5, PEASANT_HEALTH_MAX=20, PEASANT_HEALTH=10, KNIGHT_SPEED=10, THUG_SPEED_MAX=30, THUG_HEALTH=5, THUG_HEALTH_MAX=20, PEASANT=0, KNIGHT=1, THUG=2};

class Agent : public Sim_object{
public:
    Agent(const string& name, const int& health, const int& state, const Point& location, const double& speed, const int& type);
    virtual ~Agent();
    /*no need for operator=, copy c'tor and move c'tor- using unly pointers*/
    
    virtual void update();
    void broadcast_current_State() const = 0;
    virtual void goToNextDestination() = 0;
    void position(const Point& location, const double& speed);
    
    /* getters and setters */
    int getHealth() const;
    int getState() const;
    Point getLocation() const;
    Point getDestination() const;
    string getDestinationName() const;
    double getSpeed() const;
    double getTheta() const;
    double getRadius() const;
    int getType() const;
    Point getDelta() const;
    
    void setState(int state);
    void setLocation(Point location);
    void setDestination(Point destination);
    void setDestinationName(string StructureName);
    void setSpeed(double speed);
    void setTetha(double theta);
    void setRadius(double radius);
    void setDelta(Point delta);
    
private:
    int health;
    int state;
    Point location;
    Point destinationLocation;
    string destinationName;
    double speed;
    double theta;
    double radius;
    int type;
    Point delta;
};


#endif /* Agent_h */
