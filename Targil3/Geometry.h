#ifndef Geometry_h
#define Geometry_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctgmath>
using namespace std;
// angle units conversion functions
double to_radians(double theta_d);
double to_degrees(double theta_r);

// class declarations
typedef struct Point {
	double x;
	double y;
	Point(double x, double y);
	Point();
	void print() const;
	bool operator==(const Point& rhs);
    Point& operator+(const Point& rhs);
//    bool operator>=(const Point& rhs);
//    bool operator<=(const Point& rhs);
} Point;

struct Polar_vector;
typedef struct Cartesian_vector {
	Cartesian_vector(const struct Polar_vector & pv);
	Cartesian_vector();
	void operator=(const struct Polar_vector & pv);
	double delta_x;
	double delta_y;
} Cartesian_vector;
typedef struct Polar_vector {
	Polar_vector(const Cartesian_vector & cv);
	Polar_vector();
	void operator=(const Cartesian_vector & cv);
	double r;
	double theta;
} Polar_vector;

/*----------------------------------------*/
Point polarToCartesian(const double& radius , const double& teta);
pair<double,double>cartesianToPolar(const Point& point);
//double getDegFromTwoPoints(const Point& p1, const Point& p2);
double findDistance(const Point& p1, const Point& p2);

#endif /* Geometry_h */
