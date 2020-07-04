#include "Peasant.h"

Peasant::Peasant(const string& name, const Point& location)
:Agent(name, PEASANT_HEALTH, STOPPED, location, PEASANT_SPEED, PEASANT), inventory(0){}

Peasant::~Peasant(){}

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
        case DEAD:
            cout << "Dead at ";
            getLocation().print();
            cout << endl;
            break;
        default:
            break;
    }
}

void Peasant::goToNextDestination(){
    if (getState() == MOVING_TO_DESTINATION){
        if (getLocation() == farm->getLocation()){
            //ariived in farm - load.
            setState(LOADING);
            if (farm->getInventory() <= MAX_CARRY){
                setInventory(farm->getInventory());
                farm->setInventory(0);
            }
            else{
                farm->setInventory(farm->getInventory() - MAX_CARRY);
                setInventory(MAX_CARRY);
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
        setHealth(getHealth() + 1); /*increase health by one*/
        setDestinationName(farm->getName());
        position(farm->getLocation(), getSpeed());
    }
}

void Peasant::startWorking(const shared_ptr<Structure>& farm, const shared_ptr<Structure>& castle){
    setFarm(farm);
    setCastle(castle);
    setDestinationName(farm->getName());
    position(farm->getLocation(), getSpeed());
}

/* getters and setters */
const int &Peasant::getInventory() const {
    return inventory;
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
void Peasant::setFarm(const shared_ptr<Structure> &farm) { 
    this->farm = farm;
}

void Peasant::setCastle(const shared_ptr<Structure> &castle) { 
    this->castle = castle;
}
