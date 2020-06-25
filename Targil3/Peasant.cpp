#include "Peasant.h"

Peasant::Peasant(const string& name, const Point& location)
:Agent(name, PEASANT_HEALTH, STOPPED, location, location, PEASANT_SPEED, PEASANT){}


void Peasant::broadcast_current_State() const{
    cout << "Peasant " << getName() << " at ";
    getLocation().print();
    cout << ", " << getState() << endl;
}
