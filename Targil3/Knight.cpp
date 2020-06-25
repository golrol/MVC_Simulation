#include "Knight.h"

Knight::Knight(const string &name, const Point& location)
:Agent(name, 0, STOPPED, location, KNIGHT_SPEED, KNIGHT){}

void Knight::updateDeg(const double &deg) { 
    setTetha(deg);
}

void Knight::broadcast_current_State() const{
    cout << "Knight " << getName() << " at ";
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
            cout << "Heading to " << getDestinationName() << ", speed " << getSpeed() << " km/h" << endl;
            break;
        default:
            break;
    }
}


void Knight::destination(const string& StructureName, const Point& StructureLocation){
    setState(MOVING_TO_DESTINATION);
    setDestination(StructureLocation);
    setDestinationName(StructureName);
    updateDeg(getDegFromTwoPoints(getLocation(), StructureLocation));
    cout << "TEST" << getTheta() << endl;
}
