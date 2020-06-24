#include "Structure.h"

Structure::Structure(const string& name, const Point& location, const int& inventory)
:Sim_object(name), location(location), inventory(inventory){}

Structure::~Structure(){}

const Point &Structure::getLocation() const { 
    return location;
}

const int& Structure::getInventory() const{
    return inventory;
}
