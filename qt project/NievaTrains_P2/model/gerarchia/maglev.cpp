#include "maglev.h"
#include <algorithm>
#include <cctype>

Maglev::Maglev(const std::string & n, unsigned int i, const std::string & c, unsigned int s, Trotaia tr, Ttreno tt, Ttech ttt): Treno(n,i,c,s,tr,tt), tecnologia(ttt){}

Ttech Maglev::getTecnologia() const
{
    return tecnologia;
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

