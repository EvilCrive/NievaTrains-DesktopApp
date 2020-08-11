#ifndef MAGLEV_H
#define MAGLEV_H
#include "model/gerarchia/treno.h"

class Maglev: public Treno {
protected:
    enum Ttech {eds, ems};
private:
    Ttech tecnologia;
public:
    Maglev(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100, Trotaia =Trotaia::maglev, Ttreno =Ttreno::alta_velocita, Ttech =Ttech::eds);

    std::string getTecnologia() const;

    void setTecnologia(std::string);

    double carburanteNecessario(unsigned int) const;
    unsigned int kmPercorribili(unsigned int) const;
    std::string type() const;
    void print() const;
    virtual void serialize(QJsonObject&);
};

#endif // MAGLEV_H
