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
    Steam(const std::string& = "NoName", unsigned int =10, const std::string& ="NoBuilder", unsigned int =100, Trotaia =Trotaia::maglev, Ttreno =Ttreno::alta_velocita, float =7, TfuelSteam =TfuelSteam::coal);

    float getEfficenza() const;
    TfuelSteam getCarburante() const;

    void setEfficenza(float);
    void setCarburante(std::string);

    float carburanteNecessario(unsigned int) const;
    unsigned int kmPercorribili(unsigned int) const;

//     virtual Steam* clone() const = 0;
};

#endif // STEAM_H
