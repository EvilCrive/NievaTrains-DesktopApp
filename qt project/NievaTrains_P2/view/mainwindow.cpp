#include "mainwindow.h"
//#include "combotype.h"
#include <QMessageBox>
#include <QString>
#include "infolayout.h"
#include <iostream>
#include <QFile>
#include <QFileDialog>
using std::string;

MainWindow::MainWindow(Model* m, QWidget *parent): QWidget(parent), menu(new MenuBarTrain(this)), modello(m), layout(new MainLayout(this))
{
    setWindowTitle("Nieva Trains");
    QHBoxLayout* mainLayout= new QHBoxLayout(this);
    mainLayout->addWidget(layout);
    mainLayout->setMenuBar(menu);
    setLayout(mainLayout);
}
void MainWindow::slotShowInfoGenerali(){

    //occhio che magari il puntatore viene cancellato all'uscita ma non l'oggetto
    QString str1= "La quantità di treni presenti nel sistema è: "+QString::number(modello->numerotreni());
    QString str2= "Il peso medio dei treni nel sistema è: "+QString::number(modello->getPesoM());
    QString str3= "La velocità media dei treni nel sistema è: "+QString::number(modello->getPesoT());
    QString str4= "Il peso maggiore registrato è: "+QString::number(modello->getSpeedM());
    QString str5= "La velocità maggiore registrata è: "+QString::number(modello->getSpeedT());

    InfoLayout* info=new InfoLayout(this,str1,str2,str3,str4,str5);
    info->setMargin(13);
    info->setDimensioni(300,250);
    info->show();
}
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
        //flush
        layout->getList()->clear();
        modello->load(file.toStdString());
        if(modello->isEmpty()){
            QMessageBox::warning(this,"Attenzione!","Il file del programma e' vuoto.");
        }
        else{
            for(unsigned int i=0; i<modello->numerotreni(); i++)
                layout->getList()->addTrenoList(modello->getTreno(i));
        }
    }
}
void MainWindow::slotSalva(){
    QString file= QFileDialog::getSaveFileName(
                this,
                tr("Choose file"),
                "../NievaTrains_P2/file risorse",
                "File JSON(*.json)"
                );
    if(file!=""){
    //reset ricerca?
        modello->save(file.toStdString());
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

void MainWindow::slotFlush()
{
    layout->flushList();
}

void MainWindow::slotRemoveTreno(Treno * t)
{

}
void MainWindow::slotShowTreno(){
    std::cout<<"pre-show";
    string str=modello->print2(layout->estraiTrenoSelezionato());

    //chiamo la funzione in
    layout->stampaDettagliTreno(str);

    std::cout<<"post-show";
}
void MainWindow::slotFlush(){
    std::cout<<"pre";
    layout->flushList();
    modello->clear();
    std::cout<<"post";
}

void MainWindow::slotInserimentoTreno(){
    std::cout<<"pre";
    int x=layout->getTrenoInserimento();
    AggiuntaLayout* tmp=new AggiuntaLayout(this,x);
    tmp->show();
    std::cout<<"post";
}

MainWindow::~MainWindow()
{
}

