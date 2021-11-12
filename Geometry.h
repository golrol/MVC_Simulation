#ifndef Geometry_h
#define Geometry_h

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <ctgmath>
#include <memory>
using namespace std;

/* class Point */
typedef struct Point {
	double x;
	double y;
	Point(double x, double y);
	Point();
    ~Point();
    Point(const Point& other);
    Point(Point&& other) noexcept;
    Point& operator=(const Point& rhs);
    Point& operator=(Point&& rhs) noexcept;
	void print() const;
	bool operator==(const Point& rhs);
    Point& operator+(const Point& rhs);
} Point;

/* helper functions */
double to_radians(double theta_d);
double to_degrees(double theta_r);
Point polarToCartesian(const double& radius , const double& teta);

double findDistance(const Point& p1, const Point& p2);

#endif /* Geometry_h */
