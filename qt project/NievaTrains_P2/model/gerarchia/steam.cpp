#include "model/gerarchia/steam.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <math.h>

Steam::Steam(const std::string & n, const std::string & c, unsigned int s, unsigned int p, unsigned int t, std::string tfs): Treno(n,c,s,p),temperaturaOperativa(t),carburanteSteam(tfs){}

unsigned int Steam::getTemperaturaOperativa() const
{
    return temperaturaOperativa;
}

std::string Steam::getCarburanteSteam() const
{
    return carburanteSteam;
}

void Steam::setTemperaturaOperativa(unsigned int t)
{
    temperaturaOperativa=t;
}

void Steam::setCarburanteSteam(std::string tr)
{
    carburanteSteam=tr;
}
/**
 * @brief carburanteNecessario calcola quante unità di carburante sono necessarie perchè il treno compia un determinato numero di km
 * @param km da percorrere
 * @return carburante necessario
 */
double Steam::carburanteNecessario(unsigned int km) const
{
    if(temperaturaOperativa==0) return 0;
    else if(temperaturaOperativa>1000)      return km;
    else return (km*1000)/temperaturaOperativa;
}
/**
 * @brief kmPercorribili calcola quanti km sono percorribili dal treno considerando la disponibilità di un determinato numero di unità di carburante
 * @param unità di carburante
 * @return km percorribili
 */
unsigned int Steam::kmPercorribili(unsigned int kg) const
{
    if(temperaturaOperativa==0) return 0;
    else if(temperaturaOperativa>1000)      return kg;
    else return (kg*temperaturaOperativa)/1000;
}

std::string Steam::type() const
{
    return "Steam";
}

void Steam::print() const
{
    Treno::print();
    std::cout<<"\nTemperatura operativa: "<<getTemperaturaOperativa()<<"%"<<"\nCarburante: "<<getCarburanteSteam();
}
std::string Steam::treno2string() const{
    std::string s=Treno::treno2string();
    std::string temperatura=std::to_string(getTemperaturaOperativa());
    s.append("\nTemperatura operativa: "+temperatura+" C"+"\nCarburante: "+getCarburanteSteam());
    return s;
}
/**
 * @brief serialize trasforma il treno nella sua rappresentazione in json
 * @param oggetto json
 */
void Steam::serialize(QJsonObject & json)
{
    json["type"]="Steam";
    json["nome"]=QString::fromStdString(getNome());
    json["builder"]=QString::fromStdString(getCostruttore());
    json["speed"]=static_cast<int>(getSpeed());
    json["peso"]=static_cast<int>(getPeso());

    json["temperaturaOperativa"]=static_cast<int>(getTemperaturaOperativa());
    json["tipo_carburanteSteam"]=QString::fromStdString(getCarburanteSteam());
}
