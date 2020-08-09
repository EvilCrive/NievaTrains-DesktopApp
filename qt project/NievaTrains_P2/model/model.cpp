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

Treno *Model::operator[](unsigned int i) const
{
    return list[i];
}

void Model::erase(unsigned int i)
{
    list.pop(i);
}

void Model::clear()
{
    for(unsigned int i=0; i<list.getSize();i++) erase(0);
    erase(0);
}


unsigned int Model::numerotreni() const
{
    int count=0;
    for(unsigned int i=0; i<list.getSize();i++){
        count++;
    }
    return count;
}


void Model::push_end(Treno *t)
{
    list.push(&t);
}
