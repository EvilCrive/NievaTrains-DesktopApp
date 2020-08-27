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
    Steam(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100, unsigned int p=100, double =0.7, TfuelSteam =TfuelSteam::coal);

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
