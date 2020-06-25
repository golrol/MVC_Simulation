#ifndef skeleton_View_h
#define skeleton_View_h

#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include "Geometry.h"

enum {MARKS_SPACE=3};
/* View object
The View class encapsulates the data and functions needed to generate the map display, and control its properties. It has a "memory" for the names and locations of the to-be-plotted objects.

Usage: 
1. Call the update_location function with the name and position of each object to be plotted. If the object is not already in the View's memory, it will be added along with its location. If it is already present, its location will be set to the supplied location. If a single object changes location, its location can be separately updated with a call to update_location. 

2. Call the update_remove function with the name of any object that should no longer be plotted. This must be done *after* any call to update_location that has the same object name since update_location will add any object name supplied.

3. Call the draw function to print out the map.

4. As needed, change the origin, scale, or displayed size of the map with the appropriate functions. Since the view "remembers" the previously updated information, immediately calling the draw function will print out a map showing the previous objects using the new settings.
*/

struct classcomp {
    bool operator() (const pair<Point, string>& lhs, const pair<Point, string>& rhs) const{
        if (lhs.first.y > rhs.first.y)
            return true;
        else if (lhs.first.y == rhs.first.y){
            if (lhs.first.x < lhs.first.x)
                return true;
            else if (lhs.first.x == lhs.first.x)
                return lhs.second == lhs.second;
            else
                return false;
        }
        else{
            return false;
        }
    }
};

class View {
public:
	// default ctor: sets the default size, scale, and origin, outputs constructor message
	View(); 
    // dtor
    ~View(){}
	
	// Saves the supplied name and location for future use in a draw() call
	// If the name is already present,the new location replaces the previous one.
	void update_location(const string& name, const Point& location);
	
	// Removes the name and its location; no error if the name is not present.
	void update_remove(const string& name);

	// prints out the current map
	void draw() const;

	// Modifies the display parameters:
	// If the size is out of bounds will throw excpt
	void set_size(int size_);
	
	// If scale is not positive, will throw excpt
	void set_scale(double scale_);
	
	// Any values are legal for the origin
	void set_origin(Point origin_);
	
	// Sets the parameters to the default values
	void set_defaults();
	
	/*
		YOUR EXTRA DECLARATIONS GO HERE
	*/
    set<pair<Point, string> >::const_iterator findByName(const string& name) const;/*helper*/
    
private:
    int size;
    double scale;
    Point origin;
    set<pair<Point, string>, classcomp> objectsSet;
    
};

#endif /* skeleton_View_h */
