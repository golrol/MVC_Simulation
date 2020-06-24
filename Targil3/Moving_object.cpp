#include "Moving_object.h"


Moving_object::Moving_object(const Point& location, const Point& destination, const double& speed, const double& theta, const double& radius)
:location(location), destination(destination), speed(speed), theta(theta), radius(radius){}


void Moving_object::setTetha(double theta){
    this->theta = theta;
}
void Moving_object::setSpeed(double speed){
    this->speed = speed;
}

void Moving_object::setRadius(double radius){
    this->radius = radius;
}

double Moving_object::getRadius() const{
    return radius;
}

double Moving_object::getSpeed() const{
    return speed;
}

double Moving_object::getTheta() const{
    return theta;
}

void Moving_object::setLocation(Point location) { 
    this->location.x = this->location.x + location.x;
    this->location.y = this->location.y + location.y;
}


Point Moving_object::getLocatoin() const { 
    return location;
}

