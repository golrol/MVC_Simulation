#ifndef Controller_h
#define Controller_h
#include "skeleton_View.h"
#include "Validation.h"
#include "Model.h"


/* Controller
This class is responsible for controlling the Model and View according to interactions
with the user.
*/

class Controller {
public:	
	Controller();
	~Controller();
    
    void setViewPtr(shared_ptr<View> view_ptr);
    
    
	void run();

private:
    shared_ptr<View> view_ptr;
    
};

#endif /* Controller_h */
