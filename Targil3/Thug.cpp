#include "Thug.h"

Thug::Thug(const std::string &name, const Point &location)
:Agent(name, THUG_HEALTH, STOPPED, location, 0, THUG){}

Thug::~Thug(){}

void Thug::updateDegAndSpeed(const pair<double, double> &degAndSpeed) { 
    setTetha(degAndSpeed.first);
    setSpeed(degAndSpeed.second);
    setRadius(degAndSpeed.second/10.00); /*radius always equals to speed/10 (for calculations)*/
}

void Thug::broadcast_current_State() const { 
    cout << "Thug " << getName() << " at ";
    getLocation().print();
    cout << ", ";
    switch (getState()) {
        case STOPPED:
            cout << "Stopped." << endl;
            break;
        case MOVING_ON_COURSE:
            cout << "Heading on course " << getTheta() << " deg" << ", speed " << getSpeed() << " km/h" << endl;
            break;
        case MOVING_TO_DESTINATION:
            if (getDestinationName().size() > 0)
                cout << "Heading to " << getDestinationName() << ", speed " << getSpeed() << " km/h" << endl;
            else{
                cout << "Heading to ";
                getDestination().print();
                cout << ", speed " << getSpeed() << " km/h" << endl;
            }
        default:
            break;
    }
}

void Thug::position(const Point& location, const double& speed){
    setState(MOVING_TO_DESTINATION);
    setDestination(location); /*update destination's location (Point)*/
    setSpeed(speed);
    double distance = findDistance(getLocation(), location); /*distance to destination*/
    double numberOfsteps = distance / (getSpeed()/10.00); /*number of steps until arriving to destination*/
    
    /*update deltaX and deltaY according to the change need to be done in every step*/
    setDelta(Point((getDestination().x - getLocation().x) / numberOfsteps, (getDestination().y - getLocation().y) / numberOfsteps));
}
