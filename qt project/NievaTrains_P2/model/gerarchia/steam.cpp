#include "steam.h"
#include <algorithm>
#include <cctype>



Steam::Steam(const std::string & n, unsigned int i, const std::string & c, unsigned int s, Trotaia tr, Ttreno tt, float e, TfuelSteam tfs): Treno(n,i,c,s,tr,tt),efficenza(e),carburante(tfs){}

float Steam::getEfficenza() const
{
    return efficenza;
}

TfuelSteam Steam::getCarburante() const
{
    return carburante;
}

void Steam::setEfficenza(float e)
{
    efficenza=e;
}

void Steam::setCarburante(std::string tr)
{
    std::transform(tr.begin(), tr.end(), tr.begin(),
        [](unsigned char c){ return std::tolower(c); });
    //porta la stringa tutta lowercase
    if(tr=="coal"){
        carburante=TfuelSteam::coal;
    }else if(tr=="wood"){
        carburante=TfuelSteam::wood;
    }else if(tr=="oil"){
        carburante=TfuelSteam::oil;
    }
}

float Steam::carburanteNecessario(unsigned int km) const
{
    return km/efficenza;
}

unsigned int Steam::kmPercorribili(unsigned int kg) const
{
    return static_cast<unsigned int>(efficenza*kg);
}

Steam *Steam::clone() const
{
    return new Steam(*this);
}
