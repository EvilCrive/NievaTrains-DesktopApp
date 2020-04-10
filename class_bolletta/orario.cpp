#include "orario.h"

orario::orario(int o, int m, int s){
    if(o<0 || o>23 || m<0 || m>59 || s<0 || s>59)
        sec = 0;
    else
        sec = o * 3600 + m * 60 + s;
}

int orario::Ore() const
{
    return sec/3600;
}

int orario::Minuti() const
{
    return (sec/60)%60;
}

int orario::Secondi() const
{
    return sec%60;
}

int orario::sec_giorno=86400;

void orario::AvanzaUnOra()
{
    sec= (sec+3600)%sec_giorno;
}

orario orario::UnOraPiuTardi() const
{
    orario r;
    r.sec=(sec+3600)%sec_giorno;
    return r;
}

void orario::StampaSecondi() const
{
    std::cout<<sec<<std::endl;
}

orario orario::OraDiPranzo()
{
    return orario(13,30);
}

orario orario::operator+(const orario & o) const
{
    orario r;
    r.sec=(sec+o.sec)%sec_giorno;
    return r;
}

orario orario::operator-(const orario & o) const
{
    orario r;
    r.sec=(sec-o.sec)%sec_giorno;
    if(r.sec<0) r.sec=0;
    return r;
}

bool orario::operator<(const orario & o) const
{
    return sec<o.sec;
}

bool orario::operator>(const orario & o) const
{
    return sec>o.sec;
}

bool orario::operator==(const orario & o) const
{
    return sec==o.sec;
}

std::ostream& operator<<(std::ostream& os,const orario& o){
    return os<<"Sono le ore "<<o.Ore()<<":"<<o.Minuti()<<":"<<o.Secondi();
}










