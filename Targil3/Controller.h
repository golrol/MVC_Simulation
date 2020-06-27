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
    
    void setViewPtr(shared_ptr<View> view_ptr);
    
    
	void run();

private:
    shared_ptr<View> view_ptr;
    
};

#endif /* Controller_h */