#include "aggiuntalayout.h"

AggiuntaLayout::AggiuntaLayout(QWidget* p, int tipoT): QDialog(p), layoutPopUp(new QVBoxLayout(this)),nome(new QLineEdit(this)), costruttore(new QLineEdit(this)), efficenzaS(new QLineEdit(this)), efficenzaE(new QLineEdit(this)), efficenzaIC(new QLineEdit(this)), speed(new QLineEdit(this)),
    peso(new QLineEdit(this)), carburanteS(new QLineEdit(this)),motoreIC(new QLineEdit(this)),
    tecnologia(new ComboBoxTech(this)),primario(new ComboBoxMotorePrimario(this)), trasmissione(new ComboBoxTrasmissione(this)), conferma(new QPushButton(this)), annulla(new QPushButton(this)), tipo(tipoT)
{
    //inizializzazioni
    conferma->setText("Confirm");
    annulla->setText("Cancel");
    nome->setPlaceholderText("Nome treno");
    nome->setValidator(new QRegExpValidator(QRegExp("[A-Z0-9a-z ]{0,50}")));
    costruttore->setPlaceholderText("Costruttore treno");
    costruttore->setValidator(new QRegExpValidator(QRegExp("[A-Z0-9a-z]{0,50}")));
    efficenzaE->setPlaceholderText("Efficenza motore elettrico");
    efficenzaE->setValidator(new QRegExpValidator(QRegExp("[0-9.]{0,5}")));
    efficenzaS->setPlaceholderText("Efficenza motore a vapore");
    efficenzaS->setValidator(new QRegExpValidator(QRegExp("[0-9.]{0,5}")));
    efficenzaIC->setPlaceholderText("Efficenza motore a combustione interna");
    efficenzaIC->setValidator(new QRegExpValidator(QRegExp("[0-9.]{0,5}")));
    speed->setPlaceholderText("Velocità massima");
    speed->setValidator(new QRegExpValidator(QRegExp("[0-9]{0,5}")));
    peso->setPlaceholderText("Peso");
    peso->setValidator(new QRegExpValidator(QRegExp("[0-9]{0,5}")));
    carburanteS->setPlaceholderText("Carburante steam");
    carburanteS->setValidator(new QRegExpValidator(QRegExp("[A-Z0-9a-z]{0,50}")));
    motoreIC->setPlaceholderText("Nome e marca motore a combustione interna");
    motoreIC->setValidator(new QRegExpValidator(QRegExp("[A-Z0-9a-z]{0,50}")));
    motoreIC->hide();
    efficenzaE->hide();
    trasmissione->hide();
    primario->hide();
    tecnologia->hide();
    efficenzaIC->hide();
    efficenzaS->hide();
    carburanteS->hide();
    //aggiunte
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
        efficenzaIC->show();
        motoreIC->show();
        layoutPopUp->addWidget(efficenzaIC);
        layoutPopUp->addWidget(motoreIC);
        break;
    case 3:
        tecnologia->show();
        layoutPopUp->addWidget(tecnologia);
        break;
    case 4:
        efficenzaE->show();
        efficenzaIC->show();
        motoreIC->show();
        trasmissione->show();
        primario->show();
        layoutPopUp->addWidget(efficenzaE);
        layoutPopUp->addWidget(efficenzaIC);
        layoutPopUp->addWidget(motoreIC);
        layoutPopUp->addWidget(trasmissione);
        layoutPopUp->addWidget(primario);
        break;
    //default:
        //throwa qualcosa
    }
    connect(conferma, SIGNAL(clicked()), p, SLOT(slotInserisciTreno()));
    connect(annulla, SIGNAL(clicked()), this, SLOT(close()));
    layoutPopUp->addWidget(annulla);
    layoutPopUp->addWidget(conferma);

    setLayout(layoutPopUp);
}
std::string AggiuntaLayout::getNome() const{
    return nome->text().toStdString();
}
std::string AggiuntaLayout::getCostruttore()const{
    return costruttore->text().toStdString();
}

double AggiuntaLayout::getEfficenzaS()const{
    return efficenzaS->text().toDouble();
}

double AggiuntaLayout::getEfficenzaE()const{
    return efficenzaE->text().toDouble();
}
double AggiuntaLayout::getEfficenzaIC()const{
    return efficenzaIC->text().toDouble();
}
unsigned int AggiuntaLayout::getSpeed() const{
    return speed->text().toInt();
}
unsigned int AggiuntaLayout::getPeso()const{
    return peso->text().toInt();
}
std::string AggiuntaLayout::getCarburanteS()const{
    return carburanteS->text().toStdString();
}
std::string AggiuntaLayout::getMotoreIC()const{
    return motoreIC->text().toStdString();
}
bool AggiuntaLayout::getTecnologia()const{
    return tecnologia->currentIndex();
}
bool AggiuntaLayout::getPrimario()const{
    return primario->currentIndex();
}
bool AggiuntaLayout::getTrasmissione()const{
    return trasmissione->currentIndex();
}
unsigned int AggiuntaLayout::getTipo()const{
    return tipo;
}
