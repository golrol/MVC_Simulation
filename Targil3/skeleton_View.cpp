#include "skeleton_View.h"
/* *** Use this function to calculate the subscripts for the cell. */

// Calculates the cell subscripts corresponding to the supplied location parameter, 
// using the current size, scale, and origin of the display. 
// This function assumes that origin is a  member variable of type Point, 
// scale is a double value, and size is an integer for the number of rows/columns 
// currently being used for the grid.
// Returns true if the location is within the grid, false otherwise
//bool View::get_subscripts(int &ix, int &iy, Point location) const
//{
//	// adjust with origin and scale
//	Cartesian_vector subscripts = (location - origin) / scale;
//	// Truncate coordinates to appropriate integer after taking the floor.
//	// The floor function will produce a floating point value that is
//	// the greatest integer that is smaller than the argument, even for negative values.
//	// So - 0.05 is floored to -1., which will be outside the array.
//	ix = int(floor(subscripts.delta_x));
//	iy = int(floor(subscripts.delta_y));
//	// if out of range, return false
//	if ((ix < 0) || (ix >= size) || (iy < 0) || (iy >= size)) {
//		return false;
//		}
//	return true;
//}

/*
	YOUR ADDITIONAL IMPLEMENTATIONS GO HERE
*/

set<pair<Point, string> >::const_iterator View::findByName(const string& name) const{
    auto setIterator = objectsSet.begin();
    string shortName = name.substr(0, 2);
    
    for(; setIterator != objectsSet.end() ; setIterator++){
        if ((*setIterator).second == shortName)
            return setIterator;
    }
    return objectsSet.end();
}



void View::draw() const {
    int i, j;
    int yMarks = origin.y + (size * scale) - scale; /*highest number to print*/
    int emptyLines = (size-1) % MARKS_SPACE;
    auto setItarator = objectsSet.begin();
    
    for (i=0 ; i<size ; i++){/*print lines with marks*/
        if (i % 3 == emptyLines){
            //TODO: magic numbers
            if (yMarks > -1 && yMarks < 10)
                cout << "  " << yMarks << " ";
            else if ((yMarks > 9 && yMarks < 100) || (yMarks > -10 && yMarks < 0))
                cout << " " << yMarks << " ";
            else if ((yMarks > -100 && yMarks < -9) || (yMarks > 99 && yMarks < 1000))
                cout << yMarks << " ";
        }
        else{
            cout << "    ";
        }
        j=size;
        while(j--){
            Point currentLocation(origin.x + (size-j)*scale - scale, origin.y + size*scale - i*scale - scale);
            if (setItarator != objectsSet.end()){
                if (currentLocation >= (*setItarator).first){
                    cout << (*setItarator).second.substr(0, 2);/*take only first two letters*/
                    setItarator++;
                }
                else{
                    cout << ". ";
                }
            }
            else
                cout << ". ";
        }
        cout << endl;
        yMarks = yMarks - scale;
    }
    int x ;
    x = size / MARKS_SPACE;
    int xMarks = origin.x;
    
    if (xMarks > -1 && xMarks < 10)
        cout << "    " << xMarks;
    else if ((xMarks > 9 && xMarks < 100) || (xMarks > -10 && xMarks < 0))
        cout << "   " << xMarks;
    else if ((xMarks > -100 && xMarks < -9) || (xMarks > 99 && xMarks < 1000))
        cout << "  " << xMarks;
    xMarks += (scale*MARKS_SPACE);
    //x--;
    while (x--){
        if (xMarks > -1 && xMarks < 10)
            cout << "     " << xMarks;
        else if ((xMarks > 9 && xMarks < 100) || (xMarks > -10 && xMarks < 0))
            cout << "    " << xMarks;
        else if ((xMarks > -100 && xMarks < -9) || (xMarks > 99 && xMarks < 1000))
            cout << "   " << xMarks;
        xMarks += (scale*MARKS_SPACE);
    }
    cout << endl;
}

View::View()
:size(25), scale(1), origin(0, 0){}

void View::update_location(const string &name, const Point& location) {
    //TODO: update existing.
    auto it = objectsSet.begin();
    while (it != objectsSet.end()){
        if ((*it).second == name){ /*updating existing agent's location*/
            objectsSet.erase(it);
            break;
        }
        it++;
    }
    objectsSet.insert(make_pair(location, name));
}

void View::update_remove(const string &name) {
    auto setIterator = findByName(name);
    
    if (setIterator != objectsSet.end())
        objectsSet.erase(setIterator);
}

void View::set_size(int size_) {
    this->size = size_;
}

void View::set_scale(double scale_) { 
    this->scale = scale_;
}

void View::set_origin(Point origin_) { 
    this->origin = origin_;
}

void View::set_defaults() { 
    this->size = 25;
    this->scale = 2;
    this->origin = Point(0,0);
}




