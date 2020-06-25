#include "Geometry.h"
#include <cmath>
#include <ctgmath>
const double pi = 2. * atan2(1., 0.);
double to_radians(double theta_d)
{
	return theta_d * pi / 180.0;
}

double to_degrees(double theta_r)
{
	return theta_r * 180.0 / pi;
}
Point polarToCartesian(const double& radius , const double& theta){
    double x,y;
    double convertedTheta = fmod((360 - theta + 90), 360); /*so 0 will be north*/
    double radianTheta = to_radians(convertedTheta);
    
    /*fix weird behaviour of exactly 0, 90, 180, 270*/
    if ((radianTheta == to_radians(90)) || (radianTheta == to_radians(270)))
        x = 0;
    else if (radianTheta == to_radians(0))
        x = radius * 1;
    else if (radianTheta == to_radians(180))
        x = radius * -1;
    else
        x = radius * cos(radianTheta);
    
    if (radianTheta == to_radians(270))
        y = radius * -1;
    else if (radianTheta == to_radians(90))
        y = radius * 1;
    else if ((radianTheta == to_radians(180)) || (radianTheta == to_radians(0)))
        y = 0;
    else
        y = radius * sin(radianTheta);
    
    Point retVal(x,y);
    return retVal;
}

pair<double,double>cartesianToPolar(const Point& point){
    double r,t;
    r = sqrt(pow(point.x,2) + pow(point.y,2)) ;
    if(point.x != 0){/*to avoid dividing by 0*/
        t = atan(point.y / point.x);
    }
    else{/*point.x is 0 go in "Straight" line */
        if(point.y>0)
            t = 90;/*"go above x axis"*/
        else
            t = 270;/*"go below x axis"*/
    }
    /*adjusting the value of t*/
    if((point.x<0 && point.y>0) || (point.x<0 && point.y<0))/*in the second or the third Quadrant*/
        t+=180;
    if(point.x>0 && point.y<0)/*if in the forth Quadrant*/
        t+=360;
    return make_pair(r,t);
}

// construct a Cartesian_vector from a Polar_vector
Cartesian_vector::Cartesian_vector(const Polar_vector& pv) {
	delta_x = pv.r * cos(pv.theta);
	delta_y = pv.r * sin(pv.theta);
}
Cartesian_vector::Cartesian_vector()
{
	delta_x = 0.0;
	delta_y = 0.0;
}
void Cartesian_vector::operator=(const Polar_vector& pv)
{
	delta_x = pv.r * cos(pv.theta);
	delta_y = pv.r * sin(pv.theta);
}
// construct a Polar_vector from a Cartesian_vector
Polar_vector::Polar_vector(const Cartesian_vector& cv) {
	r = sqrt((cv.delta_x * cv.delta_x) + (cv.delta_y * cv.delta_y));
	/* atan2 will return a negative angle for Quadrant III, IV, must translate to I, II */
	theta = atan2(cv.delta_y, cv.delta_x);
	if (theta < 0.)
		theta = 2. * pi + theta; // normalize theta positive
}
Polar_vector::Polar_vector()
{
	r = 0.0;
	theta = 0.0;
}
void Polar_vector::operator=(const Cartesian_vector& cv)
{
	r = sqrt((cv.delta_x * cv.delta_x) + (cv.delta_y * cv.delta_y));
	/* atan2 will return a negative angle for Quadrant III, IV, must translate to I, II */
	theta = atan2(cv.delta_y, cv.delta_x);
	if (theta < 0.)
		theta = 2. * pi + theta; // normalize theta positive
}

Point::Point(double x, double y) : x(x), y(y)
{
}

Point::Point()
{
	x = 0.0;
	y = 0.0;
}

void Point::print() const
{
	cout << setprecision(2) << "(" << x << ", " << y << ")";
}

bool Point::operator==(const Point & rhs)
{
	return x == rhs.x && y == rhs.y;
}

//bool Point::operator>=(const Point& rhs){
////    return (y >= rhs.y && x>=rhs.x);
//    if ((int)y == (int)rhs.y){ /*cast to int to floor to nearest integer(just for display)*/
//        if ((int)x >= (int)rhs.x)
//            return true;
//    }
//    return false;
//}
//
//bool Point::operator<=(const Point& rhs){
//    //    return (y >= rhs.y && x>=rhs.x);
//    if ((int)y == (int)rhs.y){ /*cast to int to floor to nearest integer(just for display)*/
//        if ((int)x <= (int)rhs.x)
//            return true;
//    }
//    return false;
//}
