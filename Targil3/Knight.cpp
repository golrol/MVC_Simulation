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
            if (getDestinationName().size() > 0)
                cout << "Heading to " << getDestinationName() << ", speed " << getSpeed() << " km/h" << endl;
            else{
                cout << "Heading to ";
                getDestination().print();
                cout << ", speed " << getSpeed() << " km/h" << endl;
            }
            break;
        default:
            break;
    }
}


void Knight::position(const Point& location){
    setState(MOVING_TO_DESTINATION);
    setDestination(location); /*update destination's location (Point)*/
    double distance = findDistance(getLocation(), location); /*distance to destination*/
    double numberOfsteps = distance / (getSpeed()/10.00); /*number of steps until arriving to destination*/
    
    /*update deltaX and deltaY according to the change need to be done in every step*/
    setDelta(Point((getDestination().x - getLocation().x) / numberOfsteps, (getDestination().y - getLocation().y) / numberOfsteps));
}

void Knight::destination(const string& StructureName, const Point& StructureLocation){
    setDestinationName(StructureName); /*update destination's name*/
    position(StructureLocation); /*call position() to handle the update*/
    
    
//    updateDeg(getDegFromTwoPoints(getLocation(), StructureLocation));
//    cout << "TEST" << getTheta() << endl;
}

void Knight::addToQueue(const shared_ptr<Structure>& structure){
    structures.push(structure);
}

void Knight::goToNextDestination(){
    shared_ptr<Structure> nextStructure = structures.front();
    if (nextStructure->getName() == getDestinationName()){/*case first in queue is the same as just arrived*/
        structures.pop();
        structures.push(nextStructure);
        nextStructure = structures.front();
    }
    destination(nextStructure->getName(), nextStructure->getLocation());
}
