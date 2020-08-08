#ifndef MAGLEV_H
#define MAGLEV_H
#include "treno.h"

enum Ttech {
  eds, ems
};

class Maglev: public Treno {
private:
    Ttech tecnologia;
public:
    Maglev(const std::string& = "NoName", unsigned int =10, const std::string& ="NoBuilder", unsigned int =100, Trotaia =Trotaia::maglev, Ttreno =Ttreno::alta_velocita, Ttech =Ttech::eds);

    Ttech getTecnologia() const;

    void setTecnologia(std::string);

    Maglev* clone() const;
    float carburanteNecessario(unsigned int) const;
    unsigned int kmPercorribili(unsigned int) const;

};

#endif // MAGLEV_H
