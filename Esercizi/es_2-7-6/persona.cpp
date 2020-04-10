#include "persona.h"

Persona::Persona(std::string name):nome(name){}

Persona::Persona(std::string name, std::string yearborn, std::string yeardeath):nome(name),anno_nascita(yearborn),anno_morte(yeardeath){}

std::string Persona::Nome() const
{
    return nome;
}

std::string Persona::AnnoNascita() const
{
    return anno_nascita;
}

std::string Persona::AnnoMorte() const
{
    return anno_morte;
}




std::ostream &operator<<(std::ostream & os, const Persona & p)
{
    os<<"Questa persona e' "<<p.Nome();
    if(p.AnnoNascita()!="") os<<", nata il "<<p.AnnoNascita();
    if(p.AnnoMorte()!="") os<<", morta il "<<p.AnnoMorte();
    return os<<".\n";
}
