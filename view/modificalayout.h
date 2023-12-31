#ifndef MODIFICALAYOUT_H
#define MODIFICALAYOUT_H
#include "aggiuntalayout.h"


class ModificaLayout: public AggiuntaLayout {
    unsigned int ind;
    QPushButton* modifica;
public:
    ModificaLayout(QWidget *parent = nullptr, unsigned int tipo=0, unsigned int ind=0);

    void setNome(std::string);
    void setCostruttore(std::string);
    void setSpeed(unsigned int);
    void setPeso(unsigned int);
    void setPotenzaIC(unsigned int);
    void setTemperaturaS(unsigned int);
    void setEfficenzaE(double);
    void setCarburanteS(std::string);
    void setMotoreIC(std::string);
    void setPrimario(bool);
    void setTrasmissione(bool);
    void setTecnologia(bool);
    unsigned int getInd() const;

};

#endif // MODIFICALAYOUT_H
