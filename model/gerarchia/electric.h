#ifndef ELECTRIC_H
#define ELECTRIC_H
#include "model/gerarchia/treno.h"

class Electric: virtual public Treno {

protected:
    double efficenzaElettrico;
    bool trasmissioneElettrico;
public:
    Electric(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100,  unsigned int p=100, bool =false, double =0.7);

    bool getTrasmissioneElettrico() const;
    double getEfficenzaElettrico() const;

    void setTrasmissioneElettrico(bool);
    void setEfficenzaElettrico(double);

    double carburanteNecessario(unsigned int) const;  //input km da percorrere
    unsigned int kmPercorribili(unsigned int) const; //input kw di carburante
    std::string type() const;
    void print() const;
    std::string treno2string() const;
    virtual void serialize(QJsonObject&);
};

#endif // ELECTRIC_H
