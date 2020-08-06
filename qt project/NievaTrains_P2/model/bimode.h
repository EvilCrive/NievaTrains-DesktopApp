#ifndef BIMODE_H
#define BIMODE_H

#include "electric.h"
#include "internal_combustion.h"

enum Tmotore {
    elettrico, combustione, fullhybrid
};

class Bimode: public Electric, Internal_Combustion {
private:
    Tmotore motorePrimario;
public:
    Bimode();
    virtual ~Bimode() = default;
    virtual Bimode* clone() const = 0;

    Tmotore getMotorePrimario() const;

    void setMotorePrimario(std::string motorePrimario);
};

#endif // BIMODE_H
