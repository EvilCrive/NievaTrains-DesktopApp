#include "model/gerarchia/bimode.h"
#include "model/gerarchia/maglev.h"
#include "model/gerarchia/steam.h"
#include <algorithm>
#include <cctype>
#include <iostream>
using std::string;
using std::cerr;
using std::cout;

Treno::Treno(const string & n, const string & c, unsigned int s, Trotaia tr, Ttreno tt):
    nome(n), costruttore(c),speed(s),tipo_rotaia(tr),tipo_treno(tt){}

string Treno::getNome() const
{
    return nome;
}

string Treno::getCostruttore() const
{
    return costruttore;
}

unsigned int Treno::getSpeed() const
{
    return speed;
}

string Treno::getTipo_rotaia() const
{
    if(tipo_rotaia==Trotaia::maglev)            return "Maglev";
    if(tipo_rotaia==Trotaia::strap)             return "Strap";
    if(tipo_rotaia==Trotaia::plate)             return "Plate";
    if(tipo_rotaia==Trotaia::bridge)            return "Bridge";
    if(tipo_rotaia==Trotaia::barlow)            return "Barlow";
    if(tipo_rotaia==Trotaia::flat_bottomed)     return "Flat Bottomed";
    if(tipo_rotaia==Trotaia::double_headed)     return "Double Headed";
    if(tipo_rotaia==Trotaia::bullhead)          return "Bullhead";
    return "NoType";
}

string Treno::getTipo_treno() const
{
    if(tipo_treno==Ttreno::commuter)        return "Commuter";
    if(tipo_treno==Ttreno::regionale)       return "Regionale";
    if(tipo_treno==Ttreno::inter_city)      return "Inner City";
    if(tipo_treno==Ttreno::alta_velocita)   return "Alta velocita'";
    return "NoType";
}

void Treno::setNome(string n)
{
    nome=n;
}

void Treno::setCostruttore(string b)
{
    costruttore=b;
}

void Treno::setSpeed(unsigned int s)
{
    speed=s;
}

void Treno::setTipo_rotaia(string tr)
{
    transform(tr.begin(), tr.end(), tr.begin(),
        [](unsigned char c){ return tolower(c); });
    //porta la stringa tutta lowercase

    if(tr=="maglev" || tr=="strap" || tr=="plate" || tr=="bridge" || tr=="barlow" || tr=="flat_bottomed" || tr=="double_headed" || tr=="bullhead"){
        if(tr=="maglev")            tipo_rotaia=Trotaia::maglev;
        if(tr=="strap")             tipo_rotaia=Trotaia::strap;
        if(tr=="plate")             tipo_rotaia=Trotaia::plate;
        if(tr=="bridge")            tipo_rotaia=Trotaia::bridge;
        if(tr=="barlow")            tipo_rotaia=Trotaia::barlow;
        if(tr=="flat_bottomed")     tipo_rotaia=Trotaia::flat_bottomed;
        if(tr=="double_headed")     tipo_rotaia=Trotaia::double_headed;
        if(tr=="bullhead")          tipo_rotaia=Trotaia::bullhead;
    }

}

void Treno::setTipo_treno(string tt)
{
    transform(tt.begin(), tt.end(), tt.begin(),
        [](unsigned char c){ return tolower(c); });
    //porta la stringa tutta lowercase
    if(tt=="alta_velocita" || tt=="inter_city" || tt=="regionale" || tt=="commuter"){
        if(tt=="alta_velocita")         tipo_treno=Ttreno::alta_velocita;
        if(tt=="inter_city")            tipo_treno=Ttreno::inter_city;
        if(tt=="regionale")             tipo_treno=Ttreno::regionale;
        if(tt=="commuter")              tipo_treno=Ttreno::commuter;

    }

}

string Treno::type() const
{
 return "Treno";
}

void Treno::print() const
{


    string tr=type();
    transform(tr.begin(), tr.end(), tr.begin(),
        [](unsigned char c){ return toupper(c); });
    cout<<"\nTipo: "<<tr<<"\nNome: "<<getNome()<<"\nCostruttore: "<<getCostruttore()<<"\nVelocita': "<<getSpeed()<<"km/h\nTipo Rotaia: "<<getTipo_rotaia()<<"\nTipo Treno: "<<getTipo_treno();
}

Treno *Treno::unserialize(QJsonObject & json)
{
    Treno* t=nullptr;
    string type=json["type"].toString().toStdString();
    if(type=="Steam" || type=="Maglev" || type=="Internal_Combustion" || type=="Electric" || type=="Bimode"){

        string nome=json["nome"].toString().toStdString();
        string builder=json["builder"].toString().toStdString();
        int speed0=json["speed"].toInt();
        unsigned int speed=100;
        if(speed0>=0)   speed=speed0;
        string tiporotaia=json["tipo_rotaia"].toString().toStdString();
        string tipotreno=json["tipo_treno"].toString().toStdString();

        if(type=="Steam"){
            string tipo_carburanteSteam=json["tipo_carburanteSteam"].toString().toStdString();
            double efficenzaSteam=(json["efficenzaSteam"].toDouble());
            t=new Steam();
            t->setNome(nome);
            t->setCostruttore(builder);
            t->setSpeed(speed);
            t->setTipo_rotaia(tiporotaia);
            t->setTipo_treno(tipotreno);
            static_cast<Steam*>(t)->setEfficenzaSteam(efficenzaSteam);
            static_cast<Steam*>(t)->setCarburanteSteam(tipo_carburanteSteam);
        }
        if(type=="Maglev"){
            string tipotecnologia=json["tipo_tecnologia"].toString().toStdString();
            t=new Maglev();
            t->setNome(nome);
            t->setCostruttore(builder);
            t->setSpeed(speed);
            t->setTipo_rotaia(tiporotaia);
            t->setTipo_treno(tipotreno);
            static_cast<Maglev*>(t)->setTecnologia(tipotecnologia);
        }
        if(type=="Internal_Combustion"){
            double efficenzaIC=(json["efficenzaIC"].toDouble());
            string tipocarburanteIC=json["tipo_carburanteIC"].toString().toStdString();
            string tipotrasmissioneIC=json["tipo_trasmissioneIC"].toString().toStdString();
            t=new Internal_Combustion();
            t->setNome(nome);
            t->setCostruttore(builder);
            t->setSpeed(speed);
            t->setTipo_rotaia(tiporotaia);
            t->setTipo_treno(tipotreno);
            dynamic_cast<Internal_Combustion*>(t)->setEfficenzaIC(efficenzaIC);
            dynamic_cast<Internal_Combustion*>(t)->setCarburanteIC(tipocarburanteIC);
            dynamic_cast<Internal_Combustion*>(t)->setTrasmissioneIC(tipotrasmissioneIC);
        }
        if(type=="Electric"){
            double efficenzaElettrico=(json["efficenzaElettrico"].toDouble());
            string tipotrasmissioneElettrico=json["tipo_trasmissioneElettrico"].toString().toStdString();
            t=new Electric();
            t->setNome(nome);
            t->setCostruttore(builder);
            t->setSpeed(speed);
            t->setTipo_rotaia(tiporotaia);
            t->setTipo_treno(tipotreno);
            dynamic_cast<Electric*>(t)->setEfficenzaElettrico(efficenzaElettrico);
            dynamic_cast<Electric*>(t)->setTrasmissioneElettrico(tipotrasmissioneElettrico);

        }
        if(type=="Bimode"){
            double efficenzaElettrico=(json["efficenzaElettrico"].toDouble());
            string tipotrasmissioneElettrico=json["tipo_trasmissioneElettrico"].toString().toStdString();
            double efficenzaIC=(json["efficenzaIC"].toDouble());
            string tipocarburanteIC=json["tipo_carburanteIC"].toString().toStdString();
            string tipotrasmissioneIC=json["tipo_trasmissioneIC"].toString().toStdString();
            string motoreprimario=json["motore_primario"].toString().toStdString();
            t=new Bimode();
            t->setNome(nome);
            t->setCostruttore(builder);
            t->setSpeed(speed);
            t->setTipo_rotaia(tiporotaia);
            t->setTipo_treno(tipotreno);
            dynamic_cast<Bimode*>(t)->setEfficenzaElettrico(efficenzaElettrico);
            dynamic_cast<Bimode*>(t)->setTrasmissioneElettrico(tipotrasmissioneElettrico);
            dynamic_cast<Bimode*>(t)->setEfficenzaIC(efficenzaIC);
            dynamic_cast<Bimode*>(t)->setCarburanteIC(tipocarburanteIC);
            dynamic_cast<Bimode*>(t)->setTrasmissioneIC(tipotrasmissioneIC);
            dynamic_cast<Bimode*>(t)->setMotorePrimario(motoreprimario);
        }
    }else{
        //eccezione
        cerr<<"tipo non valido";
    }
    return t;
}
