#ifndef ELECTRIC_H
#define ELECTRIC_H
#include "treno.h"

enum Ttrasmission {
    overhead_lines, third_rail
};

class Electric: virtual public Treno {
private:
    Ttrasmission trasmissione;
    float efficenza;
public:
    Electric(const std::string& = "NoName", unsigned int =10, const std::string& ="NoBuilder", unsigned int =100, Trotaia =Trotaia::maglev, Ttreno =Ttreno::alta_velocita,  Ttrasmission =Ttrasmission::overhead_lines, float =7);

    Ttrasmission getTrasmissione() const;
    float getEfficenza() const;

    void setTrasmissione(std::string);
    void setEfficenza(float);

    float carburanteNecessario(unsigned int) const;  //input km da percorrere
    unsigned int kmPercorribili(unsigned int) const; //input kw di carburante
 // Electric* clone() const = 0;
};

#endif // ELECTRIC_H
