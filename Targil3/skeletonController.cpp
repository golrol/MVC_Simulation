#include "skeletonController.h"

Controller::Controller(){}

Controller::~Controller() {}

void Controller::run() {
    view_ptr.reset(new View);
    Model::getInstance()->setViewPtr(view_ptr);
    while(true){
        string strLine, firstWord, secondWord;
        stringstream ssLine;
        
        /*reset string stream*/
        ssLine.str("");
        ssLine.clear();
        getline(cin, strLine);
        ssLine.str(strLine);
        getline(ssLine, firstWord, ' ');
        
        if(firstWord == "go"){
            Model::getInstance()->go();
        }
        
        if(firstWord == "default"){
            try{
                defaultValidation(strLine);
            }catch(const CommandException& e){
                e.what();
            }
            view_ptr->set_defaults();
        }
        else if(firstWord == "size"){
            try{
                view_ptr->set_size(sizeValidation(strLine));
            }catch(const CommandException& e){
                e.what();
            }
        }
        else if(firstWord == "zoom"){
            try{
                view_ptr->set_scale(zoomValidation(strLine));
            }catch(const CommandException& e){
                e.what();
            }
        }
        else if(firstWord == "pan"){
            try{
                view_ptr->set_origin(panValidation(strLine));
            }catch(const CommandException& e){
                e.what();
            }
        }
        else if(firstWord == "show"){
            try{
                showValidation(strLine);
            }catch(const CommandException& e){
                e.what();
            }
            view_ptr->draw();
        }
        else if(firstWord == "create"){
            try{
                vector<string> vecLine = createValidation(strLine);
                Model::getInstance()->addAgent(vecLine);
            }catch(const CommandException& e){
                e.what();
            }
        }
        else if(firstWord == "quit"){
            break;
        }
        else {/*case where the first word is an agent's name*/
            getline(ssLine, secondWord, ' ');
            if(secondWord == "course"){
                pair<double,double> degAndSpeed = courseValidation(strLine);
                
                vector<shared_ptr<Agent>>::const_iterator agent = Model::getInstance()->findAgentByName(firstWord);
                Model::getInstance()->updateAgentDegAndSpeed(agent, degAndSpeed);
                
                
            }
            else if(secondWord == "position"){
                
            }
            else if(secondWord == "destination"){
                
            }
            else if(secondWord == "position") {
                
            }
            else if(secondWord == "stop") {
                
            }
            else if(secondWord == "attack") {
                
            }
        }
        
    }
}
