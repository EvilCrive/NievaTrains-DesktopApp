#ifndef INTERNAL_COMBUSTION_H
#define INTERNAL_COMBUSTION_H
#include "model/gerarchia/treno.h"

enum TtrasmissioneFuel {
    electric, mechanical, hydraulic, steam, pneumatic
};
enum Tfuel {
    kerosene, petrol, diesel
};

class Internal_Combustion: virtual public Treno {
private:
    Tfuel carburanteIC;
    TtrasmissioneFuel trasmissioneIC;
protected:
        float efficenzaIC; // km/l
public:
    Internal_Combustion(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100, Trotaia =Trotaia::maglev, Ttreno =Ttreno::alta_velocita, float =0.7f, Tfuel =Tfuel::kerosene, TtrasmissioneFuel =TtrasmissioneFuel::electric );

    float getEfficenzaIC() const;
    std::string getCarburanteIC() const;
    std::string getTrasmissioneIC() const;

    void setEfficenzaIC(float);
    void setCarburanteIC(std::string);
    void setTrasmissioneIC(std::string);

    float carburanteNecessario(unsigned int) const; //input km
    unsigned int kmPercorribili(unsigned int) const; //input l fuel
    std::string type() const;
    void print() const;
    //Internal_Combustion* clone() const;
};

#endif // INTERNAL_COMBUSTION_H
