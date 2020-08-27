#include "modificalayout.h"
ModificaLayout::ModificaLayout(QWidget *parent, unsigned int tipo): AggiuntaLayout(parent,tipo)
{

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
/*
ModificaLayout::ModificaLayout(QWidget *parent, Treno* treno, unsigned int tipo): AggiuntaLayout(parent,tipo)
{
    nome->setText(QString::fromStdString(treno->getNome()));
    costruttore->setText(QString::fromStdString(treno->getCostruttore()));
    speed->setText(QString::number(treno->getSpeed()));
    peso->setText(QString::number(treno->getPeso()));

    if(tipo==0){
        Steam* trenoS=dynamic_cast<Steam*>(treno);
        efficenzaS->setText(QString::number(trenoS->getEfficenzaSteam()));
        std::string carburanteSIndex=trenoS->getCarburanteSteam();
        //carburanteS->setItemData();
        //carburanteS->setItemData();
        //carburanteS->setItemData();
    }else if(tipo==1){
        Electric* trenoE=dynamic_cast<Electric*>(treno);
        std::string trasmissioneIndex=trenoE->getTrasmissioneElettrico();
        efficenzaE->setText(QString::number(trenoE->getEfficenzaElettrico()));
        trasmissione->hide();
    }else if(tipo==2){
        Internal_Combustion* trenoIC=dynamic_cast<Internal_Combustion*>(treno);
        std::string carburanteICIndex=trenoIC->getCarburanteIC();
        efficenzaIC->setText(QString::number(trenoIC->getEfficenzaIC()));
        carburanteIC->hide();
    }else if(tipo==3){
        Maglev* trenoM=dynamic_cast<Maglev*>(treno);
        std::string tecnologiaIndex=trenoM->getTecnologia();
        tecnologia->hide();
    }else{
        Bimode* trenoB=dynamic_cast<Bimode*>(treno);
        efficenzaE->setText(QString::number(trenoB->getEfficenzaElettrico()));
        //efficenzaIC->setText(QString::number(trenoB->getEfficenzaIC()));
        std::string primarioIndex=trenoB->getTrasmissioneElettrico();
        std::string carburanteICIndex=trenoB->getCarburanteIC();
        primario->hide();
    }
}
*/









