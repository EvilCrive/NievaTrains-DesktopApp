#ifndef ELECTRIC_H
#define ELECTRIC_H
#include "model/gerarchia/treno.h"



class Electric: virtual public Treno {
protected:
    enum TtrasmissioneElettrico {
        overhead_lines, third_rail
    };
private:
    TtrasmissioneElettrico trasmissioneElettrico;
protected:
    float efficenzaElettrico;
public:
    Electric(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100, Trotaia =Trotaia::maglev, Ttreno =Ttreno::alta_velocita,  TtrasmissioneElettrico =TtrasmissioneElettrico::overhead_lines, float =0.7f);

    std::string getTrasmissioneElettrico() const;
    float getEfficenzaElettrico() const;

    void setTrasmissioneElettrico(std::string);
    void setEfficenzaElettrico(float);

    float carburanteNecessario(unsigned int) const;  //input km da percorrere
    unsigned int kmPercorribili(unsigned int) const; //input kw di carburante
    std::string type() const;
    void print() const;
    // Electric* clone() const;
};

#endif // ELECTRIC_H
