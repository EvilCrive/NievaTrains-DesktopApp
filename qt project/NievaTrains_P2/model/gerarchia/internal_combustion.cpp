#include "internal_combustion.h"
#include <algorithm>
#include <cctype>
#include <iostream>

Internal_Combustion::Internal_Combustion(const std::string & n, unsigned int i, const std::string & c, unsigned int s, Trotaia tr, Ttreno tt, float e, Tfuel tf, TtrasmissioneFuel ttr): Treno(n,i,c,s,tr,tt), carburante(tf), trasmissione(ttr), efficenzaFuel(e){}

float Internal_Combustion::getEfficenza() const
{
    return efficenzaFuel;
}

std::string Internal_Combustion::getCarburante() const
{
    if(carburante==Tfuel::diesel)   return "Diesel";
    if(carburante==Tfuel::petrol)   return "Petrol";
    if(carburante==Tfuel::kerosene) return "Kerosene";
    return "NoType";
}

std::string Internal_Combustion::getTrasmissione() const
{
    if(trasmissione==TtrasmissioneFuel::steam)  return "Steam";
    if(trasmissione==TtrasmissioneFuel::electric)   return "Electric";
    if(trasmissione==TtrasmissioneFuel::hydraulic)  return "Hydraulic";
    if(trasmissione==TtrasmissioneFuel::pneumatic)  return "Pneumatic";
    if(trasmissione==TtrasmissioneFuel::mechanical) return "Mechanical";
    return "NoType";
}

void Internal_Combustion::setEfficenza(float e)
{
    efficenzaFuel=e;
}

void Internal_Combustion::setCarburante(std::string tr)
{
    std::transform(tr.begin(), tr.end(), tr.begin(),
        [](unsigned char c){ return std::tolower(c); });
    //porta la stringa tutta lowercase
    if(tr=="kerosene"){
        carburante=Tfuel::kerosene;
    }else if(tr=="petrol"){
        carburante=Tfuel::petrol;
    }else if(tr=="diesel"){
        carburante=Tfuel::diesel;
    }
}

void Internal_Combustion::setTrasmissione(std::string tr)
{
    std::transform(tr.begin(), tr.end(), tr.begin(),
        [](unsigned char c){ return std::tolower(c); });
    //porta la stringa tutta lowercase
    if(tr=="electric"){
        trasmissione=TtrasmissioneFuel::electric;
    }else if(tr=="mechanical"){
        trasmissione=TtrasmissioneFuel::mechanical;
    }else if(tr=="hydraulic"){
        trasmissione=TtrasmissioneFuel::hydraulic;
    }else if(tr=="steam"){
        trasmissione=TtrasmissioneFuel::steam;
    }else if(tr=="pneumatic"){
        trasmissione=TtrasmissioneFuel::pneumatic;
    }
}

float Internal_Combustion::carburanteNecessario(unsigned int km) const
{
    return km/efficenzaFuel;
}

unsigned int Internal_Combustion::kmPercorribili(unsigned int l) const
{
    //return static_cast<unsigned int>(efficenzaFuel*l);
    return static_cast<unsigned int>(efficenzaFuel*l);
}

std::string Internal_Combustion::type() const
{
    return "Internal_Combustion";
}

void Internal_Combustion::print() const
{
    Treno::print();
    std::cout<<"\nTrasmissione: "<<getTrasmissione()<<"\nCarburante: "<<getCarburante()<<"\nEfficenza: "<<getEfficenza()*100<<"%";
}
/*
Internal_Combustion *Internal_Combustion::clone() const
{
    return new Internal_Combustion(*this);
}
*/
