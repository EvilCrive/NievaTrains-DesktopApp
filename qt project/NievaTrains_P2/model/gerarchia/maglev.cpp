#include "model/gerarchia/maglev.h"
#include <algorithm>
#include <cctype>
#include <iostream>

Maglev::Maglev(const std::string & n, const std::string & c, unsigned int s, unsigned int p, bool ttt): Treno(n,c,s,p), tecnologia(ttt){}

bool Maglev::getTecnologia() const
{
    return tecnologia;
}

void Maglev::setTecnologia(bool tr)
{
    tecnologia=tr;
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
std::string Maglev::treno2string() const{
    std::string s=Treno::treno2string();
    std::string tmp="";
    if(getTecnologia()) tmp="EDS";
    else tmp="EMS";

    s.append("\nTecnologia Maglev: "+tmp);
    return s;
}
double Maglev::carburanteNecessario(unsigned int) const{
    return 0;
}
unsigned int Maglev::kmPercorribili(unsigned int) const{
    return 0;
}
void Maglev::serialize(QJsonObject & json)
{
    json["type"]="Maglev";
    json["nome"]=QString::fromStdString(getNome());
    json["builder"]=QString::fromStdString(getCostruttore());
    json["speed"]=static_cast<int>(getSpeed());
    json["peso"]=static_cast<int>(getPeso());
    std::string tmp="";
    if(getTecnologia()) tmp="EDS";
    else tmp="EMS";
    json["tipo_tecnologia"]=QString::fromStdString(tmp);
}

