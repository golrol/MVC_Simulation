#ifndef Structure_h
#define Structure_h

#include "Sim_object.h"

enum{FARM, CASTLE};

class Structure : public Sim_object{
public:
    Structure(const string& name, const Point& location, const int& inventory, const int& type);
    ~Structure();
    /*no need for operator=, copy c'tor and move c'tor- using unly pointers*/
    
    /*getters and setters*/
    const Point& getLocation() const;
    const int& getInventory() const;
    const int& getType() const;
    
    void setInventory(const int& inventory);
    
private:
    Point location;
    int inventory;
    int type;
};

#endif /* Structure_h */
