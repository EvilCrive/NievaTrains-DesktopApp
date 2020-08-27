#include "model/gerarchia/bimode.h"
#include "model/gerarchia/maglev.h"
#include "model/gerarchia/steam.h"
#include <algorithm>
#include <cctype>
#include <iostream>
using std::string;
using std::cerr;
using std::cout;

Treno::Treno(const string & n, const string & c, unsigned int s, unsigned int p):
    nome(n), costruttore(c),speed(s), peso(p){}

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

unsigned int Treno::getPeso() const
{
    return peso;
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

void Treno::setPeso(unsigned int p)
{
    peso=p;
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
    cout<<"\nTipo: "<<tr<<"\nNome: "<<getNome()<<"\nCostruttore: "<<getCostruttore()<<"\nVelocita': "<<getSpeed()<<"km/h";
}
std::string Treno::treno2string()const{
    string tr=type();
    transform(tr.begin(), tr.end(), tr.begin(),
        [](unsigned char c){ return toupper(c); });
    std::string s="\nTipo: "+tr+"\nNome: "+getNome()+"\nCostruttore: "+getCostruttore()+"\nVelocita': "+std::to_string(getSpeed())+"km/h"+"\nPeso: "+std::to_string(getPeso())+"kg";
    return s;
}

Treno *Treno::unserialize(QJsonObject & json)
{
    Treno* t=nullptr;
    string type=json["type"].toString().toStdString();
    if(type=="Steam" || type=="Maglev" || type=="Internal_Combustion" || type=="Electric" || type=="Bimode"){

        string nome=json["nome"].toString().toStdString();
        string builder=json["builder"].toString().toStdString();
        int speed0=json["speed"].toInt();
        int peso0=json["peso"].toInt();
        unsigned int peso=40;
        unsigned int speed=100;
        if(peso0>=0)    peso=peso0;
        if(speed0>=0)   speed=speed0;

        if(type=="Steam"){
            string tipo_carburanteSteam=json["tipo_carburanteSteam"].toString().toStdString();
            double efficenzaSteam=(json["efficenzaSteam"].toDouble());
            t=new Steam();
            t->setNome(nome);
            t->setCostruttore(builder);
            t->setSpeed(speed);
            t->setPeso(peso);
            static_cast<Steam*>(t)->setEfficenzaSteam(efficenzaSteam);
            static_cast<Steam*>(t)->setCarburanteSteam(tipo_carburanteSteam);
        }
        if(type=="Maglev"){
            string tipotecnologia=json["tipo_tecnologia"].toString().toStdString();
            t=new Maglev();
            t->setNome(nome);
            t->setCostruttore(builder);
            t->setSpeed(speed);
            t->setPeso(peso);
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
            t->setPeso(peso);
            dynamic_cast<Internal_Combustion*>(t)->setEfficenzaIC(efficenzaIC);
            dynamic_cast<Internal_Combustion*>(t)->setCarburanteIC(tipocarburanteIC);
        }
        if(type=="Electric"){
            double efficenzaElettrico=(json["efficenzaElettrico"].toDouble());
            string tipotrasmissioneElettrico=json["tipo_trasmissioneElettrico"].toString().toStdString();
            t=new Electric();
            t->setNome(nome);
            t->setCostruttore(builder);
            t->setSpeed(speed);
            t->setPeso(peso);
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
            t->setPeso(peso);
            dynamic_cast<Bimode*>(t)->setEfficenzaElettrico(efficenzaElettrico);
            dynamic_cast<Bimode*>(t)->setTrasmissioneElettrico(tipotrasmissioneElettrico);
            dynamic_cast<Bimode*>(t)->setEfficenzaIC(efficenzaIC);
            dynamic_cast<Bimode*>(t)->setCarburanteIC(tipocarburanteIC);
            dynamic_cast<Bimode*>(t)->setMotorePrimario(motoreprimario);
        }
    }else{
        //eccezione
        cerr<<"tipo non valido";
    }
    return t;
}
