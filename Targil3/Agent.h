#ifndef Agent_h
#define Agent_h

#include "Sim_object.h"
#include "Moving_object.h"
using namespace std;

enum{DEAD=0, STOPPED=1, MOVING=2, PEASANT_SPEED=5, PEASANT_HEALTH_MAX=20, PEASANT_HEALTH=10, KNIGHT_SPEED=10, THUG_SPEED_MAX=30, THUG_HEALTH=5, THUG_HEALTH_MAX=20, PEASANT, KNIGHT, THUG};

class Agent : public Sim_object{
public:
    Agent(const string& name, const int& health, const int& state, const Point& location, const Point& destination, const int& speed, const int& type);
    virtual ~Agent(){};
    
    virtual void update();
    void broadcast_current_State() const = 0;
    
    
    Point getLocation() const;
    double getSpeed() const;
    double getTheta() const;
    double getRadius() const;
    int getState() const;
    int getType() const;
    
    void setLocation(Point location);
    void setSpeed(double speed);
    void setTetha(double theta);
    void setRadius(double radius);
    void setState(int state);
    
    
private:
    int health;
    int state;
    Point location;
    Point destination;
    double speed;
    double theta;
    double radius;
    int type;

};


#endif /* Agent_h */
