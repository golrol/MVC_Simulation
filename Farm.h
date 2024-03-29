#ifndef Farm_h
#define Farm_h

#include "Structure.h"

class Farm : public Structure{
public:
    Farm(const string& name, const Point& location, const int& inventory, int const& productionRate);
    virtual ~Farm();
    /*no need for operator=, copy c'tor and move c'tor- using unly pointers*/
    
    /* inherited functions */
    void update();
    void broadcast_current_State() const;
    
private:
    int productionRate;
    
};

#endif /* Farm_h */
