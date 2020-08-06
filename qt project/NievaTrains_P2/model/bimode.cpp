#include "bimode.h"
#include <algorithm>
#include <cctype>

Bimode::Bimode(const std::string & n, unsigned int i, const std::string & c, unsigned int s, Trotaia tr, Ttreno tt,Ttrasmission ttr1, float e1,float e2, Tfuel tf, Ttrasmissione ttr2,Tmotore)
    : Electric(n,i,c,s,tr,tt,ttr1,e1),Internal_Combustion(n,i,c,s,tr,tt,e2,tf,ttr2), motorePrimario(){}

Tmotore Bimode::getMotorePrimario() const
{
    return motorePrimario;
}

void Bimode::setMotorePrimario(std::string tr)
{
    std::transform(tr.begin(), tr.end(), tr.begin(),
        [](unsigned char c){ return std::tolower(c); });
    //porta la stringa tutta lowercase
    if(tr=="elettrico"){
        motorePrimario=Tmotore::elettrico;
    }else if(tr=="combustione"){
        motorePrimario=Tmotore::combustione;
    }else if(tr=="fullhybrid"){
        motorePrimario=Tmotore::fullhybrid;
    }
}

float Bimode::carburanteNecessario(unsigned int km) const
{

}
