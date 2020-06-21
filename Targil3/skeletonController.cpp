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
        
    }
    else if(firstWord == "size"){
        
    }
    else if(firstWord == "zoom"){
        
    }
    else if(firstWord == "pen"){
        
    }
    else if(firstWord == "show"){
        
    }
    else if(firstWord == "create"){
        
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
