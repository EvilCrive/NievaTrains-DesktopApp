#include "modificalayout.h"
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
    if(str=="Coal") carburanteS->setCurrentIndex(0);
    else if(str=="Wood") carburanteS->setCurrentIndex(1);
    else carburanteS->setCurrentIndex(2);
}
void ModificaLayout::setCarburanteIC(std::string str){
    if(str=="Kerosene") carburanteIC->setCurrentIndex(0);
    else if(str=="Petrol") carburanteIC->setCurrentIndex(1);
    else carburanteIC->setCurrentIndex(2);
}
void ModificaLayout::setPrimario(std::string str){
    if(str=="Electric") primario->setCurrentIndex(0);
    else if(str=="Internal_Combustion") primario->setCurrentIndex(1);
    else primario->setCurrentIndex(2);
}
void ModificaLayout::setTrasmissione(std::string str){
    if(str=="Overhead_Lines") trasmissione->setCurrentIndex(0);
    else trasmissione->setCurrentIndex(1);//
}
void ModificaLayout::setTecnologia(std::string str){
    if(str=="Eds") tecnologia->setCurrentIndex(0);
    else tecnologia->setCurrentIndex(1);
}
unsigned int ModificaLayout::getInd() const{
    return ind;
}









