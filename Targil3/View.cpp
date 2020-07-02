#include "View.h"

/* class View */
View::View()
:size(25), scale(2), origin(0, 0){}

View::~View(){}

void View::update_location(const string &name, const Point& location) {
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

void View::draw() const {
    int i, j;
    int yMarks = origin.y + (size * scale) - scale; /*highest mark number to print*/
    int emptyLines = (size-1) % MARKS_SPACE; /*leading lines without marks*/
    int yBoundUp = yMarks;/*highest y value*/
    int xBoundRight = origin.x + (size * scale) - scale; /*highest x value*/
    auto setItarator = objectsSet.begin();
    
    /*print headline*/
    cout << "Display size: " << size << ", scale: " << scale << ", origin: ";
    origin.print();
    cout << endl;
    
    for (i=0 ; i<size ; i++){/*print lines with marks*/
        if (i % 3 == emptyLines){ /*need to print a mark*/
            //TODO: magic numbers
            //TODO: make infinity compatible
            /*print according to number of digits*/
            if (yMarks > -1 && yMarks < 10)
                cout << "  " << yMarks << " ";
            else if ((yMarks > 9 && yMarks < 100) || (yMarks > -10 && yMarks < 0))
                cout << " " << yMarks << " ";
            else if ((yMarks > -100 && yMarks < -9) || (yMarks > 99 && yMarks < 1000))
                cout << yMarks << " ";
        }
        else{/*no need to print a mark*/
            cout << "    ";
        }
        j=size;
        while(j--){
            /*get location in the "world" from i and j*/
            Point currentLocation(origin.x + (size-j)*scale - scale, origin.y + size*scale - i*scale - scale);
            
            if (setItarator != objectsSet.end()){
                /*skip if object is out of bounds*/
                while (setItarator != objectsSet.end() && checkInBounds((*setItarator).first, yBoundUp, xBoundRight))
                    setItarator++;
                
                /*check if next object's location is current location*/
                if (setItarator != objectsSet.end() && checkToPrint(currentLocation, (*setItarator).first)){
                    cout << (*setItarator).second.substr(0, 2);/*take only first two letters*/
                    
                    /*skip all others in the same place*/
                    while (checkToPrint(currentLocation, (*setItarator).first) && setItarator != objectsSet.end())
                        setItarator++;
                }
                else{ /*empty cell, no objects in that cell*/
                    if (currentLocation.x < xBoundRight)/*don't print space at the end*/
                        cout << ". ";
                    else
                        cout << ".";
                }
                
            }
            else{/*empty cell, no more objects*/
                if (currentLocation.x < xBoundRight) /*don't print space at the end*/
                    cout << ". ";
                else
                    cout << ".";
            }
        }
        cout << endl;
        yMarks = yMarks - scale; /*fix for the next printing of a mark*/
    }
    
    /* print x marks */
    int numberOfMarks ;
    numberOfMarks = ceil((double)size / (double)MARKS_SPACE);
    int xMarks = origin.x;/*smallest x value==first mark*/
    
    /*print first mark according to number of digits*/
    if (xMarks > -1 && xMarks < 10)
        cout << "    " << xMarks;
    else if ((xMarks > 9 && xMarks < 100) || (xMarks > -10 && xMarks < 0))
        cout << "   " << xMarks;
    else if ((xMarks > -100 && xMarks < -9) || (xMarks > 99 && xMarks < 1000))
        cout << "  " << xMarks;
    
    xMarks += (scale*MARKS_SPACE); /*update the next mark to print*/
    numberOfMarks--;
    while (numberOfMarks--){/*print all the other marks according to number of digits*/
        if (xMarks > -1 && xMarks < 10)
            cout << "     " << xMarks;
        else if ((xMarks > 9 && xMarks < 100) || (xMarks > -10 && xMarks < 0))
            cout << "    " << xMarks;
        else if ((xMarks > -100 && xMarks < -9) || (xMarks > 99 && xMarks < 1000))
            cout << "   " << xMarks;
        
        xMarks += (scale*MARKS_SPACE); /*update the next mark to print*/
    }
    cout << endl;
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

/* helper functions */
bool View::checkToPrint(const Point& currentLocation, const Point& objectLocation) const{
    if ((int)currentLocation.y <= (int)objectLocation.y && currentLocation.x <= objectLocation.x && currentLocation.x+scale == objectLocation.x)
        return false;
    return ((int)currentLocation.y <= (int)objectLocation.y && currentLocation.x <= objectLocation.x && currentLocation.x+scale >= objectLocation.x);
}
bool View::checkInBounds(const Point& objectLocation, const int& yBoundUp, const int& xBoundRight) const{
    if (objectLocation.x > xBoundRight || objectLocation.x < origin.x || objectLocation.y > yBoundUp || objectLocation.y < origin.y)
        return true;
    return false;
}
