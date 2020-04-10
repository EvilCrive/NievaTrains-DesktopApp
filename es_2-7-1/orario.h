#ifndef ORARIO_H
#define ORARIO_H
#include <iostream>

class orario
{
private:
    int sec;
    static int sec_giorno;
public:

    orario(int =0, int =0, int =0);
    int Ore() const;
    int Minuti() const;
    int Secondi() const;
    void AvanzaUnOra();
    orario UnOraPiuTardi() const;
    void StampaSecondi() const;
    static orario OraDiPranzo();

    orario operator+(const orario&) const;
    orario operator-(const orario&) const;
    bool operator<(const orario&) const;
    bool operator>(const orario&) const;
    bool operator==(const orario&) const;
};

std::ostream& operator<<(std::ostream&,const orario&);
#endif // ORARIO_H
