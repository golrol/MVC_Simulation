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
    /*no need for operator=, copy c'tor and move c'tor- using unly pointers*/
    
    /*getters and setters*/
    const string& getName() const{return name;}
    void setName(const string& name) {this->name = name;}
    
    virtual void update() = 0;
    virtual void broadcast_current_State() const = 0;
    
private:
    string name;
    
};

#endif /* Sim_object_h */
