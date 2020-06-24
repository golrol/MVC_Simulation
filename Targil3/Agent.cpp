#include "Agent.h"


Agent::Agent(const string& name, const Point& location, const Point& destination, const int& speed, const int& health, const int& state)
:Sim_object(name), Moving_object(location, destination, speed, cartesianToPolar(location).second, cartesianToPolar(location).first), health(health), state(state){}

void Agent::setTetha(double theta) { 
    Moving_object::setTetha(theta);
}

void Agent::setSpeed(double speed) {
    Moving_object::setSpeed(speed);
}

void Agent::go() { 
    setRadius(getRadius() + getSpeed());
    setLocatoin(polarToCartesian(getRadius(), getTheta()));
}

void Agent::setLocatoin(Point location){
    this->location = location;
}

Point Agent::getLocation() const{
    return location;
}
