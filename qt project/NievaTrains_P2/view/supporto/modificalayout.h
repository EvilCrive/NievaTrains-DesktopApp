#ifndef MODIFICALAYOUT_H
#define MODIFICALAYOUT_H
#include "aggiuntalayout.h"


class ModificaLayout: public AggiuntaLayout {
public:
    ModificaLayout(QWidget *parent = nullptr, unsigned int tipo=0);

    void setNome(std::string);
    void setCostruttore(std::string);
    void setSpeed(unsigned int);
    void setPeso(unsigned int);
    void setEfficenzaIC(double);
    void setEfficenzaS(double);
    void setEfficenzaE(double);
    void setCarburanteS(std::string);
    void setCarburanteIC(std::string);
    void setPrimario(std::string);
    void setTrasmissione(std::string);
    void setTecnologia(std::string);

};

#endif // MODIFICALAYOUT_H
