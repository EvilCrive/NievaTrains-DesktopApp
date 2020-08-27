#include "model/gerarchia/internal_combustion.h"
#include <algorithm>
#include <cctype>
#include <iostream>

Internal_Combustion::Internal_Combustion(const std::string & n, const std::string & c, unsigned int s, unsigned int p, double eff, Tfuel tf): Treno(n,c,s,p), efficenzaIC(eff), carburanteIC(tf){}

double Internal_Combustion::getEfficenzaIC() const
{
    return efficenzaIC;
}

std::string Internal_Combustion::getCarburanteIC() const
{
    if(carburanteIC==Tfuel::diesel)   return "Diesel";
    if(carburanteIC==Tfuel::petrol)   return "Petrol";
    if(carburanteIC==Tfuel::kerosene) return "Kerosene";
    return "NoType";
}


void Internal_Combustion::setEfficenzaIC(double e)
{
    efficenzaIC=e;
}

void Internal_Combustion::setCarburanteIC(std::string tr)
{
    std::transform(tr.begin(), tr.end(), tr.begin(),
        [](unsigned char c){ return std::tolower(c); });
    //porta la stringa tutta lowercase
    if(tr=="kerosene"){
        carburanteIC=Tfuel::kerosene;
    }else if(tr=="petrol"){
        carburanteIC=Tfuel::petrol;
    }else if(tr=="diesel"){
        carburanteIC=Tfuel::diesel;
    }
}

double Internal_Combustion::carburanteNecessario(unsigned int km) const
{
    return km/efficenzaIC;
}

unsigned int Internal_Combustion::kmPercorribili(unsigned int l) const
{
    //return static_cast<unsigned int>(efficenzaFuel*l);
    return static_cast<unsigned int>(efficenzaIC*l);
}

std::string Internal_Combustion::type() const
{
    return "Internal_Combustion";
}

void Internal_Combustion::print() const
{
    Treno::print();
    std::cout<<"\nCarburante: "<<getCarburanteIC()<<"\nEfficenza: "<<getEfficenzaIC()*100<<"%";
}
std::string Internal_Combustion::print2() const{
    std::string s=Treno::print2();
    s.append("\nCarburante: "+getCarburanteIC()+"\nEfficenza: "+std::to_string(getEfficenzaIC()*100)+"%");
    return s;
}
void Internal_Combustion::serialize(QJsonObject & json)
{
    json["type"]="Internal_Combustion";
    json["nome"]=QString::fromStdString(getNome());
    json["builder"]=QString::fromStdString(getCostruttore());
    json["speed"]=static_cast<int>(getSpeed());
    json["tipo_carburanteIC"]=QString::fromStdString(getCarburanteIC());
    json["efficenzaIC"]=getEfficenzaIC();
}
/*
Internal_Combustion *Internal_Combustion::clone() const
{
    return new Internal_Combustion(*this);
}
*/
