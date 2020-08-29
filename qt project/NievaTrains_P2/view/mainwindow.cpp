#include "mainwindow.h"
#include "supporto/combotype.h"
#include <QMessageBox>
#include <QString>
#include "infolayout.h"
#include <iostream>
#include <QFile>
#include <QFileDialog>
#include "supporto/nievaexception.h"
using std::string;

double MainWindow::correctEfficenza(double& e)
{
    QMessageBox* error= new QMessageBox();error->setText("Efficenza dev'essere compresa tra 0 e 1.\nVerra' settata a 0.5");
    error->setWindowTitle("Warning");
    error->show();
    e=0.5;
    return e;
}

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
    layoutAdd->resize(250,350);
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
        if(efficenzaS<0 || efficenzaS>1)
            correctEfficenza(efficenzaS);
        std::string carburanteS=layoutAdd->getCarburanteS();
        Steam* train=new Steam(nome, costruttore, speed, peso, efficenzaS, carburanteS);
        modello->push_end(train);
    }else if(x==1){
        double efficenzaE=layoutAdd->getEfficenzaE();
        if(efficenzaE<0 || efficenzaE>1)
            correctEfficenza(efficenzaE);
        bool trasmissione=layoutAdd->getTrasmissione();
        Electric* train=new Electric(nome, costruttore, peso, speed, trasmissione, efficenzaE);
        modello->push_end(train);
    }else if(x==2){
        std::string motoreIC=layoutAdd->getMotoreIC();
        double efficenzaIC=layoutAdd->getEfficenzaIC();
        if(efficenzaIC<0 || efficenzaIC>1)
            correctEfficenza(efficenzaIC);
        Internal_Combustion* train= new Internal_Combustion(nome, costruttore, peso, speed, efficenzaIC, motoreIC);
        modello->push_end(train);
    }else if(x==3){
        bool tecnologia=layoutAdd->getTecnologia();
        Maglev* train= new Maglev(nome, costruttore, peso, speed, tecnologia);
        modello->push_end(train);
    }else{
        double efficenzaE=layoutAdd->getEfficenzaE();
        if(efficenzaE<0 || efficenzaE>1)
            correctEfficenza(efficenzaE);
        bool trasmissione=layoutAdd->getTrasmissione();
        std::string motoreIC=layoutAdd->getMotoreIC();
        double efficenzaIC=layoutAdd->getEfficenzaIC();
        if(efficenzaIC<0 || efficenzaIC>1)
            correctEfficenza(efficenzaIC);
        bool primario=layoutAdd->getPrimario();
        Bimode* train= new Bimode(nome, costruttore, peso, speed, trasmissione, efficenzaE, efficenzaIC, motoreIC, primario);
        modello->push_end(train);
    }

    layout->getList()->addTrenoList(modello->getTreno(modello->numerotreni()-1));
    //aggiornamento lista view
    layoutAdd->hide();
    delete layoutAdd;
}
void MainWindow::slotShowModificaTreno() try{
    if(layout->estraiTrenoSelezionato()==-1)   throw new NievaException("Seleziona un treno esistente da modificare");
    unsigned int indecs=layout->getList()->getIndex();
    Treno* TrenoDaModificare=modello->getTreno(indecs);
    std::string tipo=TrenoDaModificare->type();
    /*Vengono usati i dynamic cast dove è necessario poichè non c'è altro modo per estrarre i campi di tipi derivati senza andare a modificare la gerarchia con
    metodi ad hoc*/
    if(tipo=="Electric"){
        layoutMod=new ModificaLayout(this,1,indecs);
        Electric*tmp=dynamic_cast<Electric*>(TrenoDaModificare);
        layoutMod->setEfficenzaE(tmp->getEfficenzaElettrico());
        layoutMod->setTrasmissione(tmp->getTrasmissioneElettrico());
    }
    else if(tipo=="Bimode"){
        layoutMod=new ModificaLayout(this,4,indecs);
        Bimode*tmp=dynamic_cast<Bimode*>(TrenoDaModificare);
        layoutMod->setPrimario(tmp->getMotorePrimario());
        layoutMod->setEfficenzaIC(tmp->getEfficenzaIC());
        layoutMod->setMotoreIC(tmp->getMotoreIC());
        layoutMod->setEfficenzaE(tmp->getEfficenzaElettrico());
        layoutMod->setTrasmissione(tmp->getTrasmissioneElettrico());
    }
    else if(tipo=="Steam"){
        layoutMod=new ModificaLayout(this,0,indecs);
        Steam*tmp=static_cast<Steam*>(TrenoDaModificare);
        layoutMod->setEfficenzaS(tmp->getEfficenzaSteam());
        layoutMod->setCarburanteS(tmp->getCarburanteSteam());
    }
    else if (tipo=="Internal_Combustion"){
        layoutMod=new ModificaLayout(this,2,indecs);
        Internal_Combustion*tmp=dynamic_cast<Internal_Combustion*>(TrenoDaModificare);
        layoutMod->setEfficenzaIC(tmp->getEfficenzaIC());
        layoutMod->setMotoreIC(tmp->getMotoreIC());
    }
    else if (tipo=="Maglev"){
        layoutMod=new ModificaLayout(this,3,indecs);
        Maglev*tmp=static_cast<Maglev*>(TrenoDaModificare);
        layoutMod->setTecnologia(tmp->getTecnologia());
    }
    else{
        //throw
        throw new NievaException("Tipo del treno sbagliato");
    }
    layoutMod->setNome(TrenoDaModificare->getNome());
    layoutMod->setCostruttore(TrenoDaModificare->getCostruttore());
    layoutMod->setPeso(TrenoDaModificare->getPeso());
    layoutMod->setSpeed(TrenoDaModificare->getSpeed());
    layoutMod->resize(250,350);
    layoutMod->show();
}catch(NievaException* e){
    QMessageBox *warning=new QMessageBox();
    warning->setText(QString::fromStdString(e->getMessage()));
    warning->setWindowTitle("Warning");
    warning->show();
}
void MainWindow::slotModificaTreno(){
    unsigned int x=layoutMod->getInd();
    unsigned int tip=layoutMod->getTipo();
    //in base al tipo identificato da tip creo un nuovo treno e lo inserisco nel modello
    std::string nomeNew=layoutMod->getNome();
    std::string costruttoreNew=layoutMod->getCostruttore();
    unsigned int speedNew=layoutMod->getSpeed();
    unsigned int pesoNew=layoutMod->getPeso();
    if(tip==0){
        double efficenzaSNew=layoutMod->getEfficenzaS();
        if(efficenzaSNew<0 || efficenzaSNew>1)
            correctEfficenza(efficenzaSNew);
        std::string carburanteSNew=layoutMod->getCarburanteS();
        Steam* trenoDaSostituire=new Steam(nomeNew, costruttoreNew, speedNew, pesoNew, efficenzaSNew, carburanteSNew);
        modello->sostituisci(trenoDaSostituire, x);
    }else if(tip==1){
        double efficenzaENew=layoutMod->getEfficenzaE();
        if(efficenzaENew<0 || efficenzaENew>1)
            correctEfficenza(efficenzaENew);
        bool trasmissioneNew=layoutMod->getTrasmissione();
        Electric* trenoDaSostituire=new Electric(nomeNew, costruttoreNew, speedNew, pesoNew, trasmissioneNew, efficenzaENew);
        modello->sostituisci(trenoDaSostituire, x);
    }else if(tip==2){
        std::string motoreICNew=layoutMod->getMotoreIC();
        double efficenzaICNew=layoutMod->getEfficenzaIC();
        if(efficenzaICNew<0 || efficenzaICNew>1)
            correctEfficenza(efficenzaICNew);
        Internal_Combustion* trenoDaSostituire=new Internal_Combustion(nomeNew, costruttoreNew, speedNew, pesoNew, efficenzaICNew, motoreICNew);
        modello->sostituisci(trenoDaSostituire, x);
    }else if(tip==3){
        bool tecnologiaNew=layoutMod->getTecnologia();
        Maglev* trenoDaSostituire=new Maglev(nomeNew, costruttoreNew, speedNew, pesoNew, tecnologiaNew);
        modello->sostituisci(trenoDaSostituire, x);
    }else if(tip==4){
        std::string motoreICNew=layoutMod->getMotoreIC();
        double efficenzaICNew=layoutMod->getEfficenzaIC();
        double efficenzaENew=layoutMod->getEfficenzaE();
        if(efficenzaICNew<0 || efficenzaICNew>1)
            correctEfficenza(efficenzaICNew);
        if(efficenzaENew<0 || efficenzaENew>1)
            correctEfficenza(efficenzaENew);
        bool trasmissioneNew=layoutMod->getTrasmissione();
        bool primarioNew=layoutMod->getPrimario();
        Bimode* trenoDaSostituire=new Bimode(nomeNew, costruttoreNew, speedNew, pesoNew, trasmissioneNew, efficenzaENew, efficenzaICNew, motoreICNew, primarioNew);
        modello->sostituisci(trenoDaSostituire, x);
    }else{
        //throw
    }
    //refresh lista
    refreshList();
    layout->getList()->setCurrentRow(x);
    layoutMod->hide();
    delete layoutMod;
}
void MainWindow::slotCerca(){
    unsigned int filtro=layout->getFiltro();
    std::string parametro=layout->getParametroRicerca();

    switch(filtro){
    case 0:
        modello->searchNome(parametro);
    case 1:
        modello->searchCostruttore(parametro);
    case 2:
    if(parametro.substr(0,0)==">")
        modello->searchVelocita(std::stoi(parametro.substr(1)), false);
    else if(parametro.substr(0,0)=="<")
        modello->searchVelocita(std::stoi(parametro=parametro.substr(1)), true);
    else
        modello->searchPeso(std::stoi(parametro), false);
    case 3:
    if(parametro.substr(0,0)==">")
        modello->searchVelocita(std::stoi(parametro.substr(1)), true);
    else if(parametro.substr(0,0)=="<")
        modello->searchVelocita(std::stoi(parametro=parametro.substr(1)), false);
    else
        modello->searchPeso(std::stoi(parametro), false);
    case 4:
        modello->searchCarburantevapore(parametro);
    case 5:
           if(parametro.substr(0,0)==">")

               modello->searchEfficenzaelettrico(std::atof(parametro.substr(1).c_str()), true);
           else if(parametro.substr(0,0)=="<")
               modello->searchEfficenzaelettrico(std::atof(parametro.substr(1).c_str()), false);
           else
                modello->searchEfficenzaIC(std::atof(parametro.substr(1).c_str()), false);
    case 6:
        modello->searchTrasmissioneelettrico(parametro);
    case 7:
           if(parametro.substr(0,0)==">")
               modello->searchEfficenzaelettrico(std::atof(parametro.substr(1).c_str()), true);
           else if(parametro.substr(0,0)=="<")
               modello->searchEfficenzaelettrico(std::atof(parametro.substr(1).c_str()), false);
           else
               modello->searchEfficenzaIC(std::atof(parametro.substr(1).c_str()), false);
    case 8:
           if(parametro.substr(0,0)==">")
               modello->searchEfficenzaelettrico(std::atof(parametro.substr(1).c_str()), true);
           else if(parametro.substr(0,0)=="<")
               modello->searchEfficenzaelettrico(std::atof(parametro.substr(1).c_str()), false);
           else
        modello->searchEfficenzaIC(std::atof(parametro.substr(1).c_str()), false);
    case 9:
        modello->searchMotoreIC(parametro);
    case 10:
        modello->searchMotoreprimario(parametro);
    case 11:
        modello->searchTecnologiamaglev(parametro);
    }
        //catcho le eccezioni dei cast errati
        //refresh lista
}
void MainWindow::slotResetSearch(){
    //modello->resettaEntrambeLeListe();
}
MainWindow::~MainWindow()
{
}































