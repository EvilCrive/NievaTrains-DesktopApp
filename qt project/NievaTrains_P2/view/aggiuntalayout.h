#ifndef AGGIUNTALAYOUT_H
#define AGGIUNTALAYOUT_H
#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QStringList>
#include <QPushButton>
#include "comboboxcarburanteic.h"
#include "comboboxcarburantes.h"
#include "comboboxmotoreprimario.h"
#include "comboboxtech.h"
#include "comboboxtrasmissione.h"


class AggiuntaLayout: public QDialog
{
    Q_OBJECT

    QLineEdit *nome, *costruttore, *efficenzaS, *efficenzaE, *speed, *peso;
    ComboBoxCarburanteS *carburanteS;
    ComboBoxCarburanteIC *carburanteIC;
    ComboBoxTech *tecnologia;
    ComboBoxMotorePrimario *primario;
    ComboBoxTrasmissione *trasmissione;
    QPushButton *conferma, *annulla;

public:
    AggiuntaLayout(QWidget * =nullptr, int tipoT=0);
};

#endif // AGGIUNTALAYOUT_H
