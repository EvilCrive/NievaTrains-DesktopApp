#include "model/gerarchia/internal_combustion.h"
#include <algorithm>
#include <cctype>
#include <iostream>

Internal_Combustion::Internal_Combustion(const std::string & n, const std::string & c, unsigned int s, unsigned int p, unsigned int pot, std::string tf): Treno(n,c,s,p), potenzaIC(pot), motoreIC(tf){}

unsigned int Internal_Combustion::getPotenzaIC() const
{
    return potenzaIC;
}

std::string Internal_Combustion::getMotoreIC() const
{
    return motoreIC;
}


void Internal_Combustion::setPotenzaIC(unsigned int p)
{
    potenzaIC=p;
}

void Internal_Combustion::setMotoreIC(std::string tr)
{
    motoreIC=tr;
}
/**
 * @brief carburanteNecessario calcola quante unità di carburante sono necessarie perchè il treno compia un determinato numero di km
 * @param km da percorrere
 * @return carburante necessario
 */
double Internal_Combustion::carburanteNecessario(unsigned int km) const
{
    if(potenzaIC==0) return 0;
    else if(potenzaIC>10000)      return km;
    else return km/(potenzaIC/10000);
}
/**
 * @brief kmPercorribili calcola quanti km sono percorribili dal treno considerando la disponibilità di un determinato numero di unità di carburante
 * @param unità di carburante
 * @return km percorribili
 */
unsigned int Internal_Combustion::kmPercorribili(unsigned int l) const
{
    if(potenzaIC==0) return 0;
    else if(potenzaIC>10000)      return l;
    else return l*(potenzaIC/10000);
}

std::string Internal_Combustion::type() const
{
    return "Internal_Combustion";
}

void Internal_Combustion::print() const
{
    Treno::print();
    std::cout<<"\nMotore Diesel: "<<getMotoreIC()<<"\nPotenza specifica: "<<getPotenzaIC()<<"%";
}
std::string Internal_Combustion::treno2string() const{
    std::string s=Treno::treno2string();
    std::string potenza=std::to_string(getPotenzaIC());
    s.append("\nMotore Diesel: "+getMotoreIC()+"\nPotenza specifica: "+potenza+"kW/l");
    return s;
}
/**
 * @brief serialize trasforma il treno nella sua rappresentazione in json
 * @param oggetto json
 */
void Internal_Combustion::serialize(QJsonObject & json)
{
    json["type"]="Internal_Combustion";
    json["nome"]=QString::fromStdString(getNome());
    json["builder"]=QString::fromStdString(getCostruttore());
    json["speed"]=static_cast<int>(getSpeed());
    json["peso"]=static_cast<int>(getPeso());

    json["tipo_motoreIC"]=QString::fromStdString(getMotoreIC());
    json["potenzaIC"]=static_cast<int>(getPotenzaIC());
}
