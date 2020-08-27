#ifndef AGGIUNTALAYOUT_H
#define AGGIUNTALAYOUT_H
#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QStringList>
#include <QPushButton>
#include <string>
#include "comboboxcarburanteic.h"
#include "comboboxcarburantes.h"
#include "comboboxmotoreprimario.h"
#include "comboboxtech.h"
#include "comboboxtrasmissione.h"


class AggiuntaLayout: public QDialog
{
    Q_OBJECT
protected:
    QVBoxLayout* layoutPopUp;
    QLineEdit *nome, *costruttore, *efficenzaS, *efficenzaE, *efficenzaIC, *speed, *peso;
    ComboBoxCarburanteS *carburanteS;
    ComboBoxCarburanteIC *carburanteIC;
    ComboBoxTech *tecnologia;
    ComboBoxMotorePrimario *primario;
    ComboBoxTrasmissione *trasmissione;
    QPushButton *conferma, *annulla;
    unsigned int tipo;

public:
    std::string getNome() const;
    std::string getCostruttore()const;
    double getEfficenzaS()const;
    double getEfficenzaE()const;
    double getEfficenzaIC()const;
    unsigned int getSpeed() const;
    unsigned int getPeso()const;
    std::string getCarburanteS()const;
    std::string getCarburanteIC()const;
    std::string getTecnologia()const;
    std::string getPrimario()const;
    std::string getTrasmissione()const;
    unsigned int getTipo()const;
    AggiuntaLayout(QWidget * =nullptr, int tipoT=0);
};

#endif // AGGIUNTALAYOUT_H
