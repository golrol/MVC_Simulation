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
        default:
            break;
    }
}
