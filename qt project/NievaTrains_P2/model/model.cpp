#include "model.h"
#include <iostream>
using std::cout;
using std::string;

void Model::print(unsigned int i) const
{
    int numero=i+1;
    cout<<"TRENO "<<numero<<": \n";
    list[i]->print();
    cout<<"\n\n\n";
}

void Model::print_all() const
{
    for(unsigned int i=0; i<list.getSize();i++) print(i);
}

void Model::push_end(Treno *t)
{
    list.push(&t);
}
