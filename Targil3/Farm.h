#ifndef Farm_h
#define Farm_h

#include "Structure.h"

class Farm : public Structure{
public:
    Farm(const string& name, const Point& location, const int& inventory);
    virtual ~Farm();
    
    void update();
    void broadcast_current_State() const;
    
private:
    
};

#endif /* Farm_h */
