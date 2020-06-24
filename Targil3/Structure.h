#ifndef Structure_h
#define Structure_h

#include "Sim_object.h"

enum{FARM, CASTLE};

class Structure : public Sim_object{
public:
    Structure(const string& name, const Point& location, const int& inventory);
    ~Structure();
    
    const Point& getLocation() const;
    const int& getInventory() const;
    
private:
    Point location;
    int inventory;
};

#endif /* Structure_h */
