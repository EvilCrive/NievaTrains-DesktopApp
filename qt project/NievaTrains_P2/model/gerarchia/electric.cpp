#include "model/gerarchia/electric.h"
#include <algorithm>
#include <cctype>
#include <iostream>

Electric::Electric(const std::string & n, const std::string & c, unsigned int s, unsigned int p, bool ttr, double e): Treno(n,c,s,p), efficenzaElettrico(e), trasmissioneElettrico(ttr){}

bool Electric::getTrasmissioneElettrico() const
{
    return trasmissioneElettrico;
}

double Electric::getEfficenzaElettrico() const
{
    return efficenzaElettrico;
}

void Electric::setTrasmissioneElettrico(bool tr)
{
    trasmissioneElettrico=tr;
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
std::string Electric::treno2string() const{
    std::string s=Treno::treno2string();
    std::string efficenza=std::to_string(getEfficenzaElettrico()*100);
    efficenza.erase ( efficenza.find(".")+3, std::string::npos );
    std::string tmp="";
    if(getTrasmissioneElettrico()) tmp="Third Rail";
    else tmp="Overhead Lines";
    s.append("\nTrasmissione: "+tmp+"\nEfficenza: "+efficenza+"%");
    return s;
}

void Electric::serialize(QJsonObject & json)
{
    json["type"]="Electric";
    json["nome"]=QString::fromStdString(getNome());
    json["builder"]=QString::fromStdString(getCostruttore());
    json["speed"]=static_cast<int>(getSpeed());
    json["peso"]=static_cast<int>(getPeso());
    std::string tmp="";
    if(getTrasmissioneElettrico()) tmp="Third Rail";
    else tmp="Overhead Lines";
    json["tipo_trasmissioneElettrico"]=QString::fromStdString(tmp);
    json["efficenzaElettrico"]=getEfficenzaElettrico();
}
