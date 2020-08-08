#include "model.h"
#include <iostream>
using std::cout;
using std::string;

void Model::print(unsigned int i) const
{
    int numero=i+1;
    cout<<"TRENO "<<numero<<": \n\n";
    list[i]->print();
    cout<<"\n\n\n";
}

void Model::push_end(Treno *t)
{
    list.push(&t);
}
