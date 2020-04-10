#ifndef TELEFONATA_H
#define TELEFONATA_H
#include <iostream>
#include "orario.h"
#include <string>

using std::ostream;

class telefonata
{
private:
    orario inizio, fine;
   // int numero;
    std::string numero;
public:
    telefonata();
    telefonata(orario, orario, std::string);
    orario Inizio() const;
    orario Fine() const;
    std::string Numero() const;
    bool operator==(const telefonata&) const;
};

ostream& operator<<(ostream&, const telefonata&);
#endif // TELEFONATA_H
