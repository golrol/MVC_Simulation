#include "Knight.h"

Knight::Knight(const string &name, const Point& location)
:Agent(name, 0, STOPPED, location, location, KNIGHT_SPEED){}

void Knight::updateDeg(const double &deg) { 
    setTetha(deg);
}

void Knight::broadcast_current_State() const{
    cout << "Knight " << getName() << " at ";
    getLocation().print();
    cout << ", " << getState() << endl;
}
