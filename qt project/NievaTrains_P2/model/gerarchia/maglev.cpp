#include "model/gerarchia/maglev.h"
#include <algorithm>
#include <cctype>
#include <iostream>

Maglev::Maglev(const std::string & n, const std::string & c, unsigned int s, Trotaia tr, Ttreno tt, Ttech ttt): Treno(n,c,s,tr,tt), tecnologia(ttt){}

std::string Maglev::getTecnologia() const
{
    if(tecnologia==Ttech::eds)  return "Eds";
    if(tecnologia==Ttech::ems)  return "Ems";
    return "NoType";
}

void Maglev::setTecnologia(std::string tr)
{
    std::transform(tr.begin(), tr.end(), tr.begin(),
        [](unsigned char c){ return std::tolower(c); });
    //porta la stringa tutta lowercase
    if(tr=="eds"){
        tecnologia=Ttech::eds;
    }else if(tr=="ems"){
        tecnologia=Ttech::ems;
    }
}
/*
Maglev *Maglev::clone() const
{
    return new Maglev(*this);
}
*/
double Maglev::carburanteNecessario(unsigned int) const
{
    return -1;
}

unsigned int Maglev::kmPercorribili(unsigned int) const
{
    return -1;
}

std::string Maglev::type() const
{
    return "Maglev";
}

void Maglev::print() const
{
    Treno::print();
    std::cout<<"\nTecnologia Maglev: "<<getTecnologia();
}

