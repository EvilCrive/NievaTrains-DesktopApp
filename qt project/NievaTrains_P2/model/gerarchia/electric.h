#ifndef ELECTRIC_H
#define ELECTRIC_H
#include "model/gerarchia/treno.h"

class Electric: virtual public Treno {
protected:
    enum TtrasmissioneElettrico {overhead_lines, third_rail};
    double efficenzaElettrico;
private:
    TtrasmissioneElettrico trasmissioneElettrico;
public:
    Electric(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100,  unsigned int p=100, TtrasmissioneElettrico =TtrasmissioneElettrico::overhead_lines, double =0.7);

    std::string getTrasmissioneElettrico() const;
    double getEfficenzaElettrico() const;

    void setTrasmissioneElettrico(std::string);
    void setEfficenzaElettrico(double);

    virtual double carburanteNecessario(unsigned int) const;  //input km da percorrere
    virtual unsigned int kmPercorribili(unsigned int) const; //input kw di carburante
    std::string type() const;
    void print() const;
    std::string treno2string() const;
    virtual void serialize(QJsonObject&);
};

#endif // ELECTRIC_H
