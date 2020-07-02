#include "Castle.h"

Castle::Castle(const string& name, const Point& location, const int& inventory)
:Structure(name, location, inventory, CASTLE){}

Castle::~Castle(){}

void Castle::broadcast_current_State() const { 
    cout << "Castle " << getName() << " at position ";
    getLocation().print();
    cout <<", Inventory: " << getInventory() << endl;
}
