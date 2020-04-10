#include "point.h"

Point::Point():x(0),y(0),z(0){}

Point::Point(double a, double b, double c):x(a),y(b),z(c){}

void Point::negate()
{
    x*=-1;
    y*=-1;
    z*=-1;
}

double Point::norm() const
{
    double norm=(x*x)+(y*y)+(z*z);
    return sqrt(norm);

}

void Point::print(char frase) const
{
    if(frase!=' ')  std::cout<<"Le coordinate del punto "<<frase<<" sono : ("<<x<<","<<y<<","<<z<<") "<<std::endl;
    else    std::cout<<"Le coordinate del punto sono : x="<<x<<" y="<<y<<" z="<<z<<std::endl;
}


