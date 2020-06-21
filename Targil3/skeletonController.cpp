#include "skeletonController.h"

void func(string commandVec){
    if(commandVec == "default"){
        if(commandVec.size()!=1){
            //TODO: throw exception (to many arguments)
        }
    }
    else if(commandVec == "size"){
        if(commandVec.size()!=2)
            //TODO: throw exception (to many arguments)
            try {
                int x = intValidation(commandVec);
            }
        catch (...) {
            
        }
    }
    else if(commandVec == "zoom"){
        
    }
    else if(commandVec == "pen"){
        
    }
    else if(commandVec == "show"){
        
    }
    else if(commandVec == "create"){
        
    }
    else if(true){//TODO: check if commandVec[0} is a name of existing agent
        if(commandVec == "course"){
            
        }
        else if(commandVec == "position"){
            
        }
        else if(commandVec == "destination"){
            
        }
        else if(commandVec == "position") {
            
        }
        else if(commandVec == "stop") {
            
        }
        else if(commandVec == "attack") {
            
        }
    }
    
}
