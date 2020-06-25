#ifndef Castle_h
#define Castle_h

#include "Structure.h"

class Castle : public Structure{
public:
    Castle(const string& name, const Point& location, const int& inventory);
    ~Castle();
    
    void update();
    void broadcast_current_State() const;
    
private:
    
};

#endif /* Castle_h */
