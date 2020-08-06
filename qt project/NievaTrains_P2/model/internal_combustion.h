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
    float efficenza; // km/l
    Tfuel carburante;
    Ttrasmissione trasmissione;
public:
    Internal_Combustion(const std::string& = "NoName", unsigned int =10, const std::string& ="NoBuilder", unsigned int =100, Trotaia =Trotaia::maglev, Ttreno =Ttreno::alta_velocita, float =7, Tfuel =Tfuel::kerosene, Ttrasmissione =Ttrasmissione::electric );

    float getEfficenza() const;
    Tfuel getCarburante() const;
    Ttrasmissione getTrasmissione() const;

    void setEfficenza(float);
    void setCarburante(std::string);
    void setTrasmissione(std::string);

    float carburanteNecessario(unsigned int) const; //input km
    unsigned int kmPercorribili(unsigned int) const; //input l fuel
//  Internal_Combustion* clone() const = 0;
};

#endif // INTERNAL_COMBUSTION_H
