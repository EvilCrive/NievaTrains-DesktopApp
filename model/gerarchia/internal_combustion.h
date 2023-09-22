#ifndef INTERNAL_COMBUSTION_H
#define INTERNAL_COMBUSTION_H
#include "model/gerarchia/treno.h"

class Internal_Combustion: virtual public Treno {
protected:
    unsigned int potenzaIC;
    std::string motoreIC;

public:
    Internal_Combustion(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100, unsigned int =100, unsigned int =1000, std::string ="diesel");

    unsigned int getPotenzaIC() const;
    std::string getMotoreIC() const;

    void setPotenzaIC(unsigned int);
    void setMotoreIC(std::string);


    double carburanteNecessario(unsigned int) const; //input km
    unsigned int kmPercorribili(unsigned int) const; //input l fuel
    std::string type() const;
    void print() const;
    std::string treno2string() const;
    virtual void serialize(QJsonObject&);
};

#endif // INTERNAL_COMBUSTION_H
