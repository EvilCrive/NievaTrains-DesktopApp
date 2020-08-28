#ifndef ELECTRIC_H
#define ELECTRIC_H
#include "model/gerarchia/treno.h"

class Electric: virtual public Treno {

private:
    double efficenzaElettrico;
    bool trasmissioneElettrico;
public:
    Electric(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100,  unsigned int p=100, bool =false, double =0.7);

    bool getTrasmissioneElettrico() const;
    double getEfficenzaElettrico() const;

    void setTrasmissioneElettrico(bool);
    void setEfficenzaElettrico(double);

    virtual double carburanteNecessario(unsigned int) const;  //input km da percorrere
    virtual unsigned int kmPercorribili(unsigned int) const; //input kw di carburante
    std::string type() const;
    void print() const;
    std::string treno2string() const;
    virtual void serialize(QJsonObject&);
};

#endif // ELECTRIC_H
