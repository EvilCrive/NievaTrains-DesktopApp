#ifndef INTERNAL_COMBUSTION_H
#define INTERNAL_COMBUSTION_H
#include "treno.h"

enum TtrasmissioneFuel {
    electric, mechanical, hydraulic, steam, pneumatic
};
enum Tfuel {
    kerosene, petrol, diesel
};

class Internal_Combustion: virtual public Treno {
private:
    Tfuel carburante;
    TtrasmissioneFuel trasmissione;
protected:
        float efficenzaFuel; // km/l
public:
    Internal_Combustion(const std::string& = "NoName", unsigned int =10, const std::string& ="NoBuilder", unsigned int =100, Trotaia =Trotaia::maglev, Ttreno =Ttreno::alta_velocita, float =0.7f, Tfuel =Tfuel::kerosene, TtrasmissioneFuel =TtrasmissioneFuel::electric );

    float getEfficenza() const;
    std::string getCarburante() const;
    std::string getTrasmissione() const;

    void setEfficenza(float);
    void setCarburante(std::string);
    void setTrasmissione(std::string);

    float carburanteNecessario(unsigned int) const; //input km
    unsigned int kmPercorribili(unsigned int) const; //input l fuel
    std::string type() const;
    void print() const;
    //Internal_Combustion* clone() const;
};

#endif // INTERNAL_COMBUSTION_H
