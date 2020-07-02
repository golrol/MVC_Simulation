#ifndef Peasant_h
#define Peasant_h

#include "Agent.h"
#include "Structure.h"

enum{MAX_CARRY=5};

class Peasant : public Agent{
public:
    Peasant(const string& name, const Point& location);
    virtual ~Peasant();
    /*no need for operator=, copy c'tor and move c'tor- using unly pointers*/
    
    /* inherited functions */
    void broadcast_current_State() const;
    void goToNextDestination();
    
    /* personal functions */
    void startWorking(const shared_ptr<Structure>& farm, const shared_ptr<Structure>& castle);
    
    /* getters and setters */
    const int& getInventory() const;
    const shared_ptr<Structure>& getFarm() const;
    const shared_ptr<Structure>& getCastle() const;
    
    void setInventory(const int& inventory);
    void setFarm(const shared_ptr<Structure>& farm);
    void setCastle(const shared_ptr<Structure>& castle);
    
private:
    int inventory;
    shared_ptr<Structure> farm;
    shared_ptr<Structure> castle;

};

#endif /* Peasant_h */
