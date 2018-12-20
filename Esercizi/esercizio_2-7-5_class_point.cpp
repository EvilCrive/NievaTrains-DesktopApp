#include <iostream>
#include <math.h>

class Point{
private:
  int x, y, z;
public:
  Point(int a,int b,int c);
  Point Negate();
  int Norm() const;
  void Print() const;
};

Point::Point(int a=0, int b=0, int c=0): x(a), y(b), z(c) {}

Point Point::Negate() {
  x=-x;
  y=-y;
  z=-z;
  return *this;
}

void Point::Print() const
{
  std::cout<<"Le coordinate del punto sono: "<<std::endl<<"x:"<<x<<" y: "<<y<<" z:"<<z<<std::endl;
}

int Point::Norm() const {
  return sqrt(x*x+y*y+z*z);
	       
}


int main(){
  int g,h,i;
  Point alfa;
  std::cout<<"Dammi i tre punti"<<std::endl;
  std::cin>>g>>h>>i;
  std::cout<<"Punto di default"<<std::endl;
  alfa.Print();
  Point punto(g,h,i);
  std::cout<<"Punto definito da te"<<std::endl;
  punto.Print();
  (punto.Negate()).Print();
  std::cout<<punto.Norm()<<std::endl<<"FINE"<<std::endl;
}
