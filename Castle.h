#ifndef Castle_h
#define Castle_h

#include "Structure.h"

class Castle : public Structure{
public:
    Castle(const string& name, const Point& location, const int& inventory);
    ~Castle();
    /*no need for operator=, copy c'tor and move c'tor- using unly pointers*/
    
    /* inherited functions */
    void update(){}/*doesn't need to update anything*/
    void broadcast_current_State() const;
    
};

#endif /* Castle_h */
