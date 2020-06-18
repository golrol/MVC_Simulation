#include "Agent.h"


Agent::Agent(const string& name, const Point& location, const Point& destination, const int& speed, const int& health, const int& state)
:Sim_object(name), Moving_object(location, destination, speed), health(health), state(state){}
