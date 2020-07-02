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

void Peasant::startWorking(const shared_ptr<Structure>& farm, const shared_ptr<Structure>& castle){
    setFarm(farm);
    setCastle(castle);
    setDestinationName(farm->getName());
    position(farm->getLocation(), getSpeed());
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
    if (getState() == MOVING_TO_DESTINATION){
        if (getLocation() == farm->getLocation()){
            //ariived in farm - load.
            setState(LOADING);
            if (farm->getInventory() <= 5){ //TODO: magic number
                setInventory(farm->getInventory());
                farm->setInventory(0);
            }
            else{
                farm->setInventory(farm->getInventory() - 5);
                setInventory(5);
            }
        }
        else if (getLocation() == castle->getLocation()){
            //ariived in castle - unload.
            setState(UNLOADING);
            castle->setInventory(castle->getInventory() + getInventory());
            setInventory(0);
        }
    }
    else if (getState() == LOADING){
        //finished loading- use position() to castle.
        setDestinationName(castle->getName());
        position(castle->getLocation(), getSpeed());
    }
    else if (getState() == UNLOADING){
        //finished loading- use position() back to farm.
        setDestinationName(farm->getName());
        position(farm->getLocation(), getSpeed());
    }
}

void Peasant::setFarm(const shared_ptr<Structure> &farm) { 
    this->farm = farm;
}

void Peasant::setCastle(const shared_ptr<Structure> &castle) { 
    this->castle = castle;
}

const shared_ptr<Structure> &Peasant::getFarm() const { 
    return farm;
}

const shared_ptr<Structure> &Peasant::getCastle() const { 
    return castle;
}

void Peasant::setInventory(const int &inventory) { 
    this->inventory = inventory;
}

const int &Peasant::getInventory() const { 
    return inventory;
}


