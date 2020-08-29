#include "modificalayout.h"
#include "nievaexception.h"
ModificaLayout::ModificaLayout(QWidget *parent, unsigned int tipo, unsigned int i): AggiuntaLayout(parent,tipo), ind(i), modifica(new QPushButton(this))
{
    conferma->hide();
    modifica->setText("Modifica");
    layoutPopUp->addWidget(modifica);

    connect(modifica, SIGNAL(clicked()), parent, SLOT(slotModificaTreno()));
}
void ModificaLayout::setNome(std::string str){
    nome->setText(QString::fromStdString(str));
}
void ModificaLayout::setCostruttore(std::string str){
    costruttore->setText(QString::fromStdString(str));
}
void ModificaLayout::setSpeed(unsigned int x){
    speed->setText(QString::number(x));
}
void ModificaLayout::setPeso(unsigned int x){
     peso->setText(QString::number(x));
}
void ModificaLayout::setEfficenzaIC(double x){
    efficenzaIC->setText(QString::number(x));
}
void ModificaLayout::setEfficenzaS(double x){
    efficenzaS->setText(QString::number(x));
}
void ModificaLayout::setEfficenzaE(double x){
     efficenzaE->setText(QString::number(x));
}
void ModificaLayout::setCarburanteS(std::string str){
    carburanteS->setText(QString::fromStdString(str));
}
void ModificaLayout::setCarburanteIC(std::string str){
    carburanteIC->setText(QString::fromStdString(str));
}
void ModificaLayout::setPrimario(bool x){
    if(x==false) primario->setCurrentIndex(0);
    else primario->setCurrentIndex(1);
}
void ModificaLayout::setTrasmissione(bool x){
    if(x==false) trasmissione->setCurrentIndex(0);
    else trasmissione->setCurrentIndex(1);//
}
void ModificaLayout::setTecnologia(bool x){
    if(x==false) tecnologia->setCurrentIndex(0);
    else tecnologia->setCurrentIndex(1);
}
unsigned int ModificaLayout::getInd() const{
    return ind;
}









