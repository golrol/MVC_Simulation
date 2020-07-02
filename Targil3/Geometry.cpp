#include "Geometry.h"

const double pi = 2. * atan2(1., 0.);

/* class Point */
Point::Point(double x, double y) : x(x), y(y)
{}

Point::Point()
:x(0.0), y(0.0)
{}

Point::~Point(){}

Point::Point(const Point &other)
:x(other.x), y(other.y){}

Point::Point(Point &&other) noexcept
:x(other.x), y(other.y){
    other.x = 0.0;
    other.y = 0.0;
}

Point &Point::operator=(const Point &rhs) {
    if (*this == rhs)
        return *this;
    this->x = rhs.x;
    this->y = rhs.y;
    return *this;
}

Point &Point::operator=(Point &&rhs) noexcept{
    if (*this == rhs)
        return *this;
    this->x = rhs.x;
    this->y = rhs.y;
    rhs.x = 0.0;
    rhs.y = 0.0;
    return *this;
}

void Point::print() const {
	cout << setprecision(2) << "(" << x << ", " << y << ")";
}

bool Point::operator==(const Point & rhs) {
	return x == rhs.x && y == rhs.y;
}

Point& Point::operator+(const Point& rhs){
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

/* helper functions */
double to_radians(double theta_d) {
    return theta_d * pi / 180.0;
}

double to_degrees(double theta_r) {
    return theta_r * 180.0 / pi;
}

Point polarToCartesian(const double& radius , const double& theta){
    /*get radius and angle, return a Point relative to (0, 0)*/
    double x,y;
    double convertedTheta = fmod((360 - theta + 90), 360); /*so 0 will be north*/
    double radianTheta = to_radians(convertedTheta);
    
    /*fix weird behaviour of exactly 0, 90, 180, 270*/
    if ((radianTheta == to_radians(90)) || (radianTheta == to_radians(270)))
        x = radius * 0;
    else if (radianTheta == to_radians(0))
        x = radius * 1;
    else if (radianTheta == to_radians(180))
        x = radius * -1;
    else /*radianTheta == any other angle*/
        x = radius * cos(radianTheta);
    
    if (radianTheta == to_radians(270))
        y = radius * -1;
    else if (radianTheta == to_radians(90))
        y = radius * 1;
    else if ((radianTheta == to_radians(180)) || (radianTheta == to_radians(0)))
        y = radius * 0;
    else /*radianTheta == any other angle*/
        y = radius * sin(radianTheta);
    
    Point retVal(x,y);
    return retVal;
}

double findDistance(const Point& p1, const Point& p2){
    double dx = (p2.x - p1.x);
    double dy = (p2.y - p1.y);
    return sqrt((dx * dx) + (dy * dy));
}
