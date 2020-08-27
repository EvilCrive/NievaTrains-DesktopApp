#include "model/gerarchia/bimode.h"
#include "model/gerarchia/maglev.h"
#include "model/gerarchia/steam.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <QJsonParseError>
#include "view/supporto/nievaexception.h"

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

//lista eccezioni
Treno *Treno::unserialize(QJsonObject & json){
    Treno* t=nullptr;
    string type=json["type"].toString().toStdString();
    //eccezione
    if(!(type=="Steam" || type=="Maglev" || type=="Internal_Combustion" || type=="Electric" || type=="Bimode"))
        throw new NievaException("Valore illegale su Type");

    //campi dati di treno e eccezione relative
    string nome, builder;unsigned int speed,peso;

    if(json["nome"].isString()) nome=json["nome"].toString().toStdString();
    else    throw new NievaException("Valore illegale su Nome");
    if(json["builder"].isString()) builder=json["builder"].toString().toStdString();
    else    throw new NievaException("Valore illegale su Costruttore");
    if((json["speed"]).isDouble() && json["speed"].toInt()>=0)  speed=json["speed"].toInt();
    else    throw new NievaException("Valore illegale su Velocita'");
    if((json["peso"]).isDouble() && json["peso"].toInt()>=0)  peso=json["peso"].toInt();
    else    throw new NievaException("Valore illegale su Peso'");

    if(type=="Steam"){
        //campi dati di steam e eccezione relative
        string tipo_carburanteSteam;double efficenzaSteam;

        if(json["tipo_carburanteSteam"].isString())
            tipo_carburanteSteam=json["tipo_carburanteSteam"].toString().toStdString();
        else    throw new NievaException("Valore illegale su tipo_carburante_Steam");
        if(json["efficenzaSteam"].isDouble())   efficenzaSteam=(json["efficenzaSteam"].toDouble());
        else    throw new NievaException("Valore illegale su efficenzaSteam");

        t=new Steam();
        static_cast<Steam*>(t)->setEfficenzaSteam(efficenzaSteam);
        static_cast<Steam*>(t)->setCarburanteSteam(tipo_carburanteSteam);
    }
    if(type=="Maglev"){
        string tipotecnologia;

        if(json["tipo_tecnologia"].isString())  tipotecnologia=json["tipo_tecnologia"].toString().toStdString();
        else    throw new NievaException("Valore illegale su tipo_tecnologia");

        t=new Maglev();
        static_cast<Maglev*>(t)->setTecnologia(tipotecnologia);
    }
    if(type=="Internal_Combustion"){
        double efficenzaIC;string tipocarburanteIC, tipotrasmissioneIC;

        if(json["efficenzaIC"].isDouble())  efficenzaIC=(json["efficenzaIC"].toDouble());
        else    throw new NievaException("Valore illegale su efficenzaIC");
        if(json["tipo_carburanteIC"].isString())    tipocarburanteIC=json["tipo_carburanteIC"].toString().toStdString();
        else    throw new NievaException("Valore illegale su tipo_carburanteIC");

        t=new Internal_Combustion();
        dynamic_cast<Internal_Combustion*>(t)->setEfficenzaIC(efficenzaIC);
        dynamic_cast<Internal_Combustion*>(t)->setCarburanteIC(tipocarburanteIC);
    }
    if(type=="Electric"){
        double efficenzaElettrico;string tipotrasmissioneElettrico;

        if(json["tipo_trasmissioneElettrico"].isString())   tipotrasmissioneElettrico=json["tipo_trasmissioneElettrico"].toString().toStdString();
        else    throw new NievaException("Valore illegale su tipo_trasmissioneElettrico");
        if(json["efficenzaElettrico"].isDouble())   efficenzaElettrico=(json["efficenzaElettrico"].toDouble());
        else    throw new NievaException("Valore illegale su efficenzaElettrico");

        t=new Electric();
        dynamic_cast<Electric*>(t)->setEfficenzaElettrico(efficenzaElettrico);
        dynamic_cast<Electric*>(t)->setTrasmissioneElettrico(tipotrasmissioneElettrico);
    }
    if(type=="Bimode"){
        double efficenzaElettrico,efficenzaIC;string tipotrasmissioneElettrico,tipocarburanteIC,tipotrasmissioneIC,motorePrimario;

        if(json["tipo_trasmissioneElettrico"].isString())   tipotrasmissioneElettrico=json["tipo_trasmissioneElettrico"].toString().toStdString();
        else    throw new NievaException("Valore illegale su tipo_trasmissioneElettrico");
        if(json["efficenzaElettrico"].isDouble())   efficenzaElettrico=(json["efficenzaElettrico"].toDouble());
        else    throw new NievaException("Valore illegale su efficenzaElettrico");
        if(json["efficenzaIC"].isDouble())  efficenzaIC=(json["efficenzaIC"].toDouble());
        else    throw new NievaException("Valore illegale su efficenzaIC");
        if(json["tipo_carburanteIC"].isString())    tipocarburanteIC=json["tipo_carburanteIC"].toString().toStdString();
        else    throw new NievaException("Valore illegale su tipo_carburanteIC");
        if(json["motore_primario"].isString())  motorePrimario=json["motore_primario"].toString().toStdString();
        else    throw new NievaException("Valore illegale su motorePrimario");

        t=new Bimode();
        dynamic_cast<Bimode*>(t)->setEfficenzaElettrico(efficenzaElettrico);
        dynamic_cast<Bimode*>(t)->setTrasmissioneElettrico(tipotrasmissioneElettrico);
        dynamic_cast<Bimode*>(t)->setEfficenzaIC(efficenzaIC);
        dynamic_cast<Bimode*>(t)->setCarburanteIC(tipocarburanteIC);
        dynamic_cast<Bimode*>(t)->setMotorePrimario(motorePrimario);
    }
    t->setNome(nome);
    t->setCostruttore(builder);
    t->setSpeed(speed);
    t->setPeso(peso);
    return t;

}
