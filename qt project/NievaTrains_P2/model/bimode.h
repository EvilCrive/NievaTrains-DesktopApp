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
    Bimode(const std::string& = "NoName", unsigned int =10, const std::string& ="NoBuilder", unsigned int =100, Trotaia =Trotaia::maglev, Ttreno =Ttreno::alta_velocita, Ttrasmission =Ttrasmission::overhead_lines, float =7, float =7, Tfuel =Tfuel::kerosene, Ttrasmissione =Ttrasmissione::electric, Tmotore =Tmotore::elettrico );

    Tmotore getMotorePrimario() const;

    void setMotorePrimario(std::string);

    float carburanteNecessario(unsigned int) const;  //input km da percorrere
    unsigned int kmPercorribili(unsigned int) const; //input kw di carburante
//  Bimode* clone() const = 0;

};

#endif // BIMODE_H
