#include "Thug.h"

Thug::Thug(const std::string &name, const Point &location)
:Agent(name, location, location, 0, THUG_HEALTH, STOPPED){}

Thug::~Thug(){}

void Thug::updateDegAndSpeed(const pair<double, double> &degAndSpeed) { 
    setTetha(degAndSpeed.first);
    setSpeed(degAndSpeed.second);
}

