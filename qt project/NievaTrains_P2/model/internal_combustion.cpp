#include "internal_combustion.h"
#include <algorithm>
#include <cctype>


Internal_Combustion::Internal_Combustion(const std::string & n, unsigned int i, const std::string & c, unsigned int s, Trotaia tr, Ttreno tt, float e, Tfuel tf, Ttrasmissione ttr): Treno(n,i,c,s,tr,tt), efficenza(e), carburante(tf), trasmissione(ttr){}

float Internal_Combustion::getEfficenza() const
{
    return efficenza;
}

Tfuel Internal_Combustion::getCarburante() const
{
    return carburante;
}

Ttrasmissione Internal_Combustion::getTrasmissione() const
{
    return trasmissione;
}

void Internal_Combustion::setEfficenza(float e)
{
    efficenza=e;
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
        trasmissione=Ttrasmissione::electric;
    }else if(tr=="mechanical"){
        trasmissione=Ttrasmissione::mechanical;
    }else if(tr=="hydraulic"){
        trasmissione=Ttrasmissione::hydraulic;
    }else if(tr=="steam"){
        trasmissione=Ttrasmissione::steam;
    }else if(tr=="pneumatic"){
        trasmissione=Ttrasmissione::pneumatic;
    }
}

float Internal_Combustion::carburanteNecessario(unsigned int km) const
{
    return km/efficenza;
}

unsigned int Internal_Combustion::kmPercorribili(unsigned int l) const
{
    return l*efficenza;
}
