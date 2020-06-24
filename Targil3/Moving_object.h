#ifndef Moving_object_h
#define Moving_object_h

#include <stdio.h>
#include "Geometry.h"
using namespace std;

enum{DEAD=0, STOPPED=1, MOVING=2, PEASANT_SPEED=5, PEASANT_HEALTH_MAX=20, PEASANT_HEALTH=10, KNIGHT_SPEED=10, THUG_SPEED_MAX=30, THUG_HEALTH=5, THUG_HEALTH_MAX=20};

class Moving_object{
public:
    Moving_object(const Point& location, const Point& destination, const double& speed, const double& theta, const double& radius);
    virtual ~Moving_object(){};
    
    const Point& getLocation() const{return location;}
    
    void setTetha(double theta);
    void setSpeed(double speed);
    void setRadius(double radius);
    
    double getTheta() const;
    double getRadius() const;
    double getSpeed() const;
    
private:
    Point location;
    Point destination;
    double speed;
    double theta;
    double radius;
};

#endif /* Moving_object_h */
