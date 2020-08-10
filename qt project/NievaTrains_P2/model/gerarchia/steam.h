#ifndef STEAM_H
#define STEAM_H
#include "model/gerarchia/treno.h"



class Steam: public Treno {
protected:
    enum TfuelSteam {
        coal, wood, oil
    };
private:
    float efficenzaSteam;        // km/kg
    TfuelSteam carburanteSteam;  //kg
public:
    Steam(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100, Trotaia =Trotaia::maglev, Ttreno =Ttreno::alta_velocita, float =0.7f, TfuelSteam =TfuelSteam::coal);

    float getEfficenzaSteam() const;
    std::string getCarburanteSteam() const;

    void setEfficenzaSteam(float);
    void setCarburanteSteam(std::string);

    float carburanteNecessario(unsigned int) const;
    unsigned int kmPercorribili(unsigned int) const;
    std::string type() const;
    void print() const;
   // Steam* clone() const;
};

#endif // STEAM_H
