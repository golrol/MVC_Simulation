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
    throw xNoSuchAgent();
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
    string newName = vec[1];
    string type = vec[2];
    
    //TODO: check if already exists in this name.
    try{
        if (type == "Knight"){
            string structureName = vec[3];
            Point newLocation = checkExistingStructure(structuresVec, structureName);
            
            agentsVec.emplace_back(shared_ptr<Knight>(new Knight(newName, newLocation)));
            view_ptr->update_location(newName, newLocation);
        }
        else if (type == "Peasant"){
            Point newLocation = pointValidation(vec[3]);
            agentsVec.emplace_back(shared_ptr<Peasant>(new Peasant(newName, newLocation)));
            view_ptr->update_location(newName, newLocation);
        }
        else {/*type == "Thug"*/
            Point newLocation = pointValidation(vec[3]);
            agentsVec.emplace_back(shared_ptr<Agent>(new Thug(newName, newLocation)));
            view_ptr->update_location(newName, newLocation);
        }
    }catch(const xNoSuchStructure& e){
        e.what();
    }
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
        throw xInvalidArgument("Peasant doesn't support the 'course' command");
    }
}

void Model::setViewPtr(shared_ptr<View> view_ptr) { 
    this->view_ptr = view_ptr;
}

void Model::go() {
    time++;
    auto it = agentsVec.begin();
    
    while(it != agentsVec.end()){
        (*it)->go();
        view_ptr->update_location((*it)->getName(), (*it)->getLocation());
        it++;
    }
}


void Model::status() const{
    auto it = agentsVec.begin();
    
    while (it != agentsVec.end()){
        (*it)->broadcast_current_State();
        it++;
    }
}
