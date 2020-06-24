#include "Knight.h"

Knight::Knight(const string &name, const Point& location)
:Agent(name, 0, STOPPED, location, location, KNIGHT_SPEED){}

void Knight::updateDeg(const double &deg) { 
    setTetha(deg);
}
