#ifndef View_h
#define View_h

#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include "Geometry.h"

enum {MARKS_SPACE=3};

/*a class to sort the objects according to the map drawing order*/
struct classcomp {
    bool operator() (const pair<Point, string>& lhs, const pair<Point, string>& rhs) const{
        if (lhs.first.y > rhs.first.y) /*larger y's go first*/
            return true;
        else if (lhs.first.y == rhs.first.y){
            if (lhs.first.x < rhs.first.x) /*same y: smaller x's go first*/
                return true;
            else
                return false;
        }
        else
            return false;
    }
};

class View {
public:
	View();
    ~View();
    /*no need for operator=, copy c'tor and move c'tor- only one instance in the program*/
	
	/*Saves the supplied name and location for future use in a draw() call.
	If the name is already present, the new location replaces the previous one*/
	void update_location(const string& name, const Point& location);

	/*prints out the current map*/
	void draw() const;

	/*Modifies the display parameters:*/
	/*If the size is out of bounds will throw excpt*/
	void set_size(int size_);
	
	/*If scale is not positive, will throw excpt*/
	void set_scale(double scale_);
	
	/*Any values are legal for the origin*/
	void set_origin(Point origin_);
	
	/*Sets the parameters to the default values*/
	void set_defaults();
    
    /* helper functions */
    /*check if current location is an empty cell or not*/
    bool checkToPrint(const Point& currentLocation, const Point& objectLocation) const;
    /*check if a given object is in bounds of the current map*/
    bool checkInBounds(const Point& objectLocation, const int& yBoundUp, const int& xBoundRight) const;
    
private:
    int size;
    double scale;
    Point origin;
    set<pair<Point, string>, classcomp> objectsSet;
};

#endif /* View_h */
