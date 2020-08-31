#ifndef AGGIUNTALAYOUT_H
#define AGGIUNTALAYOUT_H
#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QStringList>
#include <QPushButton>
#include <QLabel>
#include <string>
#include "supporto/comboboxmotoreprimario.h"
#include "supporto/comboboxtech.h"
#include "supporto/comboboxtrasmissione.h"


class AggiuntaLayout: public QDialog
{
    Q_OBJECT
protected:
    QVBoxLayout* layoutPopUp;
    QLabel *nomeL, *costruttoreL, *efficenzaSL, *efficenzaEL, *efficenzaICL, *speedL, *pesoL, *carburanteSL, *motoreICL;
    QLineEdit *nome, *costruttore, *efficenzaS, *efficenzaE, *efficenzaIC, *speed, *peso, *carburanteS, *motoreIC;
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
    std::string getMotoreIC()const;
    bool getTecnologia()const;
    bool getPrimario()const;
    bool getTrasmissione()const;
    unsigned int getTipo()const;
    AggiuntaLayout(QWidget * =nullptr, int tipoT=0);
};

#endif // AGGIUNTALAYOUT_H
