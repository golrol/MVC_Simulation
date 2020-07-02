#ifndef Controller_h
#define Controller_h
#include "View.h"
#include "Validation.h"
#include "Model.h"
#include "Geometry.h"


/* Controller
This class is responsible for controlling the Model and View according to interactions
with the user.
*/

class Controller {
public:	
	Controller();
	~Controller();
    /*no need for operator=, copy c'tor and move c'tor- only one instance in the program*/
    
    /*get command from user, validate and send to Model/View to execute*/
	void run();

private:
    shared_ptr<View> view_ptr;
    
};

#endif /* Controller_h */
