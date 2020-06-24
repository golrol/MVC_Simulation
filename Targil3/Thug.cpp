#include "Thug.h"

Thug::Thug(const std::string &name, const Point &location)
:Agent(name, THUG_HEALTH, STOPPED, location, location, 0){}

Thug::~Thug(){}

void Thug::updateDegAndSpeed(const pair<double, double> &degAndSpeed) { 
    setTetha(degAndSpeed.first);
    setSpeed(degAndSpeed.second);
    setRadius(degAndSpeed.second); /*radius always equals to speed(for calculations)*/
}

void Thug::broadcast_current_State() const { 
    cout << "Thug " << getName() << " at ";
    getLocation().print();
    cout << ", " << getState();
}


