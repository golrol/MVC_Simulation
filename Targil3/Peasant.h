#ifndef Peasant_h
#define Peasant_h

#include "Agent.h"
#include "Structure.h"
//#include "Farm.h"
//#include "Castle.h"

class Peasant : public Agent{
public:
    Peasant(const string& name, const Point& location);
    virtual ~Peasant(){};
    
//    void updateDeg(const double &deg);
    void broadcast_current_State() const;
    void loadBoxes();
    void unloadBoxes();
    void goToNextDestination();
//    void position(const Point& location, const double& speed);
    void startWorking(const shared_ptr<Structure>& farm, const shared_ptr<Structure>& castle);
    void setFarm(const shared_ptr<Structure>& farm);
    void setCastle(const shared_ptr<Structure>& castle);
    const shared_ptr<Structure>& getFarm() const;
    const shared_ptr<Structure>& getCastle() const;
    void setInventory(const int& inventory);
    const int& getInventory() const;

private:
    int inventory;
    shared_ptr<Structure> farm;
    shared_ptr<Structure> castle;

};

#endif /* Peasant_h */
