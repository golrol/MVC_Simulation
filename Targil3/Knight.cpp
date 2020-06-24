#include "Knight.h"

Knight::Knight(const string &name, const Point& location)
:Agent(name, location, location, KNIGHT_SPEED, 0, STOPPED){}

void Knight::updateDeg(const double &deg) { 
    setTetha(deg);
}

