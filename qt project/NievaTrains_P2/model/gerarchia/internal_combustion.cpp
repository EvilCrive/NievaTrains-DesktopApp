#include "model/gerarchia/internal_combustion.h"
#include <algorithm>
#include <cctype>
#include <iostream>

Internal_Combustion::Internal_Combustion(const std::string & n, const std::string & c, unsigned int s, Trotaia tr, Ttreno tt, double e, Tfuel tf, TtrasmissioneFuel ttr): Treno(n,c,s,tr,tt), carburanteIC(tf), trasmissioneIC(ttr), efficenzaIC(e){}

double Internal_Combustion::getEfficenzaIC() const
{
    return efficenzaIC;
}

std::string Internal_Combustion::getCarburanteIC() const
{
    if(carburanteIC==Tfuel::diesel)   return "Diesel";
    if(carburanteIC==Tfuel::petrol)   return "Petrol";
    if(carburanteIC==Tfuel::kerosene) return "Kerosene";
    return "NoType";
}

std::string Internal_Combustion::getTrasmissioneIC() const
{
    if(trasmissioneIC==TtrasmissioneFuel::steam)  return "Steam";
    if(trasmissioneIC==TtrasmissioneFuel::electric)   return "Electric";
    if(trasmissioneIC==TtrasmissioneFuel::hydraulic)  return "Hydraulic";
    if(trasmissioneIC==TtrasmissioneFuel::pneumatic)  return "Pneumatic";
    if(trasmissioneIC==TtrasmissioneFuel::mechanical) return "Mechanical";
    return "NoType";
}

void Internal_Combustion::setEfficenzaIC(double e)
{
    efficenzaIC=e;
}

void Internal_Combustion::setCarburanteIC(std::string tr)
{
    std::transform(tr.begin(), tr.end(), tr.begin(),
        [](unsigned char c){ return std::tolower(c); });
    //porta la stringa tutta lowercase
    if(tr=="kerosene"){
        carburanteIC=Tfuel::kerosene;
    }else if(tr=="petrol"){
        carburanteIC=Tfuel::petrol;
    }else if(tr=="diesel"){
        carburanteIC=Tfuel::diesel;
    }
}

void Internal_Combustion::setTrasmissioneIC(std::string tr)
{
    std::transform(tr.begin(), tr.end(), tr.begin(),
        [](unsigned char c){ return std::tolower(c); });
    //porta la stringa tutta lowercase
    if(tr=="electric"){
        trasmissioneIC=TtrasmissioneFuel::electric;
    }else if(tr=="mechanical"){
        trasmissioneIC=TtrasmissioneFuel::mechanical;
    }else if(tr=="hydraulic"){
        trasmissioneIC=TtrasmissioneFuel::hydraulic;
    }else if(tr=="steam"){
        trasmissioneIC=TtrasmissioneFuel::steam;
    }else if(tr=="pneumatic"){
        trasmissioneIC=TtrasmissioneFuel::pneumatic;
    }
}

double Internal_Combustion::carburanteNecessario(unsigned int km) const
{
    return km/efficenzaIC;
}

unsigned int Internal_Combustion::kmPercorribili(unsigned int l) const
{
    //return static_cast<unsigned int>(efficenzaFuel*l);
    return static_cast<unsigned int>(efficenzaIC*l);
}

std::string Internal_Combustion::type() const
{
    return "Internal_Combustion";
}

void Internal_Combustion::print() const
{
    Treno::print();
    std::cout<<"\nTrasmissione: "<<getTrasmissioneIC()<<"\nCarburante: "<<getCarburanteIC()<<"\nEfficenza: "<<getEfficenzaIC()*100<<"%";
}

void Internal_Combustion::serialize(QJsonObject & json)
{
    json["type"]="Internal_Combustion";
    json["nome"]=QString::fromStdString(getNome());
    json["builder"]=QString::fromStdString(getCostruttore());
    json["speed"]=static_cast<int>(getSpeed());
    json["tipo_rotaia"]=QString::fromStdString(getTipo_rotaia());
    json["tipo_treno"]=QString::fromStdString(getTipo_treno());
    json["tipo_carburanteIC"]=QString::fromStdString(getCarburanteIC());
    json["tipo_trasmissioneIC"]=QString::fromStdString(getTrasmissioneIC());
    json["efficenzaIC"]=getEfficenzaIC();
}
/*
Internal_Combustion *Internal_Combustion::clone() const
{
    return new Internal_Combustion(*this);
}
*/
