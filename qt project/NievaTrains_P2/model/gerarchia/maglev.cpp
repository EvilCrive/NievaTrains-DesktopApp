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


std::string Maglev::type() const
{
    return "Maglev";
}

void Maglev::print() const
{
    Treno::print();
    std::cout<<"\nTecnologia Maglev: "<<getTecnologia();
}
std::string Maglev::print2() const{
    std::string s=Treno::print2();
    s.append("\nTecnologia Maglev: "+getTecnologia());
    return s;
}

void Maglev::serialize(QJsonObject & json)
{
    json["type"]="Maglev";
    json["nome"]=QString::fromStdString(getNome());
    json["builder"]=QString::fromStdString(getCostruttore());
    json["speed"]=static_cast<int>(getSpeed());
    json["tipo_rotaia"]=QString::fromStdString(getTipo_rotaia());
    json["tipo_treno"]=QString::fromStdString(getTipo_treno());
    json["tipo_tecnologia"]=QString::fromStdString(getTecnologia());
}

