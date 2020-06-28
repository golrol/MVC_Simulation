#ifndef Peasant_h
#define Peasant_h

#include "Agent.h"

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
    void startWorking(const string& farmName, const Point& farmLocation, const string& castleName, const Point& castleLocation);
//    const Point &getSecondLocation() const;
//    void setSecondLocation(const Point &secondLocation);
//    const string &getSecondLocationName() const;
//    void setSecondLocationName(const string &secondLocationName);
    const pair<string,Point> &getFarm() const;
    void setFarm(const pair<string,Point> &farm);
    const pair<string,Point> &getCastle() const;
    void setCastle(const pair<string,Point> &castle);

private:
    int inventory;
    pair<string,Point> farm;
    pair<string,Point> castle;

};

#endif /* Peasant_h */
