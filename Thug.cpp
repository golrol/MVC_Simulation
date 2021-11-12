#include "Thug.h"

Thug::Thug(const std::string &name, const Point &location)
:Agent(name, THUG_HEALTH, STOPPED, location, 0, THUG){}

Thug::~Thug(){}

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
            break;
        case PREPARE_TO_ATTACK:
            cout << "preparing to attack " << getPeasantToAttack()->getName() << endl;
            break;
        case READY_TO_ATTACK:
            cout << "preparing to attack " << getPeasantToAttack()->getName() << endl;
            break;
        default:
            break;
    }
}

void Thug::goToNextDestination(){
    setState(STOPPED);
}

void Thug::updateDegAndSpeed(const pair<double, double> &degAndSpeed) { 
    setTetha(degAndSpeed.first);
    setSpeed(degAndSpeed.second);
    setRadius(degAndSpeed.second/10.00); /*radius always equals to speed/10 (for calculations)*/
}

void Thug::attack(shared_ptr<Agent> peasantToAttack) { 
    this->peasantToAttack = peasantToAttack;
    setState(PREPARE_TO_ATTACK);
}

shared_ptr<Agent> Thug::getPeasantToAttack() const{
    return peasantToAttack;
}
