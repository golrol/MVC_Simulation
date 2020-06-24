#ifndef Agent_h
#define Agent_h

#include "Sim_object.h"
#include "Moving_object.h"
using namespace std;

class Agent : public Sim_object, private Moving_object{
public:
    Agent(const string& name, const Point& location, const Point& destination, const int& speed, const int& health, const int& state);
    virtual ~Agent(){};
    
    virtual void update() = 0;
    virtual void broadcast_current_State() const = 0;
    
    void setTetha(double theta);
    void setSpeed(double speed);
    void go();
    void setLocatoin(Point location);
    
    Point getLocation() const;
    
private:
    int health;
    int state;

};


#endif /* Agent_h */
