#include "model/gerarchia/internal_combustion.h"
#include <algorithm>
#include <cctype>
#include <iostream>

Internal_Combustion::Internal_Combustion(const std::string & n, const std::string & c, unsigned int s, unsigned int p, double eff, std::string tf): Treno(n,c,s,p), efficenzaIC(eff), motoreIC(tf){}

double Internal_Combustion::getEfficenzaIC() const
{
    return efficenzaIC;
}

std::string Internal_Combustion::getMotoreIC() const
{
    return motoreIC;
}


void Internal_Combustion::setEfficenzaIC(double e)
{
    efficenzaIC=e;
}

void Internal_Combustion::setMotoreIC(std::string tr)
{
    motoreIC=tr;
}

double Internal_Combustion::carburanteNecessario(unsigned int km) const
{
    return km/efficenzaIC;
}

unsigned int Internal_Combustion::kmPercorribili(unsigned int l) const
{
    return static_cast<unsigned int>(efficenzaIC*l);
}

std::string Internal_Combustion::type() const
{
    return "Internal_Combustion";
}

void Internal_Combustion::print() const
{
    Treno::print();
    std::cout<<"\nCarburante: "<<getMotoreIC()<<"\nEfficenza: "<<getEfficenzaIC()*100<<"%";
}
std::string Internal_Combustion::treno2string() const{
    std::string s=Treno::treno2string();
    std::string efficenza=std::to_string(getEfficenzaIC()*100);
    efficenza.erase ( efficenza.find(".")+3, std::string::npos );
    s.append("\nCarburante: "+getMotoreIC()+"\nEfficenza: "+efficenza+"%");
    return s;
}
void Internal_Combustion::serialize(QJsonObject & json)
{
    json["type"]="Internal_Combustion";
    json["nome"]=QString::fromStdString(getNome());
    json["builder"]=QString::fromStdString(getCostruttore());
    json["speed"]=static_cast<int>(getSpeed());
    json["peso"]=static_cast<int>(getPeso());

    json["tipo_motoreIC"]=QString::fromStdString(getMotoreIC());
    json["efficenzaIC"]=getEfficenzaIC();
}
