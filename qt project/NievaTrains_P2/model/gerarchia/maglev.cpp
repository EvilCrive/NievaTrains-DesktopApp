#include "model/gerarchia/maglev.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include "view/supporto/nievaexception.h"

Maglev::Maglev(const std::string & n, const std::string & c, unsigned int s, unsigned int p, bool ttt): Treno(n,c,s,p), tecnologia(ttt){}

bool Maglev::getTecnologia() const
{
    return tecnologia;
}

void Maglev::setTecnologia(bool tr)
{
    tecnologia=tr;
}
/**
 * @brief carburanteNecessario calcola quante unità di carburante sono necessarie perchè il treno compia un determinato numero di km
 * @param km da percorrere
 * @return carburante necessario
 */
//eccezione
//lista eccezioni
double Maglev::carburanteNecessario(unsigned int) const{
    throw new NievaException("Maglev");
}
/**
 * @brief kmPercorribili calcola quanti km sono percorribili dal treno considerando la disponibilità di un determinato numero di unità di carburante
 * @param unità di carburante
 * @return km percorribili
 */
unsigned int Maglev::kmPercorribili(unsigned int) const{
    throw new NievaException("Maglev");
}
std::string Maglev::type() const
{
    return "Maglev";
}

void Maglev::print() const
{
    Treno::print();
    std::cout<<"\nTecnologia Maglev: "<<getTecnologia();
}
std::string Maglev::treno2string() const{
    std::string s=Treno::treno2string();
    std::string tmp="";
    if(getTecnologia()) tmp="EDS";
    else tmp="EMS";

    s.append("\nTecnologia Maglev: "+tmp);
    return s;
}
/**
 * @brief serialize trasforma il treno nella sua rappresentazione in json
 * @param oggetto json
 */
void Maglev::serialize(QJsonObject & json)
{
    json["type"]="Maglev";
    json["nome"]=QString::fromStdString(getNome());
    json["builder"]=QString::fromStdString(getCostruttore());
    json["speed"]=static_cast<int>(getSpeed());
    json["peso"]=static_cast<int>(getPeso());
    std::string tmp="";
    if(getTecnologia()) tmp="EDS";
    else tmp="EMS";
    json["tipo_tecnologia"]=QString::fromStdString(tmp);
}

