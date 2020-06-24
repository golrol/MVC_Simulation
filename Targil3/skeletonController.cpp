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
        
        try{
            if(firstWord == "status"){
                Model::getInstance()->status();
            }
            else if(firstWord == "go"){
                Model::getInstance()->go();
            }
            
            else if(firstWord == "default"){
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
                vector<string> vecLine = createValidation(strLine);
                Model::getInstance()->addAgent(vecLine);
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
                else
                    throw CommandException("wrong input");
            }
        }catch(const CommandException& e){
            e.what();
        }catch(const Model::xNoSuchAgent& e){
            e.what();
        }
    }
}
