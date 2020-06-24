#ifndef Structure_h
#define Structure_h

#include "Sim_object.h"

class Structure : public Sim_object{
public:
    Structure(const string& name, const Point& location);
    ~Structure();
    
    const Point& getLocation() const;
    
private:
    Point location;
};

#endif /* Structure_h */
