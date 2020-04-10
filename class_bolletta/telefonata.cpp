#include "telefonata.h"

telefonata::telefonata()
{
    numero="0";
}

telefonata::telefonata(orario i, orario f, std::string n)
{
    inizio=i; fine=f; numero=n;
}

orario telefonata::Inizio() const
{
    return inizio;
}

orario telefonata::Fine() const
{return fine;}

std::string telefonata::Numero() const
{
    return numero;
}

bool telefonata::operator==(const telefonata & t) const
{
    return inizio==t.inizio && fine==t.fine && numero==t.numero;
}

std::ostream &operator<<(std::ostream & os, const telefonata & t)
{
    return os<<"INIZIO "<<t.Inizio()<<" FINE "<<t.Fine()<<" NUMERO CHIAMATO "<<t.Numero()<<std::endl;
}
