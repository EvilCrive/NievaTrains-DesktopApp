#include "electric.h"
#include <algorithm>
#include <cctype>
#include <iostream>

Electric::Electric(const std::string & n, const std::string & c, unsigned int s, Trotaia tr, Ttreno tt, TtrasmissioneElettrico ttr, float e): Treno(n,c,s,tr,tt), trasmissione(ttr), efficenzaElettrico(e){}

std::string Electric::getTrasmissione() const
{
    if(trasmissione==TtrasmissioneElettrico::third_rail)    return "Third_Rail";
    if(trasmissione==TtrasmissioneElettrico::overhead_lines)    return "Overhead_Lines";
    return "NoType";
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
        trasmissione=TtrasmissioneElettrico::overhead_lines;
    }else if(tr=="third_rail"){
        trasmissione=TtrasmissioneElettrico::third_rail;
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

std::string Electric::type() const
{
    return "Electric";
}
void Electric::print() const{
    Treno::print();
    std::cout<<"\nTrasmissione: "<<getTrasmissione()<<"\nEfficenza: "<<getEfficenza()*100<<"%";
}
/*
Electric *Electric::clone() const
{
    return new Electric(*this);
}
*/
