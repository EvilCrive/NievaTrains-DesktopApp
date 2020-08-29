#include "model/gerarchia/bimode.h"
#include <algorithm>
#include <cctype>
#include <iostream>

Bimode::Bimode(const std::string & n, const std::string & c, unsigned int s, unsigned int p,bool ttr1, double e1,double e2, std::string tf,bool tm1)
    : Treno(n,c,s,p),Electric(n,c,s,p,ttr1,e1),Internal_Combustion(n,c,s,p,e2,tf), motorePrimario(tm1){}

bool Bimode::getMotorePrimario() const
{
    return motorePrimario;
}

void Bimode::setMotorePrimario(bool tr)
{
    motorePrimario=tr;
}

void Bimode::setMotoreIC(std::string t)
{
    Internal_Combustion::setMotoreIC(t);
}

void Bimode::setEfficenzaIC(double e)
{
    Internal_Combustion::setEfficenzaIC(e);
}

void Bimode::setTrasmissioneElettrico(bool t)
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
    if(motorePrimario)
        result= (((km/efficenzaElettrico)*0.75)+((km/efficenzaIC)*0.25));
    else
        result= (((km/efficenzaElettrico)*0.25)+((km/efficenzaIC)*0.75));
    return result;
}

unsigned int Bimode::kmPercorribili(unsigned int f) const
{
    unsigned int result=0;
    if(motorePrimario)
        result= static_cast<unsigned int>(efficenzaElettrico*f);
    else
        result= static_cast<unsigned int>(efficenzaIC*f);
    return result;
}

std::string Bimode::type() const
{
    return "Bimode";
}

void Bimode::print() const
{
    Treno::print();
    std::cout<<"\nMotore Primario: "<<getMotorePrimario()<<"\nTrasmissione Motore Elettrico: "<<Electric::getTrasmissioneElettrico()<<"\nEfficenza Motore Elettrico: "<<Electric::getEfficenzaElettrico()*100<<"%"<<"\nEfficenza Motore a Combustione Interna: "<<Internal_Combustion::getEfficenzaIC()*100<<"%"<<"\nCarburante Motore a Combustione Interna: "<<getMotoreIC();

}
std::string Bimode::treno2string() const{
    std::string s=Treno::treno2string();
    std::string efficenzaIC=std::to_string(getEfficenzaIC()*100);
    efficenzaIC.erase ( efficenzaIC.find(".")+3, std::string::npos );
    std::string efficenzaE=std::to_string(getEfficenzaElettrico()*100);
    efficenzaE.erase ( efficenzaE.find(".")+3, std::string::npos );
    std::string tmp="";
    if(getMotorePrimario()) tmp="Internal Combustion";
    else tmp="Electric";
    std::string tmp2="";
    if(Electric::getTrasmissioneElettrico()) tmp2="Third Rail";
    else tmp2="Overhead Line";
    s.append("\nMotore Primario: "+tmp+"\nTrasmissione Motore Elettrico: "+tmp2+"\nEfficenza Motore Elettrico: "+efficenzaE+"%"+"\nEfficenza Motore a Combustione Interna: "+efficenzaIC+"%"+"\nCarburante Motore a Combustione Interna: "+getMotoreIC());
    return s;
}
void Bimode::serialize(QJsonObject & json)
{
    json["type"]="Bimode";
    json["nome"]=QString::fromStdString(getNome());
    json["builder"]=QString::fromStdString(getCostruttore());
    json["speed"]=static_cast<int>(getSpeed());
    json["peso"]=static_cast<int>(getPeso());
    std::string tmp="";
    if(getMotorePrimario()) tmp="Internal Combustion";
    else tmp="Electric";
    std::string tmp2="";
    if(Electric::getTrasmissioneElettrico()) tmp2="Third Rail";
    else tmp2="Overhead Line";
    json["tipo_trasmissioneElettrico"]=QString::fromStdString(tmp2);
    json["efficenzaElettrico"]=getEfficenzaElettrico();
    json["tipo_motoreIC"]=QString::fromStdString(getMotoreIC());
    json["efficenzaIC"]=getEfficenzaIC();
    json["motore_primario"]=QString::fromStdString(tmp);
}

