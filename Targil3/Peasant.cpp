#include "Peasant.h"

Peasant::Peasant(const string& name, const Point& location)
:Agent(name, location, location, PEASANT_SPEED, PEASANT_HEALTH, STOPPED){}
