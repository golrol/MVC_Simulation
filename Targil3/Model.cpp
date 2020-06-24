#include "Model.h"

shared_ptr<Model> Model::inst = nullptr;

shared_ptr<Model> Model::getInstance() {
    if (inst == nullptr)
        inst.reset(new Model);
    return inst;
}

Model::Model()
:time(0)
{}

Model::~Model() {}

vector<shared_ptr<Agent>>::const_iterator Model::findAgentByName(const string& name) const{
    vector<shared_ptr<Agent>>::const_iterator it = agentsVec.begin();
    while(it != agentsVec.end()){
        if ((*it)->getName() == name)
            return it;
        it++;
    }
    throw 6;//TODO: throw
}

vector<shared_ptr<Structure>>::const_iterator Model::findStructureByName(const string& name) const{
    vector<shared_ptr<Structure>>::const_iterator it = structuresVec.begin();
    while(it != structuresVec.end()){
        if ((*it)->getName() == name)
            return it;
    }
    throw 6;//TODO: throw
}

void Model::addAgent(const vector<std::string> &vec) {
    shared_ptr<Agent> aPtr(new Thug(vec[1], pointValidation(vec[3])));
    agentsVec.push_back(aPtr);
    view_ptr->update_location(vec[1], pointValidation(vec[3]));
}

void Model::updateAgentDegAndSpeed(const vector<shared_ptr<Agent> >::const_iterator &agent, const pair<int, int> &degAndSpeed) {
    shared_ptr<Knight> knightPtr = dynamic_pointer_cast<Knight>((*agent));
    if (knightPtr != nullptr){
        knightPtr->updateDeg(degAndSpeed.first);
        return;
    }
    
    shared_ptr<Thug> ThugPtr = dynamic_pointer_cast<Thug>((*agent));
    if (ThugPtr != nullptr){
        ThugPtr->updateDegAndSpeed(degAndSpeed);
    }
    
    shared_ptr<Peasant> peasantPtr = dynamic_pointer_cast<Peasant>((*agent));
    if (peasantPtr != nullptr){
        //TODO: throw exception
    }
}

void Model::setViewPtr(shared_ptr<View> view_ptr) { 
    this->view_ptr = view_ptr;
}

void Model::go() { 
    auto it = agentsVec.begin();
    
    while(it != agentsVec.end()){
        (*it)->go();
        view_ptr->update_location((*it)->getName(), (*it)->getLocation());
        it++;
    }
}




