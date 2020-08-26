#include "aggiuntalayout.h"

AggiuntaLayout::AggiuntaLayout(QWidget* p, int tipoT): QDialog(p), nome(new QLineEdit(this)), costruttore(new QLineEdit(this)), efficenzaS(new QLineEdit(this)), efficenzaE(new QLineEdit(this)), speed(new QLineEdit(this)),
    peso(new QLineEdit(this)), carburanteS(new ComboBoxCarburanteS(this)),carburanteIC(new ComboBoxCarburanteIC(this)),
    tecnologia(new ComboBoxTech(this)),primario(new ComboBoxMotorePrimario(this)), trasmissione(new ComboBoxTrasmissione(this)), conferma(new QPushButton(this)), annulla(new QPushButton(this))
{
    //inizializzazioni
    conferma->setText("Confirm");
    annulla->setText("Cancel");
    nome->setText("Nome treno");
    costruttore->setText("Costruttore treno");
    efficenzaE->setText("Efficenza motore elettrico");
    efficenzaS->setText("Efficenza motore a vapore");
    speed->setText("Velocità massima");
    peso->setText("Peso");
    carburanteIC->hide();
    efficenzaE->hide();
    trasmissione->hide();
    primario->hide();
    tecnologia->hide();
    carburanteIC->hide();
    efficenzaE->hide();
    trasmissione->hide();
    efficenzaS->hide();
    carburanteS->hide();
    //aggiunte
    QVBoxLayout* layoutPopUp= new QVBoxLayout(this);
    layoutPopUp->addWidget(nome);
    layoutPopUp->addWidget(costruttore);
    layoutPopUp->addWidget(speed);
    layoutPopUp->addWidget(peso);
    switch (tipoT) {
    case 0:
        efficenzaS->show();
        carburanteS->show();
        layoutPopUp->addWidget(efficenzaS);
        layoutPopUp->addWidget(carburanteS);
        break;
    case 1:
        efficenzaE->show();
        trasmissione->show();
        layoutPopUp->addWidget(efficenzaE);
        layoutPopUp->addWidget(trasmissione);
        break;
    case 2:
        carburanteIC->show();
        layoutPopUp->addWidget(carburanteIC);
        break;
    case 3:
        tecnologia->show();
        layoutPopUp->addWidget(tecnologia);
        break;
    case 4:
        carburanteIC->show();
        efficenzaE->show();
        trasmissione->show();
        primario->show();
        layoutPopUp->addWidget(carburanteIC);
        layoutPopUp->addWidget(efficenzaE);
        layoutPopUp->addWidget(trasmissione);
        layoutPopUp->addWidget(primario);
        break;
    //default:
        //throwa qualcosa
    }
    layoutPopUp->addWidget(conferma);
    layoutPopUp->addWidget(annulla);

    setLayout(layoutPopUp);
    //connect
}
