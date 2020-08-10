#include "model/gerarchia/treno.h"
#include <algorithm>
#include <cctype>
#include <iostream>

Treno::Treno(const std::string & n, const std::string & c, unsigned int s, Trotaia tr, Ttreno tt):
    nome(n), costruttore(c),speed(s),tipo_rotaia(tr),tipo_treno(tt){}

std::string Treno::getNome() const
{
    return nome;
}

std::string Treno::getCostruttore() const
{
    return costruttore;
}

unsigned int Treno::getSpeed() const
{
    return speed;
}

std::string Treno::getTipo_rotaia() const
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

std::string Treno::getTipo_treno() const
{
    if(tipo_treno==Ttreno::commuter)        return "Commuter";
    if(tipo_treno==Ttreno::regionale)       return "Regionale";
    if(tipo_treno==Ttreno::inter_city)      return "Inner City";
    if(tipo_treno==Ttreno::alta_velocita)   return "Alta velocita'";
    return "NoType";
}

void Treno::setNome(std::string n)
{
    nome=n;
}

void Treno::setCostruttore(std::string b)
{
    costruttore=b;
}

void Treno::setSpeed(unsigned int s)
{
    speed=s;
}

void Treno::setTipo_rotaia(std::string tr)
{
    std::transform(tr.begin(), tr.end(), tr.begin(),
        [](unsigned char c){ return std::tolower(c); });
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

void Treno::setTipo_treno(std::string tt)
{
    std::transform(tt.begin(), tt.end(), tt.begin(),
        [](unsigned char c){ return std::tolower(c); });
    //porta la stringa tutta lowercase
    if(tt=="alta_velocita" || tt=="inter_city" || tt=="regionale" || tt=="commuter"){
        if(tt=="alta_velocita")         tipo_treno=Ttreno::alta_velocita;
        if(tt=="inter_city")            tipo_treno=Ttreno::inter_city;
        if(tt=="regionale")             tipo_treno=Ttreno::regionale;
        if(tt=="commuter")              tipo_treno=Ttreno::commuter;

    }

}

std::string Treno::type() const
{
 return "Treno";
}

void Treno::print() const
{


    std::string tr=type();
    std::transform(tr.begin(), tr.end(), tr.begin(),
        [](unsigned char c){ return std::toupper(c); });
    std::cout<<"\nTipo: "<<tr<<"\nNome: "<<getNome()<<"\nCostruttore: "<<getCostruttore()<<"\nVelocita': "<<getSpeed()<<"km/h\nTipo Rotaia: "<<getTipo_rotaia()<<"\nTipo Treno: "<<getTipo_treno();
}
