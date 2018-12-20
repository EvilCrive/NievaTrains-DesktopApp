#include <iostream>

class Puntatore{
public:
  int* punt;
};

int main(){
  Puntatore x, y;
  x.punt=new int(8);
  y=x;
  std:: cout<<*(y.punt)<<std::endl;
  *(y.punt)=3;
  std:: cout<<*(x.punt)<<std::endl;
}
 
