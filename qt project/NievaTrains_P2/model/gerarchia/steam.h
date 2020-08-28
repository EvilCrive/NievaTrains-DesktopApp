#ifndef STEAM_H
#define STEAM_H
#include "model/gerarchia/treno.h"

class Steam: public Treno {
private:
    double efficenzaSteam;        // km/kg
    std::string carburanteSteam;  //tipo carburante (kg)
public:
    Steam(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100, unsigned int p=100, double =0.7, std::string ="coal");

    double getEfficenzaSteam() const;
    std::string getCarburanteSteam() const;

    void setEfficenzaSteam(double);
    void setCarburanteSteam(std::string);

    virtual double carburanteNecessario(unsigned int) const;
    virtual unsigned int kmPercorribili(unsigned int) const;
    std::string type() const;
    void print() const;
    std::string treno2string() const;
    virtual void serialize(QJsonObject&);
};

#endif // STEAM_H
