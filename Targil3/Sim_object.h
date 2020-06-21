#ifndef Sim_object_h
#define Sim_object_h

#include <stdio.h>
#include <iostream>
#include "Geometry.h"
using namespace std;

class Sim_object{
public:
    Sim_object(const string& name);
    virtual ~Sim_object(){}
    
    
    const string& getName() const{return name;}
    virtual const Point& getLocation() const = 0;
    
    virtual void update() = 0;
    virtual void broadcast_current_State() const = 0;
    
private:
    string name;
};

#endif /* Sim_object_h */