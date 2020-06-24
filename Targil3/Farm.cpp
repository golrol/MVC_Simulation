#include "Farm.h"

Farm::Farm(const string& name, const Point& location, const int& inventory)
:Structure(name, location, inventory){}

Farm::~Farm(){}

void Farm::broadcast_current_State() const { 
    cout << "Farm " << getName() << " at position ";
    getLocation().print();
    cout <<", Inventory: " << getInventory() << endl;
}

void Farm::update(){
    
}
