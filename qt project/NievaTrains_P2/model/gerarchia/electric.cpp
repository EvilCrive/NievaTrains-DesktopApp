#include "model/gerarchia/electric.h"
#include <algorithm>
#include <cctype>
#include <iostream>

Electric::Electric(const std::string & n, const std::string & c, unsigned int s, Trotaia tr, Ttreno tt, TtrasmissioneElettrico ttr, double e): Treno(n,c,s,tr,tt), trasmissioneElettrico(ttr), efficenzaElettrico(e){}

std::string Electric::getTrasmissioneElettrico() const
{
    if(trasmissioneElettrico==TtrasmissioneElettrico::third_rail)    return "Third_Rail";
    if(trasmissioneElettrico==TtrasmissioneElettrico::overhead_lines)    return "Overhead_Lines";
    return "NoType";
}

double Electric::getEfficenzaElettrico() const
{
    return efficenzaElettrico;
}

void Electric::setTrasmissioneElettrico(std::string tr)
{
    std::transform(tr.begin(), tr.end(), tr.begin(),
        [](unsigned char c){ return std::tolower(c); });
    //porta la stringa tutta lowercase
    if(tr=="overhead_lines"){
        trasmissioneElettrico=TtrasmissioneElettrico::overhead_lines;
    }else if(tr=="third_rail"){
        trasmissioneElettrico=TtrasmissioneElettrico::third_rail;
    }
}

void Electric::setEfficenzaElettrico(double e)
{
    efficenzaElettrico=e;
}

double Electric::carburanteNecessario(unsigned int km) const
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
    std::cout<<"\nTrasmissione: "<<getTrasmissioneElettrico()<<"\nEfficenza: "<<getEfficenzaElettrico()*100<<"%";
}
/*
Electric *Electric::clone() const
{
    return new Electric(*this);
}
*/
