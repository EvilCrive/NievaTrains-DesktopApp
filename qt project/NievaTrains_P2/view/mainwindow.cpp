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
        layout->getList()->addTrenoList(modello->getTreno(i),i); //asd123
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
        try{
        modello->load(file.toStdString());

        }catch(NievaException* e){QMessageBox::warning(this,"Nieva Trains",QString::fromStdString(e->getMessage()));}
        if(modello->isEmpty()){
            QMessageBox::warning(this,"Nieva Trains","Il file e' vuoto.");
        }
        else{
            refreshList();
        }
    }else{
        QMessageBox::warning(this,"Nieva Trains","Seleziona un file.");
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
        try{modello->save(file.toStdString());}catch(NievaException* e){QMessageBox::warning(this,"Nieva Trains",QString::fromStdString(e->getMessage()));}
    }else{
        QMessageBox::warning(this,"Nieva Trains","Seleziona un file.");
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


void MainWindow::slotRemoveTreno() try
{
    if(layout->estraiTrenoSelezionato()==-1)   throw new NievaException("Seleziona un treno esistente da eliminare");
        unsigned int t=layout->estraiTrenoSelezionato();
        unsigned int i=layout->getList()->getItem()->getRealIndex();
        layout->eliminaTreno(t);
        modello->erase(i);

        refreshList();
}catch(NievaException* e){
    QMessageBox::warning(this,"Nieva Trains",QString::fromStdString(e->getMessage()));
}

void MainWindow::slotShowTreno(){
    string str="";
    if(layout->estraiTrenoSelezionato()!=-1 && layout->getList()->getItem()){
        std::cout<<" "<<layout->getList()->getItem()->getRealIndex();
        str=modello->treno2string(layout->getList()->getItem()->getRealIndex());
    }
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
    layoutAdd->exec();
}
void MainWindow::slotInserisciTreno(){
    unsigned int x=layoutAdd->getTipo();
    std::string nome=layoutAdd->getNome();
    std::string costruttore=layoutAdd->getCostruttore();
    unsigned int speed=layoutAdd->getSpeed();
    unsigned int peso=layoutAdd->getPeso();
    if(x==0){
        double efficenzaS=layoutAdd->getEfficenzaS();
        if(efficenzaS<0 || efficenzaS>1){
            QMessageBox::warning(this,"Nieva Trains","Efficenza dev'essere compresa tra 0 e 1.\nVerra' settata a 0.5");
            efficenzaS=0.5;
        }
        std::string carburanteS=layoutAdd->getCarburanteS();
        Steam* train=new Steam(nome, costruttore, speed, peso, efficenzaS, carburanteS);
        modello->push_end(train);
    }else if(x==1){
        double efficenzaE=layoutAdd->getEfficenzaE();
        if(efficenzaE<0 || efficenzaE>1){
            QMessageBox::warning(this,"Nieva Trains","Efficenza dev'essere compresa tra 0 e 1.\nVerra' settata a 0.5");
            efficenzaE=0.5;
        }
        bool trasmissione=layoutAdd->getTrasmissione();
        Electric* train=new Electric(nome, costruttore, peso, speed, trasmissione, efficenzaE);
        modello->push_end(train);
    }else if(x==2){
        std::string motoreIC=layoutAdd->getMotoreIC();
        double efficenzaIC=layoutAdd->getEfficenzaIC();
        if(efficenzaIC<0 || efficenzaIC>1){
            QMessageBox::warning(this,"Nieva Trains","Efficenza dev'essere compresa tra 0 e 1.\nVerra' settata a 0.5");
            efficenzaIC=0.5;
        }
        Internal_Combustion* train= new Internal_Combustion(nome, costruttore, peso, speed, efficenzaIC, motoreIC);
        modello->push_end(train);
    }else if(x==3){
        bool tecnologia=layoutAdd->getTecnologia();
        Maglev* train= new Maglev(nome, costruttore, peso, speed, tecnologia);
        modello->push_end(train);
    }else{
        double efficenzaE=layoutAdd->getEfficenzaE();
        if(efficenzaE<0 || efficenzaE>1){
            QMessageBox::warning(this,"Nieva Trains","Efficenza dev'essere compresa tra 0 e 1.\nVerra' settata a 0.5");
            efficenzaE=0.5;
        }
        bool trasmissione=layoutAdd->getTrasmissione();
        std::string motoreIC=layoutAdd->getMotoreIC();
        double efficenzaIC=layoutAdd->getEfficenzaIC();
        if(efficenzaIC<0 || efficenzaIC>1){
            QMessageBox::warning(this,"Nieva Trains","Efficenza dev'essere compresa tra 0 e 1.\nVerra' settata a 0.5");
            efficenzaIC=0.5;
        }
        bool primario=layoutAdd->getPrimario();
        Bimode* train= new Bimode(nome, costruttore, peso, speed, trasmissione, efficenzaE, efficenzaIC, motoreIC, primario);
        modello->push_end(train);
    }
    //prende l'ultimo treno del modello e lo aggiunge alla lista
    layout->getList()->addTrenoList(modello->getTreno(modello->numerotreni()-1),modello->numerotreni()-1); //asd123
    layout->getList()->setCurrentRow(modello->numerotreni()-1);
    //aggiornamento lista view
    layoutAdd->close();
    delete layoutAdd;
}
void MainWindow::slotShowModificaTreno() try{
    if(layout->estraiTrenoSelezionato()==-1)   throw new NievaException("Seleziona un treno esistente da modificare");
    unsigned int indecs=layout->getList()->getItem()->getRealIndex();
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
    layoutMod->exec();
}catch(NievaException* e){
    QMessageBox::warning(this,"Nieva Trains",QString::fromStdString(e->getMessage()));
}
void MainWindow::slotModificaTreno(){
    unsigned int x=layoutMod->getInd(); //è l'indice reale
    unsigned int tip=layoutMod->getTipo();
    //in base al tipo identificato da tip creo un nuovo treno e lo inserisco nel modello
    std::string nomeNew=layoutMod->getNome();
    std::string costruttoreNew=layoutMod->getCostruttore();
    unsigned int speedNew=layoutMod->getSpeed();
    unsigned int pesoNew=layoutMod->getPeso();
    if(tip==0){
        double efficenzaSNew=layoutMod->getEfficenzaS();
        if(efficenzaSNew<0 || efficenzaSNew>1){
            QMessageBox::warning(this,"Nieva Trains","Efficenza dev'essere compresa tra 0 e 1.\nVerra' settata a 0.5");
            efficenzaSNew=0.5;
        }
        std::string carburanteSNew=layoutMod->getCarburanteS();
        Steam* trenoDaSostituire=new Steam(nomeNew, costruttoreNew, speedNew, pesoNew, efficenzaSNew, carburanteSNew);
        modello->sostituisci(trenoDaSostituire, x);
    }else if(tip==1){
        double efficenzaENew=layoutMod->getEfficenzaE();
        if(efficenzaENew<0 || efficenzaENew>1)    {
            QMessageBox::warning(this,"Nieva Trains","Efficenza dev'essere compresa tra 0 e 1.\nVerra' settata a 0.5");
            efficenzaENew=0.5;
        }
        bool trasmissioneNew=layoutMod->getTrasmissione();
        Electric* trenoDaSostituire=new Electric(nomeNew, costruttoreNew, speedNew, pesoNew, trasmissioneNew, efficenzaENew);
        modello->sostituisci(trenoDaSostituire, x);
    }else if(tip==2){
        std::string motoreICNew=layoutMod->getMotoreIC();
        double efficenzaICNew=layoutMod->getEfficenzaIC();
        if(efficenzaICNew<0 || efficenzaICNew>1){
            QMessageBox::warning(this,"Nieva Trains","Efficenza dev'essere compresa tra 0 e 1.\nVerra' settata a 0.5");
            efficenzaICNew=0.5;
        }
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
        if(efficenzaICNew<0 || efficenzaICNew>1){
            QMessageBox::warning(this,"Nieva Trains","Efficenza dev'essere compresa tra 0 e 1.\nVerra' settata a 0.5");
            efficenzaICNew=0.5;
        }
        if(efficenzaENew<0 || efficenzaENew>1){
            QMessageBox::warning(this,"Nieva Trains","Efficenza dev'essere compresa tra 0 e 1.\nVerra' settata a 0.5");
            efficenzaENew=0.5;
        }
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
    layoutMod->close();
    delete layoutMod;
}
void MainWindow::slotCerca(){
    try{
    unsigned int filtro=layout->getFiltro();
    std::string parametro=layout->getParametroRicerca();
    switch(filtro){
    case 0:
        searchNome(parametro);
        break;
    case 1:
        searchCostruttore(parametro);
        break;
    case 2:
    if(parametro.substr(0,1)=="<")
        searchPeso(std::stoi(parametro.substr(1)), false);
    else if(parametro.substr(0,1)==">")
        searchPeso(std::stoi(parametro=parametro.substr(1)), true);
    else
        searchPeso(std::stoi(parametro), false);
    break;
    case 3:
    if(parametro.substr(0,1)=="<")
        searchVelocita(std::stoi(parametro.substr(1)), true);
    else if(parametro.substr(0,1)==">")
        searchVelocita(std::stoi(parametro=parametro.substr(1)), false);
    else
        searchVelocita(std::stoi(parametro), false);
    break;
    case 4:
        searchMotoreIC(parametro);
        break;
    case 5:
           if(parametro.substr(0,1)=="<")
               searchEfficenzaIC(std::atof(parametro.substr(1).c_str()), true);
           else if(parametro.substr(0,1)==">")
               searchEfficenzaIC(std::atof(parametro.substr(1).c_str()), false);
           else
               searchEfficenzaIC(std::atof(parametro.substr(1).c_str()), false);
           break;
    case 6:
        searchTrasmissioneelettrico(parametro);
        break;
    case 7:
           if(parametro.substr(0,1)=="<")
               searchEfficenzaelettrico(std::atof(parametro.substr(1).c_str()), true);
           else if(parametro.substr(0,1)==">")
               searchEfficenzaelettrico(std::atof(parametro.substr(1).c_str()), false);
           else
               searchEfficenzaelettrico(std::atof(parametro.substr(1).c_str()), false);
           break;
    case 8:
           if(parametro.substr(0,1)=="<")
               searchEfficenzavapore(std::atof(parametro.substr(1).c_str()), true);
           else if(parametro.substr(0,1)==">")
               searchEfficenzavapore(std::atof(parametro.substr(1).c_str()), false);
           else
               searchEfficenzavapore(std::atof(parametro.substr(1).c_str()), false);
           break;
    case 9:
        searchCarburantevapore(parametro);
        break;
    case 10:
        searchTecnologiamaglev(parametro);
        break;
    case 11:
        searchMotoreprimario(parametro);
        break;

    }
    }catch(...){
        QMessageBox::warning(this,"Nieva Trains","eccezione ricerca");
    }

        //catcho le eccezioni dei cast errati
}
void MainWindow::slotResetSearch(){
    refreshList();
}
using std::cout;
/*filtri*/
void MainWindow::searchNome(std::string n)
{
    unsigned int lun=layout->getList()->count();
    for(unsigned int i=0; i<lun; ++i){
        std::string nome=layout->getList()->getItemByIndex(i)->getNome();
        transform(nome.begin(), nome.end(), nome.begin(),
            [](unsigned char c){ return toupper(c); });
        transform(n.begin(), n.end(), n.begin(),
            [](unsigned char c){ return toupper(c); });
        if(n!=nome){
            if(nome.find(n)==std::string::npos){
                layout->getList()->erase(i);
                --i; --lun;
            }
        }
    }
}
void MainWindow::searchCostruttore(std::string n)
{
    unsigned int lun=layout->getList()->count();
    for(unsigned int i=0; i<lun; ++i){
        std::string costruttore=layout->getList()->getItemByIndex(i)->getCostruttore();
        transform(costruttore.begin(), costruttore.end(), costruttore.begin(),
            [](unsigned char c){ return toupper(c); });
        transform(n.begin(), n.end(), n.begin(),
            [](unsigned char c){ return toupper(c); });
        if(n!=layout->getList()->getItemByIndex(i)->getCostruttore()){
            if(costruttore.find(n)==std::string::npos){
                layout->getList()->erase(i);
                --i; --lun;
            }
        }
    }
}
void MainWindow::searchMotoreIC(std::string n){
    unsigned int lun=layout->getList()->count();
    for(unsigned int i=0; i<lun; ++i){
        if(dynamic_cast<Internal_Combustion*>(layout->getList()->getItemByIndex(i))){
            Internal_Combustion* t=dynamic_cast<Internal_Combustion*>(layout->getList()->getItemByIndex(i));
            std::string motore=t->getMotoreIC();
            transform(motore.begin(), motore.end(), motore.begin(),
                [](unsigned char c){ return toupper(c); });
            transform(n.begin(), n.end(), n.begin(),
                [](unsigned char c){ return toupper(c); });
            if(n!=motore){
                if(motore.find(n)==std::string::npos){
                    layout->getList()->erase(i);
                    --i; --lun;
                }
            }
        }else{
                layout->getList()->erase(i);
                --i; --lun;
            }
        }
    }
void MainWindow::searchCarburantevapore(std::string n){
    unsigned int lun=layout->getList()->count();
    for(unsigned int i=0; i<lun; ++i){
        if(layout->getList()->getItemByIndex(i)->type()=="Steam"){
            Steam* t=static_cast<Steam*>(layout->getList()->getItemByIndex(i));
            std::string fuel=t->getCarburanteSteam();
            transform(fuel.begin(), fuel.end(), fuel.begin(),
                [](unsigned char c){ return toupper(c); });
            transform(n.begin(), n.end(), n.begin(),
                [](unsigned char c){ return toupper(c); });
            if(n!=fuel){
                if(fuel.find(n)==std::string::npos){
                    layout->getList()->erase(i);
                    --i; --lun;
                };
            }
        }
        else{
            layout->getList()->erase(i);
            --i; --lun;
        }
    }
}

void MainWindow::searchPeso(unsigned int n, bool b){
    unsigned int lun=layout->getList()->count();
    for(unsigned int i=0; i<lun; ++i){
        if(b && layout->getList()->getItemByIndex(i)->getPeso()<n){
            //maggiore
            layout->getList()->erase(i);
            --i; --lun;
        }else if(!b && layout->getList()->getItemByIndex(i)->getPeso()>=n){
            //minore
            layout->getList()->erase(i);
            --i; --lun;
        }
    }
}
void MainWindow::searchVelocita(unsigned int n, bool b){
    unsigned int lun=layout->getList()->count();
    for(unsigned int i=0; i<lun; ++i){
        if(b && layout->getList()->getItemByIndex(i)->getSpeed()<n){
            //maggiore
            layout->getList()->erase(i);
            --i; --lun;
        }else if(!b && layout->getList()->getItemByIndex(i)->getSpeed()>=n){
            //minore
            layout->getList()->erase(i);
            --i; --lun;
        }
    }
}


void MainWindow::searchEfficenzavapore(double n, bool b){
    unsigned int lun=layout->getList()->count();
    for(unsigned int i=0; i<lun; ++i){
        if(layout->getList()->getItemByIndex(i)->type()=="Steam"){
            Steam* t=static_cast<Steam*>(layout->getList()->getItemByIndex(i));
            if(b && n<t->getEfficenzaSteam()){
                layout->getList()->erase(i);
                --i; --lun;
            }else if(!b && n>=t->getEfficenzaSteam()){
                layout->getList()->erase(i);
                --i; --lun;
            }
        }
        else{
            layout->getList()->erase(i);
            --i; --lun;
        }
    }
}
void MainWindow::searchEfficenzaelettrico(double n, bool b){
    unsigned int lun=layout->getList()->count();
    for(unsigned int i=0; i<lun; ++i){
        if(layout->getList()->getItemByIndex(i)->type()=="Electric" || layout->getList()->getItemByIndex(i)->type()=="Bimode"){
            Electric* t=dynamic_cast<Electric*>(layout->getList()->getItemByIndex(i));
            if(t){
                if(b && n<t->getEfficenzaElettrico()){
                    layout->getList()->erase(i);
                    --i; --lun;
                }else if(!b && n>=t->getEfficenzaElettrico()){
                    layout->getList()->erase(i);
                    --i; --lun;
                }
            }
            else{
                layout->getList()->erase(i);
                --i; --lun;
            }
        }
    }
}
void MainWindow::searchEfficenzaIC(double n, bool b){
    unsigned int lun=layout->getList()->count();
    for(unsigned int i=0; i<lun; ++i){
        if(layout->getList()->getItemByIndex(i)->type()=="Internal Combustion" || layout->getList()->getItemByIndex(i)->type()=="Bimode"){
            Internal_Combustion* t=dynamic_cast<Internal_Combustion*>(layout->getList()->getItemByIndex(i));
            if(t){
                if(b && n<t->getEfficenzaIC()){
                    layout->getList()->erase(i);
                    --i; --lun;
                }else if(!b && n>=t->getEfficenzaIC()){
                    layout->getList()->erase(i);
                    --i; --lun;
                }
            }
            else{
                layout->getList()->erase(i);
                --i; --lun;
            }
        }
    }
}
void MainWindow::searchTrasmissioneelettrico(std::string n){
    unsigned int lun=layout->getList()->count();
    for(unsigned int i=0; i<lun; ++i){
        if(layout->getList()->getItemByIndex(i)->type()=="Electric" || layout->getList()->getItemByIndex(i)->type()=="Bimode"){
            Electric* t=dynamic_cast<Electric*>(layout->getList()->getItemByIndex(i));
            if(t){
                bool  test;
                transform(n.begin(), n.end(), n.begin(),
                    [](unsigned char c){ return tolower(c); });
                if(n=="third rail") test=true;
                else if(n=="overhead line")    test=false;
                //eccezione ?
                else    return;
                if(test!=t->getTrasmissioneElettrico()){
                        layout->getList()->erase(i);
                        --i; --lun;
                }
            }
            else{
                layout->getList()->erase(i);
                --i; --lun;
            }
        }
    }
}
void MainWindow::searchMotoreprimario(std::string n){
    unsigned int lun=layout->getList()->count();
    for(unsigned int i=0; i<lun; ++i){
        if(layout->getList()->getItemByIndex(i)->type()=="Bimode"){
            Bimode* t=dynamic_cast<Bimode*>(layout->getList()->getItemByIndex(i));
            if(t){
                transform(n.begin(), n.end(), n.begin(),
                    [](unsigned char c){ return tolower(c); });
                bool test;
                if(n=="internal combustion") test=true;
                else if(n=="electric")    test=false;
                //eccezione ?
                else    return;
                if(test!=t->getMotorePrimario()){
                    layout->getList()->erase(i);
                    --i; --lun;
                }
            }
        }
        else{
            layout->getList()->erase(i);
            --i; --lun;
        }
    }
}
void MainWindow::searchTecnologiamaglev(std::string n){
    unsigned int lun=layout->getList()->count();
    for(unsigned int i=0; i<lun; ++i){
        if(layout->getList()->getItemByIndex(i)->type()=="Maglev"){
            Maglev* t=static_cast<Maglev*>(layout->getList()->getItemByIndex(i));
            bool test;
            transform(n.begin(), n.end(), n.begin(),
                [](unsigned char c){ return toupper(c); });
            if(n=="eds") test=true;
            else if(n=="ems")    test=false;
            //eccezione ?
            else return;
            if(test!=t->getTecnologia()){
                layout->getList()->erase(i);
                --i; --lun;
            }
        }
        else{
            layout->getList()->erase(i);
            --i; --lun;
        }
    }
}
void MainWindow::slotKmPercorribili(){
    if(layout->getList()->getItem()){
        unsigned int mostra=layout->getList()->getItem()->getTreno()->kmPercorribili(layout->getCarb());
        std::string str="I km percorribili dal treno selezionato con "+std::to_string(layout->getCarb())+" unità di carburante sono: "+std::to_string(mostra)+"km.";
        QMessageBox::information(this,"Nieva Trains",QString::fromStdString(str));
    }
}
void MainWindow::slotCarburanteNecessario(){
    if(layout->getList()->getItem()){
        unsigned int mostra=layout->getList()->getItem()->getTreno()->carburanteNecessario(layout->getKm());
        std::string str="Le unità di carburante necessarie dal treno selezionato per percorrere "+std::to_string(layout->getKm())+"km sono: "+std::to_string(mostra);
        QMessageBox::information(this,"Nieva Trains",QString::fromStdString(str));
    }
}
MainWindow::~MainWindow()
{
}































