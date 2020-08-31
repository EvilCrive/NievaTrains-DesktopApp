#ifndef MAGLEV_H
#define MAGLEV_H
#include "model/gerarchia/treno.h"

class Maglev: public Treno {
private:
    bool tecnologia;
public:
    Maglev(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100,  unsigned int p=100, bool=false);

    bool getTecnologia() const;

    void setTecnologia(bool);

    double carburanteNecessario(unsigned int) const;  //input km da percorrere
    unsigned int kmPercorribili(unsigned int) const; //input kw di carburante

    std::string type() const;
    void print() const;
    std::string treno2string() const;
    virtual void serialize(QJsonObject&);
};

#endif // MAGLEV_H
