#include "Model.h"

shared_ptr<Model> Model::inst = nullptr;

shared_ptr<Model> Model::getInstance() {
    if (inst == nullptr)
        inst.reset(new Model);
    return inst;
}

Model::Model()
:time(0), view_ptr(new View){}

Model::~Model() {}

/* init files functions */
void Model::farmInit(const string &fileName) {
    ifstream file(fileName);
    if(!file){
        throw xFileException("Can't open file");
    }
    string strLine , tmpPointStr;
    stringstream ssLine;
    Point location;
    int inventory , production;
    vector<string> vec;
    while(!file.eof()){
        getline(file,strLine);
        vec = tokenizeLine(strLine);/*tokenize with ' ' del.*/
        if(vec.size() == 5)
        {
            try{/*do substr(0,vec[0].size()-1) to remove the ',' from the end of the string*/
                nameValidation(vec[0].substr(0,vec[0].size()-1));
                tmpPointStr=vec[1];
                tmpPointStr.append(vec[2].substr(0,vec[2].size()-1));
                location = pointValidation(tmpPointStr);
                inventory = intValidation(vec[3].substr(0,vec[3].size()-1));
                production = intValidation(vec[4]);
            }
            catch (const stringstream& ss) {
                throw xFileException("Wrong input in the files");
            }
        }
        else
            throw xFileException("Wrong input in the files");
        addStructure(vec[0].substr(0, vec[0].size()-1), location, inventory, FARM, production);
    }
    file.close();
}

void Model::castleInit(const string &fileName) {
    ifstream file(fileName);
    if(!file){
        throw xFileException("Can't open file");
    }
    string strLine , tmpPointStr;
    stringstream ssLine;
    Point location;
    int inventory;
    vector<string> vec;
    while(!file.eof()){
        getline(file,strLine);
        vec = tokenizeLine(strLine);/*tokenize with ' ' del.*/
        if(vec.size() == 4)
        {
            try{/*do substr(0,vec[0].size()-1) to remove the ',' from the end of the string*/
                nameValidation(vec[0].substr(0,vec[0].size()-1));
                tmpPointStr=vec[1];
                tmpPointStr.append(vec[2].substr(0,vec[2].size()-1));
                location = pointValidation(tmpPointStr);
                inventory = intValidation(vec[3]);
            }
            catch (const stringstream& ss) {
                throw xFileException("Wrong input in the files");
            }
        }
        else
            throw xFileException("Wrong input in the files");
        addStructure(vec[0].substr(0,vec[0].size()-1),location,inventory,CASTLE,-1);
    }
    file.close();
}

/*adding and finding Sim_objecs*/
void Model::addAgent(const vector<std::string> &vec) {
    string newName = vec[1];
    string type = vec[2];
    
    try{
        auto it = agentsVec.begin();
        while (it != agentsVec.end()) { /*check if the name already exists*/
            if ((*it)->getName() == newName)
                throw xInvalidArgument("An agent with this name already exists");
            it++;
        }
        if (type == "Knight"){
            string structureName = vec[3];
            Point newLocation = checkExistingStructure(structuresVec, structureName);/*validate structure name*/
            
            agentsVec.emplace_back(shared_ptr<Agent>(new Knight(newName, newLocation))); /*add to agents vector*/
            shared_ptr<Knight> newKnight = dynamic_pointer_cast<Knight>(agentsVec.back());
            for (auto it=structuresVec.begin() ; it!=structuresVec.end() ; it++){/*add all structures to Knight's queue*/
                newKnight->addToQueue((*it));
            }
            view_ptr->update_location(newName, newLocation);/*send new agent location to the View*/
        }
        else if (type == "Peasant"){
            Point newLocation = pointValidation(vec[3]);
            agentsVec.emplace_back(shared_ptr<Agent>(new Peasant(newName, newLocation))); /*add to agents vector*/
            view_ptr->update_location(newName, newLocation);/*send new agent location to the View*/
        }
        else {/*type == "Thug"*/
            Point newLocation = pointValidation(vec[3]);
            agentsVec.emplace_back(shared_ptr<Agent>(new Thug(newName, newLocation))); /*add to agents vector*/
            view_ptr->update_location(newName, newLocation);/*send new agent location to the View*/
        }
    }catch(const xNoSuchStructure& e){
        e.what();
    }catch(const xInvalidArgument& e){
        e.what();
    }
}

void Model::addStructure(const string& name, const Point& location, const int& inventory, const int& type, const int& productionRate){
    //TODO: check if exists??
    /*all validations are made in init functions*/
    switch (type) {
        case FARM:
            structuresVec.emplace_back(shared_ptr<Structure>(new Farm(name, location, inventory, productionRate)));/*add to structures vector*/
            break;
        
        case CASTLE:
            structuresVec.emplace_back(shared_ptr<Structure>(new Castle(name, location, inventory)));/*add to structures vector*/
            break;
        default:
            break;
    }
    view_ptr->update_location(name, location);/*send new structure location to the View*/
}

const int& Model::getTime(){
    return time;
}

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
        it++;
    }
    throw xNoSuchStructure();
}

/* sending command to agents */
void Model::updateAgentDegAndSpeed(const vector<shared_ptr<Agent> >::const_iterator &agent, const pair<int, int> &degAndSpeed) {
    shared_ptr<Knight> knightPtr = dynamic_pointer_cast<Knight>((*agent));
    if (knightPtr != nullptr){
        knightPtr->updateDeg(degAndSpeed.first);
        return;
    }
    
    shared_ptr<Thug> ThugPtr = dynamic_pointer_cast<Thug>((*agent));
    if (ThugPtr != nullptr){
        ThugPtr->updateDegAndSpeed(degAndSpeed);
        return;
    }
}

void Model::changeState(const vector<shared_ptr<Agent> >::const_iterator& agent, const int& state){
    (*agent)->setState(state);
//    (*agent)->setDestinationName("");
}

void Model::status() const{
    auto structuresIterator = structuresVec.begin();
    while (structuresIterator != structuresVec.end()){
        (*structuresIterator)->broadcast_current_State();
        structuresIterator++;
    }
    
    auto agentsIterator = agentsVec.begin();
    while (agentsIterator != agentsVec.end()){
        (*agentsIterator)->broadcast_current_State();
        agentsIterator++;
    }
}

void Model::go() {
    time++;
    
    auto structuresIterator = structuresVec.begin();
    while (structuresIterator != structuresVec.end()){
        (*structuresIterator)->update();
        structuresIterator++;
    }

    auto agentsIterator = agentsVec.begin();
    while(agentsIterator != agentsVec.end()){
        (*agentsIterator)->update();
        view_ptr->update_location((*agentsIterator)->getName(), (*agentsIterator)->getLocation());
        agentsIterator++;
    }
}

shared_ptr<View> Model::getViewPtr() const{
    return view_ptr;
}
