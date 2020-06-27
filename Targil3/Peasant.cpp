#include "Peasant.h"

Peasant::Peasant(const string& name, const Point& location)
:Agent(name, PEASANT_HEALTH, STOPPED, location, PEASANT_SPEED, PEASANT), inventory(0){}


void Peasant::updateDeg(const double &deg) {
    setTetha(deg);
}

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
            cout << "Heading to " << getDestinationName() << ", speed " << getSpeed() << " km/h" << endl;
            break;
        default:
            break;
    }
}

void Peasant::loadBoxes(){
    
}
