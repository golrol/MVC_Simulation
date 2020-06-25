#ifndef Model_h
#define Model_h

#include <vector>
#include "skeleton_View.h"
#include "Agent.h"
#include "Structure.h"
#include "Knight.h"
#include "Peasant.h"
#include "Thug.h"
#include "Farm.h"
#include "Castle.h"
#include "Validation.h"

class Model{
public:
    static shared_ptr<Model> getInstance();
    ~Model();
    Model(const Model&) = delete;
    Model(const Model&&) = delete;
    Model& operator=(const Structure&) = delete;
    Model& operator=(const Structure&&) = delete;
    
    void addAgent(const vector<string>& vec);
    void addStructure(const string& name, const Point& location, const int& inventory, const int& type, const int& productionRate);
    vector<shared_ptr<Agent>>::const_iterator findAgentByName(const string& name) const;
    vector<shared_ptr<Structure>>::const_iterator findStructureByName(const string& name) const;
    
    void updateAgentDegAndSpeed(const vector<shared_ptr<Agent>>::const_iterator& agent, const pair<int,int>& degAndSpeed);
    void changeState(const vector<shared_ptr<Agent> >::const_iterator& agent, const int& state);
    
    void setViewPtr(shared_ptr<View> view_ptr);
    void go();
    Point getPointFromStructure(const string& structureName) const;
    void status() const;
    
    
    const int& getTime();
    
    class xNoSuchAgent{
    public:
        void what() const{cerr << "No such Agent exists" << endl;}
    };
    
    class xNoSuchStructure{
    public:
        void what() const{cerr << "No such Structure exists" << endl;}
    };
    
    class xInvalidArgument{
    public:
        xInvalidArgument(const string& str):str(str){}
        ~xInvalidArgument(){};
        void what() const{cerr << str << endl;}
    private:
        string str;
    };
    
    class xFileException{
    public:
        void what() const{cerr << "Can't open file" << endl;}
    };
    
private:
    static shared_ptr<Model> inst;
    shared_ptr<View> view_ptr;
    
    vector<shared_ptr<Agent> > agentsVec;
    vector<shared_ptr<Structure> > structuresVec;
    int time;
    
    Model();
};

#endif /* Model_h */
