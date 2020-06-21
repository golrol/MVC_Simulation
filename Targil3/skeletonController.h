#ifndef Controller_h
#define Controller_h


/* Controller
This class is responsible for controlling the Model and View according to interactions
with the user.
*/

class Controller {
public:	
	Controller();
	~Controller();

	// creates View object, runs the program by accepting user commands, then destroys View object
	void run();

private:
	View* view_ptr;
};

#endif /* Controller_h */
