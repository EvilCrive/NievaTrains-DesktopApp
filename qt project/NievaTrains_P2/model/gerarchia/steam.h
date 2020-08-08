#ifndef STEAM_H
#define STEAM_H
#include "treno.h"

enum TfuelSteam {
    coal, wood, oil
};

class Steam: public Treno {
private:
    float efficenza;        // km/kg
    TfuelSteam carburante;  //kg
public:
    Steam(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100, Trotaia =Trotaia::maglev, Ttreno =Ttreno::alta_velocita, float =0.7f, TfuelSteam =TfuelSteam::coal);

    float getEfficenza() const;
    std::string getCarburante() const;

    void setEfficenza(float);
    void setCarburante(std::string);

    float carburanteNecessario(unsigned int) const;
    unsigned int kmPercorribili(unsigned int) const;
    std::string type() const;
    void print() const;
   // Steam* clone() const;
};

#endif // STEAM_H
