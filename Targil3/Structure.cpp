#include "Structure.h"

Structure::Structure(const string& name, const Point& location)
:Sim_object(name), location(location){}

Structure::~Structure(){}

const Point &Structure::getLocation() const { 
    return location;
}

