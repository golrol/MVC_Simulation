#ifndef Model_h
#define Model_h

#include <fstream>
#include "View.h"
#include "Knight.h"
#include "Peasant.h"
#include "Thug.h"
#include "Farm.h"
#include "Castle.h"
#include "Validation.h"
enum{PEASANT_RADIUS=1, NUMBER_OF_FILES=3};
const double KNIGHT_RADIUS = 2.5;

class Model{
public:
    static shared_ptr<Model> getInstance();/*lazy init*/
    ~Model();
    /*Singleton*/
    Model(const Model&) = delete;
    Model(const Model&&) = delete;
    Model& operator=(const Structure&) = delete;
    Model& operator=(const Structure&&) = delete;
    
    /* init files functions */
    void farmInit(const string& fileName);
    void castleInit(const string& fileName);
    
    /*adding and finding Sim_objecs*/
    void addAgent(const vector<string>& vec); /*vec includes all the Sim_object's details*/
    void addStructure(const string& name, const Point& location, const int& inventory, const int& type, const int& productionRate);
    vector<shared_ptr<Agent>>::const_iterator findAgentByName(const string& name) const;
    vector<shared_ptr<Structure>>::const_iterator findStructureByName(const string& name) const;
    
    /* sending command to agents */
    void updateAgentDegAndSpeed(const vector<shared_ptr<Agent>>::const_iterator& agent, const pair<double,double>& degAndSpeed);
    void changeState(const vector<shared_ptr<Agent> >::const_iterator& agent, const int& state);
    void status() const; /*send status request for every Sim_object*/
    void addAttckingThug(shared_ptr<Agent> thug);
    void attack(shared_ptr<Agent> thug);/*helper func*/
    
    void go(); /*increment time and execute update() on every Sim_object*/
    
    /* getters */
    const int& getTime();
    shared_ptr<View> getViewPtr() const;
    
    /* exceptions */
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
        xFileException(const string& str):str(str){}
        ~xFileException(){};
        void what() const{cerr << str << endl;}
    private:
        string str;
    };
    
private:
    static shared_ptr<Model> inst; /*singleton*/
    shared_ptr<View> view_ptr; /*to send comand to the View*/
    
    vector<shared_ptr<Agent> > agentsVec; /*all the agents in the program*/
    vector<shared_ptr<Structure> > structuresVec; /*all the structures in the program*/
    vector<shared_ptr<Agent> > attackingThugs;
    int time;
    
    Model();/*private c'tor*/
};

#endif /* Model_h */
