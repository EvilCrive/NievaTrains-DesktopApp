#ifndef INTERNAL_COMBUSTION_H
#define INTERNAL_COMBUSTION_H
#include "treno.h"

enum Ttrasmissione {
    electric, mechanical, hydraulic, steam, pneumatic
};
enum Tfuel {
    kerosene, petrol, diesel
};

class Internal_Combustion: virtual public Treno {
private:
    float efficenza;
    Tfuel carburante;
    Ttrasmissione trasmissione;
public:
    Internal_Combustion();
    virtual ~Internal_Combustion() = default;
    virtual Internal_Combustion* clone() const = 0;

    float getEfficenza() const;
    Tfuel getCarburante() const;
    Ttrasmissione getTrasmissione() const;

    void setEfficenza(float efficenza);
    void setCarburante(std::string carburante);
    void setTrasmissione(std::string trasmissione);
};

#endif // INTERNAL_COMBUSTION_H
