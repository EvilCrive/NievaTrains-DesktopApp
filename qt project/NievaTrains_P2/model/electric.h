#ifndef ELECTRIC_H
#define ELECTRIC_H
#include "treno.h"

enum Ttrasmission {
    overhead_lines, third_rail
};

class Electric: virtual public Treno {
private:
    Ttrasmission trasmissione;
    float potenzaNecessaria;
public:
    Electric();
    virtual ~Electric() = default;
    virtual Electric* clone() const = 0;

    Ttrasmission getTrasmissione() const;
    float getPotenzaNecessaria() const;

    void setTrasmissione(std::string trasmissione);
    void setPotenzaNecessaria(float potenzaNecessaria);
};

#endif // ELECTRIC_H
