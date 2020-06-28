#include "Peasant.h"

Peasant::Peasant(const string& name, const Point& location)
:Agent(name, PEASANT_HEALTH, STOPPED, location, PEASANT_SPEED, PEASANT), inventory(0){}


//void Peasant::updateDeg(const double &deg) {
//    setTetha(deg);
//}

void Peasant::broadcast_current_State() const{
    cout << "Peasant " << getName() << " at ";
    getLocation().print();
    cout << ", ";
    switch (getState()) {
        case STOPPED:
            cout << "Stopped." << endl;
            break;
        case MOVING_ON_COURSE:
            cout << "Heading on course " << getTheta() << " deg" << ", speed " << getSpeed() << " km/h, inventory: " << inventory << " health: " << getHealth() << endl;
            break;
        case MOVING_TO_DESTINATION:
            cout << "Heading to " << getDestinationName() << ", speed " << getSpeed() << " km/h, inventory: " << inventory << " health: " << getHealth() << endl;
            break;
        case UNLOADING:
            cout << "Unloading at " << getDestinationName() << ", inventory: " << inventory << " health: " << getHealth() << endl;
            break;
        case LOADING:
            cout << "Loading at " << getDestinationName() << ", inventory: " << inventory << " health: " << getHealth() << endl;
            break;
        default:
            break;
    }
}

void Peasant::loadBoxes(){
    
}

void Peasant::unloadBoxes(){
    
}

void Peasant::startWorking(const string& farmName, const Point& farmLocation, const string& castleName, const Point& castleLocation){
    
}

//void Peasant::position(const Point& location, const double& speed){
//    setState(MOVING_TO_DESTINATION);
//    setDestination(location); /*update destination's location (Point)*/
//    double distance = findDistance(getLocation(), location); /*distance to destination*/
//    double numberOfsteps = distance / (getSpeed()/10.00); /*number of steps until arriving to destination*/
//    
//    /*update deltaX and deltaY according to the change need to be done in every step*/
//    setDelta(Point((getDestination().x - getLocation().x) / numberOfsteps, (getDestination().y - getLocation().y) / numberOfsteps));
//}

void Peasant::goToNextDestination(){
    
}
