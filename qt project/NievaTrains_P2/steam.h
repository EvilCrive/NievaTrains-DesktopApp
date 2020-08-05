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
    Steam();
    virtual ~Steam() = default;
    virtual Steam* clone() const = 0;

    float getEfficenza() const;
    TfuelSteam getCarburante() const;

    void setEfficenza(float efficenza);
    void setCarburante(std::string carburante);
};

#endif // STEAM_H
