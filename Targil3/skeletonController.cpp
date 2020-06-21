#include "skeletonController.h"

Controller::Controller()
:view_ptr(new View), model_ptr(new Model){}

Controller::~Controller() {}

void Controller::run() {
    //TODO: create a View instance.
    string strLine, firstWord, secondWord;
    stringstream ssLine;
    
    getline(cin, strLine);
    ssLine.str(strLine);
    getline(ssLine, firstWord, ' ');
    
    if(firstWord == "default"){
        defaultValidation(strLine);
        view_ptr->set_defaults();
    }
    else if(firstWord == "size"){
        view_ptr->set_size(sizeValidation(strLine));
    }
    else if(firstWord == "zoom"){
        view_ptr->set_scale(zoomValidation(strLine));
    }
    else if(firstWord == "pan"){
        view_ptr->set_origin(panValidation(strLine));
    }
    else if(firstWord == "show"){
        showValidation(strLine);
        view_ptr->draw();
    }
    else if(firstWord == "create"){
        //TODO: check if already exists
        createValidation(strLine);
        
    }
    else {/*case where the first word is an agent's name*/
        //TODO: check if secont word is a name of existing agent
        model_ptr->findAgentByName(firstWord);/*//TODO: throws exception if not found*/
        
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
