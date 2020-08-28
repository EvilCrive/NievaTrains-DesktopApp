#include "model/gerarchia/steam.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <math.h>

Steam::Steam(const std::string & n, const std::string & c, unsigned int s, unsigned int p, double e, std::string tfs): Treno(n,c,s,p),efficenzaSteam(e),carburanteSteam(tfs){}

double Steam::getEfficenzaSteam() const
{
    return efficenzaSteam;
}

std::string Steam::getCarburanteSteam() const
{
    return carburanteSteam;
}

void Steam::setEfficenzaSteam(double e)
{
    efficenzaSteam=e;
}

void Steam::setCarburanteSteam(std::string tr)
{
    carburanteSteam=tr;
}

double Steam::carburanteNecessario(unsigned int km) const
{
    return km/efficenzaSteam;
}

unsigned int Steam::kmPercorribili(unsigned int kg) const
{
    return static_cast<unsigned int>(efficenzaSteam*kg);
}

std::string Steam::type() const
{
    return "Steam";
}

void Steam::print() const
{
    Treno::print();
    std::cout<<"\nEfficenza: "<<getEfficenzaSteam()*100<<"%"<<"\nCarburante: "<<getCarburanteSteam();
}
std::string Steam::treno2string() const{
    std::string s=Treno::treno2string();
    std::string efficenza=std::to_string(getEfficenzaSteam()*100);
    efficenza.erase ( efficenza.find(".")+3, std::string::npos );
    s.append("\nEfficenza: "+efficenza+"%"+"\nCarburante: "+getCarburanteSteam());
    return s;
}

void Steam::serialize(QJsonObject & json)
{
    json["type"]="Steam";
    json["nome"]=QString::fromStdString(getNome());
    json["builder"]=QString::fromStdString(getCostruttore());
    json["speed"]=static_cast<int>(getSpeed());
    json["peso"]=static_cast<int>(getPeso());

    json["efficenzaSteam"]=getEfficenzaSteam();
    json["tipo_carburanteSteam"]=QString::fromStdString(getCarburanteSteam());
}
