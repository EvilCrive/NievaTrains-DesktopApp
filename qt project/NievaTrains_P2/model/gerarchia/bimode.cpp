#include "model/gerarchia/bimode.h"
#include <algorithm>
#include <cctype>
#include <iostream>

Bimode::Bimode(const std::string & n, const std::string & c, unsigned int s,TtrasmissioneElettrico ttr1, double e1,double e2, Tfuel tf,Tmotore tm1)
    : Electric(n,c,s,ttr1,e1),Internal_Combustion(n,c,s,e2,tf), motorePrimario(tm1){}

std::string Bimode::getMotorePrimario() const
{
    if(motorePrimario==Tmotore::electric)      return "Electric";
    if(motorePrimario==Tmotore::fullhybrid)     return "FullHybrid";
    if(motorePrimario==Tmotore::internal_combustion)   return "Internal_Combustion";
    return "NoType";
}

void Bimode::setMotorePrimario(std::string tr)
{
    std::transform(tr.begin(), tr.end(), tr.begin(),
        [](unsigned char c){ return std::tolower(c); });
    //porta la stringa tutta lowercase
    if(tr=="elettrico"){
        motorePrimario=Tmotore::electric;
    }else if(tr=="combustione"){
        motorePrimario=Tmotore::internal_combustion;
    }else if(tr=="fullhybrid"){
        motorePrimario=Tmotore::fullhybrid;
    }
}

void Bimode::setCarburanteIC(std::string t)
{
    Internal_Combustion::setCarburanteIC(t);
}

void Bimode::setEfficenzaIC(double e)
{
    Internal_Combustion::setEfficenzaIC(e);
}

void Bimode::setTrasmissioneElettrico(std::string t)
{
    Electric::setTrasmissioneElettrico(t);
}

void Bimode::setEfficenzaElettrico(double e)
{
    Electric::setEfficenzaElettrico(e);
}

double Bimode::carburanteNecessario(unsigned int km) const
{
    double result=0;
    if(motorePrimario==Tmotore::electric){
        result= (((km/efficenzaElettrico)*0.75)+((km/efficenzaIC)*0.25));
    }else if(motorePrimario==Tmotore::internal_combustion){
        result= (((km/efficenzaElettrico)*0.25)+((km/efficenzaIC)*0.75));
    }else{
        result= (((km/efficenzaElettrico)*0.5)+((km/efficenzaIC)*0.5));
    }
    return result;
}

unsigned int Bimode::kmPercorribili(unsigned int f) const
{
    unsigned int result=0;
    if(motorePrimario==Tmotore::electric){
        result= static_cast<unsigned int>(efficenzaElettrico*f);
    }else if(motorePrimario==Tmotore::internal_combustion){
        result= static_cast<unsigned int>(efficenzaIC*f);
    }else{
        result= static_cast<unsigned int>(efficenzaIC*f);
    }
    return result;
}

std::string Bimode::type() const
{
    return "Bimode";
}

void Bimode::print() const
{
    Treno::print();
    std::cout<<"\nMotore Primario: "<<getMotorePrimario()<<"\nTrasmissione Motore Elettrico: "<<Electric::getTrasmissioneElettrico()<<"\nEfficenza Motore Elettrico: "<<Electric::getEfficenzaElettrico()*100<<"%"<<"\nEfficenza Motore a Combustione Interna: "<<Internal_Combustion::getEfficenzaIC()*100<<"%"<<"\nCarburante Motore a Combustione Interna: "<<getCarburanteIC();

}
std::string Bimode::print2() const{
    std::string s=Treno::print2();
    s.append("\nMotore Primario: "+getMotorePrimario()+"\nTrasmissione Motore Elettrico: "+Electric::getTrasmissioneElettrico()+"\nEfficenza Motore Elettrico: "+std::to_string(Electric::getEfficenzaElettrico()*100)+"%"+"\nEfficenza Motore a Combustione Interna: "+std::to_string(Internal_Combustion::getEfficenzaIC()*100)+"%"+"\nCarburante Motore a Combustione Interna: "+getCarburanteIC());
    return s;
}
void Bimode::serialize(QJsonObject & json)
{
    json["type"]="Bimode";
    json["nome"]=QString::fromStdString(getNome());
    json["builder"]=QString::fromStdString(getCostruttore());
    json["speed"]=static_cast<int>(getSpeed());
    json["tipo_trasmissioneElettrico"]=QString::fromStdString(getTrasmissioneElettrico());
    json["efficenzaElettrico"]=getEfficenzaElettrico();
    json["tipo_carburanteIC"]=QString::fromStdString(getCarburanteIC());
    json["efficenzaIC"]=getEfficenzaIC();
    json["motore_primario"]=QString::fromStdString(getMotorePrimario());
}
/*
Bimode *Bimode::clone() const
{
    return new Bimode(*this);
}
*/
