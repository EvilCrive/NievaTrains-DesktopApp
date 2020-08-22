#include "infolayout.h"
#include <QString>
#include <QVBoxLayout>
InfoLayout::InfoLayout(QWidget* p, unsigned int vartot, unsigned int varVelT, unsigned int varPesoT, double varVelM, double varPesoM): QDialog(p),
    tot(new QLabel(this)),
    PesoM(new QLabel(this)),
    VelM(new QLabel(this)),
    PesoT(new QLabel(this)),
    VelT(new QLabel(this))
{
    QString str1, str2, str3, str4, str5;
    str1= "La quantità di treni presenti nel sistema è: "+ QString::number(vartot);
    str2= "Il peso medio dei treni nel sistema è: "+QString::number(varPesoM);
    str3= "La velocità media dei treni nel sistema è: "+QString::number(varVelM);
    str4= "Il peso maggiore registrato è: "+QString::number(varPesoT);
    str5= "La velocità maggiore registrata è: "+QString::number(varVelT);

    tot->setText(str1);
    PesoM->setText(str2);
    VelM->setText(str3);
    PesoT->setText(str4);
    VelT->setText(str5);

    setWindowTitle("Informazioni di sistema");
    QVBoxLayout* ilayout(new QVBoxLayout(this));

    ilayout->addWidget(tot);
    ilayout->addWidget(PesoM);
    ilayout->addWidget(VelM);
    ilayout->addWidget(PesoT);
    ilayout->addWidget(VelT);
    setLayout(ilayout);
}
