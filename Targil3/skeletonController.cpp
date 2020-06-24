#include "skeletonController.h"

Controller::Controller(){}

Controller::~Controller() {}

void Controller::run() {
    view_ptr.reset(new View);
    while(true){
        string strLine, firstWord, secondWord;
        stringstream ssLine;
        
        /*reset string stream*/
        ssLine.str("");
        ssLine.clear();
        getline(cin, strLine);
        ssLine.str(strLine);
        getline(ssLine, firstWord, ' ');
        
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
            //TODO: check if already exists
            createValidation(strLine);
            
//            Model::getInstance()->addAgent();
            
        }
        else {/*case where the first word is an agent's name*/
            //TODO: check if secont word is a name of existing agent
            Model::getInstance()->findAgentByName(firstWord); /*//TODO: throws exception if not found*/
            
            getline(ssLine, secondWord, ' ');
            if(secondWord == "course"){
                
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
