#ifndef INTERNAL_COMBUSTION_H
#define INTERNAL_COMBUSTION_H
#include "model/gerarchia/treno.h"

class Internal_Combustion: virtual public Treno {
protected:
    enum TtrasmissioneFuel {electric, mechanical, hydraulic, steam, pneumatic};
    enum Tfuel {kerosene, petrol, diesel};
    double efficenzaIC; // km/l
private:
    Tfuel carburanteIC;
    TtrasmissioneFuel trasmissioneIC;
public:
    Internal_Combustion(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100, Trotaia =Trotaia::maglev, Ttreno =Ttreno::alta_velocita, double =0.7, Tfuel =Tfuel::kerosene, TtrasmissioneFuel =TtrasmissioneFuel::electric );

    double getEfficenzaIC() const;
    std::string getCarburanteIC() const;
    std::string getTrasmissioneIC() const;

    void setEfficenzaIC(double);
    void setCarburanteIC(std::string);
    void setTrasmissioneIC(std::string);

    virtual double carburanteNecessario(unsigned int) const; //input km
    virtual unsigned int kmPercorribili(unsigned int) const; //input l fuel
    std::string type() const;
    void print() const;
    std::string print2() const;
    virtual void serialize(QJsonObject&);
};

#endif // INTERNAL_COMBUSTION_H
