#ifndef ELECTRIC_H
#define ELECTRIC_H
#include "model/gerarchia/treno.h"

class Electric: virtual public Treno {
protected:
    enum TtrasmissioneElettrico {overhead_lines, third_rail};
private:
    TtrasmissioneElettrico trasmissioneElettrico;
protected:
    double efficenzaElettrico;
public:
    Electric(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100, Trotaia =Trotaia::maglev, Ttreno =Ttreno::alta_velocita,  TtrasmissioneElettrico =TtrasmissioneElettrico::overhead_lines, double =0.7);

    std::string getTrasmissioneElettrico() const;
    double getEfficenzaElettrico() const;

    void setTrasmissioneElettrico(std::string);
    void setEfficenzaElettrico(double);

    virtual double carburanteNecessario(unsigned int) const;  //input km da percorrere
    virtual unsigned int kmPercorribili(unsigned int) const; //input kw di carburante
    std::string type() const;
    void print() const;
    std::string print2() const;
    virtual void serialize(QJsonObject&);
};

#endif // ELECTRIC_H
