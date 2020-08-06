#ifndef STEAM_H
#define STEAM_H
#include "treno.h"

enum TfuelSteam {
    coal, wood, oil
};

class Steam: public Treno {
private:
    float efficenza;
    TfuelSteam carburante;
public:
    Steam(const std::string& = "NoName", unsigned int =10, const std::string& ="NoBuilder", unsigned int =100, Trotaia =Trotaia::maglev, Ttreno =Ttreno::alta_velocita, float =7, TfuelSteam =TfuelSteam::coal);
    virtual ~Steam() = default;
    virtual Steam* clone() const = 0;

    float getEfficenza() const;
    TfuelSteam getCarburante() const;

    void setEfficenza(float efficenza);
    void setCarburante(std::string carburante);



    virtual float carburanteNecessario(unsigned int km) const =0;
    virtual unsigned int kmPercorribili(unsigned int carburante) const =0;
};

#endif // STEAM_H
