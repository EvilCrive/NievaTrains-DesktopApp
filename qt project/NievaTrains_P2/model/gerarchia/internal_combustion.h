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
    Tfuel carburante;
    Ttrasmissione trasmissione;
protected:
        float efficenzaFuel; // km/l
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
    //Internal_Combustion* clone() const;
};

#endif // INTERNAL_COMBUSTION_H
