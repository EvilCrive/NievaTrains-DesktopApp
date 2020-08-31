#include "aggiuntalayout.h"

AggiuntaLayout::AggiuntaLayout(QWidget* p, int tipoT): QDialog(p), layoutPopUp(new QVBoxLayout(this)),
    nomeL(new QLabel(this)), costruttoreL(new QLabel(this)), efficenzaSL(new QLabel(this)), efficenzaEL(new QLabel(this)), efficenzaICL(new QLabel(this)), speedL(new QLabel(this)), pesoL(new QLabel(this)), carburanteSL(new QLabel(this)), motoreICL(new QLabel(this)),
    nome(new QLineEdit(this)), costruttore(new QLineEdit(this)), efficenzaS(new QLineEdit(this)), efficenzaE(new QLineEdit(this)), efficenzaIC(new QLineEdit(this)), speed(new QLineEdit(this)),
    peso(new QLineEdit(this)), carburanteS(new QLineEdit(this)),motoreIC(new QLineEdit(this)),
    tecnologia(new ComboBoxTech(this)),primario(new ComboBoxMotorePrimario(this)), trasmissione(new ComboBoxTrasmissione(this)), conferma(new QPushButton(this)), annulla(new QPushButton(this)), tipo(tipoT)

{
    conferma->setText("Confirm");
    annulla->setText("Cancel");
    nomeL->setText("Name");
    pesoL->setText("Weight");
    speedL->setText("Top speed");
    costruttoreL->setText("Builder");
    efficenzaSL->setText("Steam engine efficency");
    efficenzaEL->setText("Electric engine efficency");
    efficenzaICL->setText("Internal combustion engine efficency");
    carburanteSL->setText("Steam engine fuel");
    motoreICL->setText("Internal combustion engine name");

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
    efficenzaSL->hide();
    efficenzaEL->hide();
    efficenzaICL->hide();
    motoreICL->hide();
    carburanteSL->hide();

    layoutPopUp->addWidget(nomeL);
    layoutPopUp->addWidget(nome);
    layoutPopUp->addWidget(costruttoreL);
    layoutPopUp->addWidget(costruttore);
    layoutPopUp->addWidget(speedL);
    layoutPopUp->addWidget(speed);
    layoutPopUp->addWidget(pesoL);
    layoutPopUp->addWidget(peso);
    switch (tipoT) {
    case 0:
        efficenzaS->show();
        carburanteS->show();
        efficenzaSL->show();
        carburanteSL->show();
        layoutPopUp->addWidget(efficenzaSL);
        layoutPopUp->addWidget(efficenzaS);
        layoutPopUp->addWidget(carburanteSL);
        layoutPopUp->addWidget(carburanteS);
        break;
    case 1:
        efficenzaE->show();
        trasmissione->show();
        efficenzaEL->show();
        layoutPopUp->addWidget(efficenzaEL);
        layoutPopUp->addWidget(efficenzaE);
        layoutPopUp->addWidget(trasmissione);
        break;
    case 2:
        efficenzaIC->show();
        efficenzaICL->show();
        motoreIC->show();
        motoreICL->show();
        layoutPopUp->addWidget(efficenzaICL);
        layoutPopUp->addWidget(efficenzaIC);
        layoutPopUp->addWidget(motoreICL);
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
        efficenzaEL->show();
        efficenzaICL->show();
        motoreICL->show();
        trasmissione->show();
        primario->show();
        layoutPopUp->addWidget(efficenzaEL);
        layoutPopUp->addWidget(efficenzaE);
        layoutPopUp->addWidget(efficenzaICL);
        layoutPopUp->addWidget(efficenzaIC);
        layoutPopUp->addWidget(motoreICL);
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
