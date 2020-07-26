#include "Controller.h"

Controller::Controller()
:view_ptr(Model::getInstance()->getViewPtr()) {}

Controller::~Controller() {}

void Controller::run() {
    while(true){
        cout << "Time " << Model::getInstance()->getTime() << ": Enter Command: ";
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
                statusValidation(strLine);
                Model::getInstance()->status();
            }
            else if(firstWord == "go"){
                goValidation(strLine);
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
            else if(firstWord == "exit"){
                break;
            }
            else {/*case where the first word is an agent's name*/
                getline(ssLine, secondWord, ' '); /*read the command*/
                
                if(secondWord == "course"){
                    /*find the existing agent*/
                    vector<shared_ptr<Agent> >::const_iterator agent = Model::getInstance()->findAgentByName(firstWord);
                    pair<double,double> degAndSpeed = courseValidation(strLine, (*agent)->getType()); /*validation*/
                    
                    Model::getInstance()->changeState(agent, MOVING_ON_COURSE); /*change state*/
                    Model::getInstance()->updateAgentDegAndSpeed(agent, degAndSpeed);/*update deg and speed for calculations*/
                }
                
                else if(secondWord == "destination"){
                    /*find the existing agent*/
                    vector<shared_ptr<Agent> >::const_iterator agent = Model::getInstance()->findAgentByName(firstWord);
                    string structureName = destinationValidation(strLine, (*agent)->getType());
                    vector<shared_ptr<Structure> >::const_iterator structure = Model::getInstance()->findStructureByName(structureName);
                    shared_ptr<Knight> knightPtr = dynamic_pointer_cast<Knight>((*agent));
                    knightPtr->destination(structureName, (*structure)->getLocation());
                    
                }
                else if(secondWord == "position") {
                    /*find the existing agent*/
                    vector<shared_ptr<Agent> >::const_iterator agent = Model::getInstance()->findAgentByName(firstWord);
                    pair<Point, double> destinationAndSpeed = positionValidation(strLine, (*agent)->getType());
                    (*agent)->setDestinationName(""); /*delete old destination if existed*/
                    if ((*agent)->getType() == KNIGHT)
                        dynamic_pointer_cast<Knight>((*agent))->position(destinationAndSpeed.first, (*agent)->getSpeed());
                    else if ((*agent)->getType() == THUG)
                        dynamic_pointer_cast<Thug>((*agent))->position(destinationAndSpeed.first, destinationAndSpeed.second);
                }
                else if(secondWord == "stop") {
                    stopValidation(strLine);
                    /*find the existing agent*/
                    vector<shared_ptr<Agent> >::const_iterator agent = Model::getInstance()->findAgentByName(firstWord);
                    (*agent)->setState(STOPPED);
                }
                else if(secondWord == "attack") {
                    /*find the existing agent*/
                    vector<shared_ptr<Agent> >::const_iterator agent = Model::getInstance()->findAgentByName(firstWord);
                    string peasantName = attackValidation(strLine);
                    /*find the peasant*/
                    vector<shared_ptr<Agent>>::const_iterator peasantToAttack = Model::getInstance()->findAgentByName(peasantName);
                    if ((*agent)->getType() != THUG)
                        throw xInvalidCommand("This agent doesn't support this command");
                    dynamic_pointer_cast<Thug>(*agent)->attack(*peasantToAttack);
                    Model::getInstance()->addAttckingThug(*agent);/*add the thug to the attacking queue*/
                }
                else if(secondWord == "start_working") {
                    /*find the existing agent*/
                    vector<shared_ptr<Agent> >::const_iterator agent = Model::getInstance()->findAgentByName(firstWord);
                    pair<string, string> famrmAndCastle = startWorkingValidation(strLine, (*agent)->getType());
                    vector<shared_ptr<Structure> >::const_iterator farm = Model::getInstance()->findStructureByName(famrmAndCastle.first);
                    if ((*farm)->getType() != FARM)
                        throw Model::xInvalidArgument("First structure isn't a farm");
                    vector<shared_ptr<Structure> >::const_iterator castle = Model::getInstance()->findStructureByName(famrmAndCastle.second);
                    if ((*castle)->getType() != CASTLE)
                        throw Model::xInvalidArgument("Second structure isn't a castle");
                    (*agent)->setDestination((*farm)->getLocation());
                    dynamic_pointer_cast<Peasant>((*agent))->startWorking(*farm, *castle);

                }
                else
                    throw xInvalidCommand("Wrong input");
            }
        }catch(const xInvalidCommand& e){
            e.what();
        }catch(const Model::xNoSuchAgent& e){
            e.what();
        }catch(const Model::xNoSuchStructure& e){
            e.what();
        }catch(const Model::xInvalidArgument& e){
            e.what();
        }
    }
}
