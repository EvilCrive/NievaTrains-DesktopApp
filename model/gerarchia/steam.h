#ifndef STEAM_H
#define STEAM_H
#include "model/gerarchia/treno.h"

class Steam: public Treno {
private:
    unsigned int temperaturaOperativa;
    std::string carburanteSteam;  //tipo carburante (kg)
public:
    Steam(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100, unsigned int p=100, unsigned int =100, std::string ="coal");

    unsigned int getTemperaturaOperativa() const;
    std::string getCarburanteSteam() const;

    void setTemperaturaOperativa(unsigned int);
    void setCarburanteSteam(std::string);

    double carburanteNecessario(unsigned int) const;
    unsigned int kmPercorribili(unsigned int) const;
    std::string type() const;
    void print() const;
    std::string treno2string() const;
    virtual void serialize(QJsonObject&);
};

#endif // STEAM_H
