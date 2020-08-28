#ifndef INTERNAL_COMBUSTION_H
#define INTERNAL_COMBUSTION_H
#include "model/gerarchia/treno.h"

class Internal_Combustion: virtual public Treno {
protected:
    enum Tfuel {kerosene, petrol, diesel};
    double efficenzaIC; // km/l
    Tfuel carburanteIC;

public:
    Internal_Combustion(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100, unsigned int =100, double efficenza=0.5, Tfuel =Tfuel::kerosene);

    double getEfficenzaIC() const;
    std::string getCarburanteIC() const;

    void setEfficenzaIC(double);
    void setCarburanteIC(std::string);


    virtual double carburanteNecessario(unsigned int) const; //input km
    virtual unsigned int kmPercorribili(unsigned int) const; //input l fuel
    std::string type() const;
    void print() const;
    std::string treno2string() const;
    virtual void serialize(QJsonObject&);
};

#endif // INTERNAL_COMBUSTION_H
