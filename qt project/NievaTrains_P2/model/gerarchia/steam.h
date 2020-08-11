#ifndef STEAM_H
#define STEAM_H
#include "model/gerarchia/treno.h"

class Steam: public Treno {
protected:
    enum TfuelSteam {coal, wood, oil};
private:
    double efficenzaSteam;        // km/kg
    TfuelSteam carburanteSteam;  //kg
public:
    Steam(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100, Trotaia =Trotaia::maglev, Ttreno =Ttreno::alta_velocita, double =0.7, TfuelSteam =TfuelSteam::coal);

    double getEfficenzaSteam() const;
    std::string getCarburanteSteam() const;

    void setEfficenzaSteam(double);
    void setCarburanteSteam(std::string);

    double carburanteNecessario(unsigned int) const;
    unsigned int kmPercorribili(unsigned int) const;
    std::string type() const;
    void print() const;
    virtual void serialize(QJsonObject&);
};

#endif // STEAM_H
