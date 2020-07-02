#include "Structure.h"

Structure::Structure(const string& name, const Point& location, const int& inventory, const int& type)
:Sim_object(name), location(location), inventory(inventory), type(type){}

Structure::~Structure(){}

const Point &Structure::getLocation() const { 
    return location;
}

const int& Structure::getInventory() const{
    return inventory;
}
const int& Structure::getType() const{
    return type;
}


void Structure::setInventory(const int& inventory){
    this->inventory = inventory;
}
