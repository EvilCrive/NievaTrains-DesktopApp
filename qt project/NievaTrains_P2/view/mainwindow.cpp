#include "mainwindow.h"
#include "supporto/combotype.h"
#include <QMessageBox>
#include <QString>
#include "supporto/infolayout.h"
#include <iostream>
#include <QFile>
#include <QFileDialog>
#include "supporto/nievaexception.h"
using std::string;

MainWindow::MainWindow(Model* m, QWidget *parent): QWidget(parent), menu(new MenuBarTrain(this)), modello(m), layout(new MainLayout(this)), layoutAdd(nullptr), layoutMod(nullptr)
{
    setWindowTitle("Nieva Trains");
    QHBoxLayout* mainLayout= new QHBoxLayout(this);
    mainLayout->addWidget(layout);
    mainLayout->setMenuBar(menu);
    setLayout(mainLayout);
}
void MainWindow::refreshList(){
    layout->getList()->clear();
    for(unsigned int i=0; i<modello->numerotreni(); i++)
        layout->getList()->addTrenoList(modello->getTreno(i));
}
void MainWindow::slotShowInfoGenerali(){

    //occhio che magari il puntatore viene cancellato all'uscita ma non l'oggetto
    QString str1= "La quantità di treni presenti nel sistema è:  "+QString::number(modello->numerotreni())+"treni";
    QString str2= "Il peso medio dei treni nel sistema è:  "+QString::number(modello->getPesoM())+"t";
    QString str3= "La velocità media dei treni nel sistema è:  "+QString::number(modello->getSpeedM())+"km/h";
    QString str4= "Il peso maggiore registrato è:  "+QString::number(modello->getPesoT())+"t";
    QString str5= "La velocità maggiore registrata è:  "+QString::number(modello->getSpeedT())+"km/h";

    InfoLayout* info=new InfoLayout(this,str1,str2,str3,str4,str5);
    info->setMargin(13);
    info->setDimensioni(300,250);
    info->show();
}
//lista eccezioni
void MainWindow::slotCarica(){
    QString file= QFileDialog::getOpenFileName(
                this,
                tr("Choose file"),
                "../NievaTrains_P2/file risorse",
                "File JSON(*.json)"
                );
    if(file!=""){
    //reset ricerca?
        modello->clear();
        //eccezione
        try{modello->load(file.toStdString());}catch(NievaException* e){QMessageBox* tmp=new QMessageBox();tmp->setText(QString::fromStdString(e->getMessage()));tmp->setWindowTitle("Warning");tmp->show();}
        if(modello->isEmpty()){
            QMessageBox::warning(this,"Attenzione!","Il file e' vuoto.");
        }
        else{
            refreshList();
        }
    }else{
        QMessageBox* tmp=new QMessageBox();tmp->setText("Seleziona un file.");tmp->setWindowTitle("Warning");tmp->show();
    }
}
//lista eccezioni
void MainWindow::slotSalva(){
    QString file= QFileDialog::getSaveFileName(
                this,
                tr("Choose file"),
                "../NievaTrains_P2/file risorse",
                "File JSON(*.json)"
                );
    if(file!=""){
    //reset ricerca?
        //eccezione
        try{modello->save(file.toStdString());}catch(NievaException* e){QMessageBox* tmp=new QMessageBox();tmp->setText(QString::fromStdString(e->getMessage()));tmp->setWindowTitle("Warning");tmp->show();}
    }else{
        QMessageBox* tmp=new QMessageBox();tmp->setText("Seleziona un file.");tmp->setWindowTitle("Warning");tmp->show();
    }
}

void MainWindow::slotAutori()
{
    QDialog* info=new QDialog(this);
    QLabel* text=new QLabel(info);
    text->setText("Gli autori:\n Alberto Crivellari, Matteo Brosolo, Francesco Bugno.");
    text->setMargin(5);
    info->resize(300,50);
    info->show();
}


void MainWindow::slotRemoveTreno()
{
    unsigned int t=layout->estraiTrenoSelezionato();
    layout->eliminaTreno(t);
    modello->erase(t);
    refreshList();
}

void MainWindow::slotShowTreno(){
    string str="";
    if(layout->estraiTrenoSelezionato()!=-1)
        str=modello->treno2string(layout->estraiTrenoSelezionato());
    layout->stampaDettagliTreno(str);
}
void MainWindow::slotFlush(){
    layout->flushList();
    modello->clear();
}

void MainWindow::slotShowInserimentoTreno(){
    int x=layout->getTrenoInserimento();
    layoutAdd=new AggiuntaLayout(this,x);
    layoutAdd->show();
}
void MainWindow::slotInserisciTreno(){
    unsigned int x=layoutAdd->getTipo();
    std::string nome=layoutAdd->getNome();
    std::string costruttore=layoutAdd->getCostruttore();
    unsigned int speed=layoutAdd->getSpeed();
    unsigned int peso=layoutAdd->getPeso();
    if(x==0){
        double efficenzaS=layoutAdd->getEfficenzaS();
        std::string carburanteS=layoutAdd->getCarburanteS();
        modello->addtrainSteam(nome, costruttore, peso, speed, efficenzaS, carburanteS);
    }else if(x==1){
        double efficenzaE=layoutAdd->getEfficenzaE();
        std::string trasmissione=layoutAdd->getTrasmissione();
        modello->addtrainElectric(nome, costruttore, peso, speed, trasmissione, efficenzaE);
    }else if(x==2){
        std::string carburanteIC=layoutAdd->getCarburanteIC();
        double efficenzaIC=layoutAdd->getEfficenzaIC();
        modello->addtrainIC(nome, costruttore, peso, speed, carburanteIC, efficenzaIC);
    }else if(x==3){
        std::string tecnologia=layoutAdd->getTecnologia();
        modello->addtrainMaglev(nome, costruttore, peso, speed, tecnologia);
    }else{
        double efficenzaE=layoutAdd->getEfficenzaE();
        std::string trasmissione=layoutAdd->getTrasmissione();
        std::string carburanteIC=layoutAdd->getCarburanteIC();
        double efficenzaIC=layoutAdd->getEfficenzaIC();
        std::string primario=layoutAdd->getPrimario();
        modello->addtrainBimode(nome, costruttore, peso, speed, carburanteIC, efficenzaIC, trasmissione, efficenzaE, primario);
    }

    layout->getList()->addTrenoList(modello->getTreno(modello->numerotreni()-1));
    //aggiornamento lista view
    layoutAdd->hide();
    delete layoutAdd;
}
void MainWindow::slotShowModificaTreno(){
    unsigned int indecs=layout->getList()->getIndex();
    Treno* TrenoDaModificare=modello->getTreno(indecs);
    //capire il tipo di treno
    std::string tipo=TrenoDaModificare->type();
    int x=-1;
    if(tipo=="Electric"){
        x=1;
    }
    else if(tipo=="Bimode"){
        x=4;
    }
    else if(tipo=="Steam"){
        x=0;
    }
    else if (tipo=="Internal_Combustion"){
        x=2;
    }
    else if (tipo=="Maglev"){
        x=3;
    }
    else{
        //throw
    }
    //creare ModificaLayout
    layoutMod=new ModificaLayout(this,x,indecs);
    //estrarre i parametri che mi servono e settarli in ModificaLayout
    layoutMod->setNome(TrenoDaModificare->getNome());
    layoutMod->setCostruttore(TrenoDaModificare->getCostruttore());
    layoutMod->setPeso(TrenoDaModificare->getPeso());
    layoutMod->setSpeed(TrenoDaModificare->getSpeed());
    if(Bimode*tmp=dynamic_cast<Bimode*>(TrenoDaModificare)){
        layoutMod->setPrimario(tmp->getMotorePrimario());
    }
    if(Steam*tmp=dynamic_cast<Steam*>(TrenoDaModificare)){
        layoutMod->setEfficenzaS(tmp->getEfficenzaSteam());
        layoutMod->setCarburanteS(tmp->getCarburanteSteam());
    }
    if(Internal_Combustion*tmp=dynamic_cast<Internal_Combustion*>(TrenoDaModificare)){
        layoutMod->setEfficenzaIC(tmp->getEfficenzaIC());
        layoutMod->setCarburanteIC(tmp->getCarburanteIC());
    }
    if(Electric*tmp=dynamic_cast<Electric*>(TrenoDaModificare)){
        layoutMod->setEfficenzaE(tmp->getEfficenzaElettrico());
        layoutMod->setTrasmissione(tmp->getTrasmissioneElettrico());
    }
    if(Maglev*tmp=dynamic_cast<Maglev*>(TrenoDaModificare)){
        layoutMod->setTecnologia(tmp->getTecnologia());
    }
    //displayarlo il modificalayout
    layoutMod->show();

    //*ci sono da fare magie con la connect prolly
}
void MainWindow::slotModificaTreno(){
    unsigned int x=layoutMod->getInd();
    Treno* TrenoDaModificare=modello->getTreno(x);
    TrenoDaModificare->setNome(layoutMod->getNome());
    TrenoDaModificare->setCostruttore(layoutMod->getCostruttore());
    TrenoDaModificare->setSpeed(layoutMod->getSpeed());
    TrenoDaModificare->setPeso(layoutMod->getPeso());


    if(Steam*tmp=dynamic_cast<Steam*>(TrenoDaModificare)){
        tmp->setEfficenzaSteam(layoutMod->getEfficenzaS());
        tmp->setCarburanteSteam(layoutMod->getCarburanteS());
    }if(Electric*tmp=dynamic_cast<Electric*>(TrenoDaModificare)){
        tmp->setEfficenzaElettrico(layoutMod->getEfficenzaE());
        tmp->setTrasmissioneElettrico(layoutMod->getTrasmissione());
    }if(Internal_Combustion*tmp=dynamic_cast<Internal_Combustion*>(TrenoDaModificare)){
        tmp->setCarburanteIC(layoutMod->getCarburanteIC());
        tmp->setEfficenzaIC(layoutMod->getEfficenzaIC());
    }if(Maglev*tmp=dynamic_cast<Maglev*>(TrenoDaModificare)){
        tmp->setTecnologia(layoutMod->getTecnologia());
    }if(Bimode*tmp=dynamic_cast<Bimode*>(TrenoDaModificare)){
        tmp->setMotorePrimario(layoutMod->getPrimario());
    }
    //refresh lista
    refreshList();
    layout->getList()->setCurrentRow(x);
    layoutMod->hide();
    delete layoutMod;
}
MainWindow::~MainWindow()
{
}































