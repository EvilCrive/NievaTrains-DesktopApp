#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <math.h>

class Point
{
private:
    double x, y, z;
public:
    Point();//inzializza a origine
    Point(double,double,double);
    void negate();
    double norm() const;
    void print(char =' ') const;
};

#endif // POINT_H
