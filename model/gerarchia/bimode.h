#ifndef BIMODE_H
#define BIMODE_H
#include "model/gerarchia/electric.h"
#include "model/gerarchia/internal_combustion.h"

class Bimode: public Electric, public Internal_Combustion {
private:
    bool motorePrimario;
public:

    Bimode(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100,  unsigned int =100,bool =false, double =0.7, unsigned int =1000, std::string ="diesel", bool =false);

    bool getMotorePrimario() const;

    void setMotorePrimario(bool);
    void setMotoreIC(std::string);
    void setTrasmissioneIC(bool);
    void setPotenzaIC(unsigned int);
    void setTrasmissioneElettrico(bool);
    void setEfficenzaElettrico(double);

    double carburanteNecessario(unsigned int) const;
    unsigned int kmPercorribili(unsigned int) const;
    std::string type() const;
    void print() const;
    std::string treno2string() const;
    virtual void serialize(QJsonObject&);
};

#endif // BIMODE_H
