#include <iostream>
#include "point.h"
using std::cout;
using std::endl;

int main()
{
    Point primo;
    Point secondo(1,2,3);
    Point terzo(3,2,1);
    Point quattro(4,4,4);
    cout<<"Class Point: testing\n\n";
    primo.print('1');
    secondo.print('2');
    terzo.print('3');
    quattro.print('4');
    cout<<"\npunto 2 negated\n";
    double norm1=secondo.norm();
    secondo.negate();
    secondo.print();
    double norm2=secondo.norm();
    double norm3= terzo.norm();
    cout<<"\nNorm: Distanza da punto 2 a origine, Distanza da punto2 negated a origine; e dal punto 3 e dal punto 4: \n"<<norm1<<" , "<<norm2<<" ,"<<norm3<<" , "<<(quattro.norm())<<"\n\n";
    return 0;
}

/**
    Point();//inzializza a origine
    Point(double,double,double);
    void negate();
    double norm() const;
    void print() const;
*/
