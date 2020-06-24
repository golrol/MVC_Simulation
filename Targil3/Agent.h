#ifndef Agent_h
#define Agent_h

#include "Sim_object.h"
#include "Moving_object.h"
using namespace std;

enum{DEAD=0, STOPPED=1, MOVING=2, PEASANT_SPEED=5, PEASANT_HEALTH_MAX=20, PEASANT_HEALTH=10, KNIGHT_SPEED=10, THUG_SPEED_MAX=30, THUG_HEALTH=5, THUG_HEALTH_MAX=20};

class Agent : public Sim_object{
public:
    Agent(const string& name, const Point& location, const Point& destination, const int& speed, const int& health, const int& state);
    virtual ~Agent(){};
    
    virtual void update() = 0;
    virtual void broadcast_current_State() const = 0;
    
    virtual void go();
    
    
    Point getLocation() const;
    double getSpeed() const;
    double getTheta() const;
    double getRadius() const;
    
    void setLocation(Point location);
    void setSpeed(double speed);
    void setTetha(double theta);
    void setRadius(double radius);
    
    
    
private:
    int health;
    int state;
    Point location;
    Point destination;
    double speed;
    double theta;
    double radius;

};


#endif /* Agent_h */
