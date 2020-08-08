#include "electric.h"
#include <algorithm>
#include <cctype>

Electric::Electric(const std::string & n, unsigned int i, const std::string & c, unsigned int s, Trotaia tr, Ttreno tt, Ttrasmission ttr, float e): Treno(n,i,c,s,tr,tt), trasmissione(ttr), efficenzaElettrico(e){}

Ttrasmission Electric::getTrasmissione() const
{
    return trasmissione;
}

float Electric::getEfficenza() const
{
    return efficenzaElettrico;
}

void Electric::setTrasmissione(std::string tr)
{
    std::transform(tr.begin(), tr.end(), tr.begin(),
        [](unsigned char c){ return std::tolower(c); });
    //porta la stringa tutta lowercase
    if(tr=="overhead_lines"){
        trasmissione=Ttrasmission::overhead_lines;
    }else if(tr=="third_rail"){
        trasmissione=Ttrasmission::third_rail;
    }
}

void Electric::setEfficenza(float e)
{
    efficenzaElettrico=e;
}

float Electric::carburanteNecessario(unsigned int km) const
{
    return km/efficenzaElettrico;
}

unsigned int Electric::kmPercorribili(unsigned int kw) const
{
    return static_cast<unsigned int>(kw*efficenzaElettrico);
}
