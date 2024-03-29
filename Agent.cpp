#include "Agent.h"

Agent::Agent(const string& name, const int& health, const int& state, const Point& location, const double& speed, const int& type)
        :Sim_object(name), health(health), state(state), location(location), destinationName(""), speed(speed), theta(0), radius(speed/10.00), type(type){}
Agent::~Agent(){}

void Agent::update() {
    if (state == MOVING_ON_COURSE)
        setLocation(getLocation() + polarToCartesian(radius, theta));

    else if (state == MOVING_TO_DESTINATION){
        if (findDistance(location, destinationLocation) <= speed/10.00){/*arriving to destination in this step*/
            setLocation(destinationLocation); /*update location to destination*/
            switch (type) {
                case THUG:
                    goToNextDestination();
                    break;
                case PEASANT:
                    goToNextDestination();
                    break;
                case KNIGHT:
                    goToNextDestination();
                    break;
                default:
                    break;
            }
        }
        else{
            setLocation(getLocation() + delta);
        }
    }
    else if (state == UNLOADING || state == LOADING){
        goToNextDestination();
    }
    else if (state == PREPARE_TO_ATTACK){
        setState(READY_TO_ATTACK);
    }
}

void Agent::position(const Point &location, const double &speed) {
    setState(MOVING_TO_DESTINATION);
    setDestination(location); /*update destination's location (Point)*/
    setSpeed(speed);
    double distance = findDistance(getLocation(), location); /*distance to destination*/
    double numberOfSteps = distance / (getSpeed()/10.00); /*number of steps until arriving to destination*/

    /*update deltaX and deltaY according to the change need to be done in every step*/
    setDelta(Point((getDestination().x - getLocation().x) / numberOfSteps, (getDestination().y - getLocation().y) / numberOfSteps));
}


/* getters and setters */
int Agent::getHealth() const {
    return health;
}
int Agent::getState() const{
    return state;
}
Point Agent::getLocation() const {
    return location;
}
Point Agent::getDestination() const{
    return destinationLocation;
}
string Agent::getDestinationName() const{
    return destinationName;
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
int Agent::getType() const{
    return type;
}
Point Agent::getDelta() const {
    return delta;
}

void Agent::setHealth(int health){
    this->health = health;
}
void Agent::setState(int state){/*no zombies allowed*/
    if (this->state == DEAD)
        return;
    this->state = state;
}
void Agent::setLocation(Point location){
    this->location = location;
}
void Agent::setDestination(Point destination){
    this->destinationLocation = destination;
}
void Agent::setDestinationName(string StructureName){
    this->destinationName = StructureName;
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
void Agent::setDelta(Point delta) {
    this->delta = delta;
}
