#ifndef Agent_h
#define Agent_h

#include "Sim_object.h"
#include "Moving_object.h"
using namespace std;

enum{DEAD, STOPPED, MOVING_TO_DESTINATION, MOVING_ON_COURSE, LOADING, UNLOADING, PEASANT_SPEED=5, PEASANT_HEALTH_MAX=20, PEASANT_HEALTH=10, KNIGHT_SPEED=10, THUG_SPEED_MAX=30, THUG_HEALTH=5, THUG_HEALTH_MAX=20, PEASANT=0, KNIGHT=1, THUG=2};

class Agent : public Sim_object{
public:
    Agent(const string& name, const int& health, const int& state, const Point& location, const double& speed, const int& type);
    virtual ~Agent(){};
    
    virtual void update();
    void broadcast_current_State() const = 0;
    
    
    Point getLocation() const;
    Point getDestination() const;
    double getSpeed() const;
    double getTheta() const;
    double getRadius() const;
    int getState() const;
    int getHealth() const;
    int getType() const;
    string getDestinationName() const;
    Point getDelta() const;
    
//    void setLocationWithOffset(Point location);
    void setLocation(Point location);
    void setSpeed(double speed);
    void setTetha(double theta);
    void setRadius(double radius);
    void setState(int state);
    void setDestination(Point destination);
    void setDestinationName(string StructureName);
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
