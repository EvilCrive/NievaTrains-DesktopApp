#include "model/gerarchia/bimode.h"
#include <algorithm>
#include <cctype>
#include <iostream>

Bimode::Bimode(const std::string & n, const std::string & c, unsigned int s, unsigned int p,bool ttr1, double e1,unsigned int pot, std::string tf,bool tm1)
    : Treno(n,c,s,p),Electric(n,c,s,p,ttr1,e1),Internal_Combustion(n,c,s,p,pot,tf), motorePrimario(tm1){}

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

void Bimode::setPotenzaIC(unsigned int e)
{
    Internal_Combustion::setPotenzaIC(e);
}

void Bimode::setTrasmissioneElettrico(bool t)
{
    Electric::setTrasmissioneElettrico(t);
}

void Bimode::setEfficenzaElettrico(double e)
{
    Electric::setEfficenzaElettrico(e);
}
/**
 * @brief carburanteNecessario calcola quante unità di carburante sono necessarie perchè il treno compia un determinato numero di km
 * @param km da percorrere
 * @return carburante necessario
 */
double Bimode::carburanteNecessario(unsigned int km) const
{

    if(motorePrimario)
        return Electric::carburanteNecessario(km);
    else
        return Internal_Combustion::carburanteNecessario(km);
}
/**
 * @brief kmPercorribili calcola quanti km sono percorribili dal treno considerando la disponibilità di un determinato numero di unità di carburante
 * @param unità di carburante
 * @return km percorribili
 */
unsigned int Bimode::kmPercorribili(unsigned int f) const
{
    if(motorePrimario)
        return Electric::kmPercorribili(f);
    else
        return Internal_Combustion::kmPercorribili(f);

}
/**
 * @brief type ritorna il tipo del treno
 * @return stringa rappresentante il tipo del treno
 */
std::string Bimode::type() const
{
    return "Bimode";
}
/**
 * @brief stampa tramite cout alcune informazioni sul treno (usata per debugging)
 */
void Bimode::print() const
{
    Treno::print();
    std::cout<<"\nMotore Primario: "<<getMotorePrimario()<<"\nTrasmissione Motore Elettrico: "<<Electric::getTrasmissioneElettrico()<<"\nEfficenza Motore Elettrico: "<<Electric::getEfficenzaElettrico()*100<<"%"<<"\nEfficenza Motore a Combustione Interna: "<<Internal_Combustion::getPotenzaIC()<<"kW/l"<<"\nCarburante Motore a Combustione Interna: "<<getMotoreIC();
}
/**
  * @brief utilizzata per rappresentazre in forma di stringa un treno
  * @return stringa contentente le informazioni riguardanti il treno
  */
std::string Bimode::treno2string() const{
    std::string s=Treno::treno2string();
    std::string potenzaIC=std::to_string(getPotenzaIC()*100);
    potenzaIC.erase ( potenzaIC.find(".")+3, std::string::npos );
    std::string efficenzaE=std::to_string(getEfficenzaElettrico()*100);
    efficenzaE.erase ( efficenzaE.find(".")+3, std::string::npos );
    std::string tmp="";
    if(getMotorePrimario())tmp="Electric" ;
    else tmp="Internal Combustion" ;
    std::string tmp2="";
    if(Electric::getTrasmissioneElettrico()) tmp2="Third Rail";
    else tmp2="Overhead Line";
    s.append("\nMotore Primario: "+tmp+"\nTrasmissione Motore Elettrico: "+tmp2+"\nEfficenza Motore Elettrico: "+efficenzaE+"%"+"\nPotenza specifica motore a Combustione Interna: "+potenzaIC+" kW/l"+"\nMotore a Combustione Interna: "+getMotoreIC());
    return s;
}
/**
 * @brief serialize trasforma il treno nella sua rappresentazione in json
 * @param oggetto json
 */
void Bimode::serialize(QJsonObject & json)
{
    json["type"]="Bimode";
    json["nome"]=QString::fromStdString(getNome());
    json["builder"]=QString::fromStdString(getCostruttore());
    json["speed"]=static_cast<int>(getSpeed());
    json["peso"]=static_cast<int>(getPeso());
    std::string tmp="";
    if(getMotorePrimario()) tmp="Electric";
    else tmp="Internal Combustion";
    std::string tmp2="";
    if(Electric::getTrasmissioneElettrico()) tmp2="Third Rail";
    else tmp2="Overhead Line";
    json["tipo_trasmissioneElettrico"]=QString::fromStdString(tmp2);
    json["efficenzaElettrico"]=getEfficenzaElettrico();
    json["tipo_motoreIC"]=QString::fromStdString(getMotoreIC());
    json["potenzaIC"]=static_cast<int>(getPotenzaIC());
    json["motore_primario"]=QString::fromStdString(tmp);
}

