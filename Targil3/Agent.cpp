#include "Agent.h"


Agent::Agent(const string& name, const int& health, const int& state, const Point& location, const double& speed, const int& type)
:Sim_object(name), health(health), state(state), location(location), destinationName(""), speed(speed), theta(0), radius(speed/10.00), type(type){}

Point Agent::getLocation() const { 
    return location;
}

double Agent::getSpeed() const { 
    return speed;
}

double Agent::getTheta() const { 
    return theta;
}

double Agent::getRadius() const { 
    return radius;
}

int Agent::getState() const{
    return state;
}

void Agent::setLocation(Point location) {/*adding the offset from the current location*/
    this->location.x = this->location.x + location.x;
    this->location.y = this->location.y + location.y;
}

void Agent::setSpeed(double speed) { 
    this->speed = speed;
}

void Agent::setTetha(double theta) { 
    this->theta = theta;
}

void Agent::setRadius(double radius) { 
    this->radius = radius;
}

void Agent::update() {
    if (state == MOVING_TO_DESTINATION || state == MOVING_ON_COURSE)
        setLocation(polarToCartesian(radius, theta));
}


int Agent::getType() const{
    return type;
}


void Agent::setState(int state){
    this->state = state;
}

void Agent::setDestinationName(string StructureName){
    this->destinationName = StructureName;
}

void Agent::setDestination(Point destination){
    this->destination = destination;
}

string Agent::getDestinationName() const{
    return destinationName;
}

int Agent::getHealth() const { 
    return health;
}

