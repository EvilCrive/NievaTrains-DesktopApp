#include "mainwindow.h"
#include "combotype.h"
#include <QMessageBox>
#include <QString>
#include "infolayout.h"
#include <iostream>
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
   /* double pesoM=modello->getPesoM();
    double pesoT=modello->getPesoT();
    unsigned int velM=modello->getSpeedM();
    unsigned int velT=modello->getSpeedT();*/

    //occhio che magari il puntatore viene cancellato all'uscita ma non l'oggetto
    InfoLayout* info=new InfoLayout(this,1,2,3,4,5);
    info->show();
}
void MainWindow::slotCarica(){
    std::cout<<"pre-carica";
    modello->load("C:\\Users\\matbr\\Desktop\\data.json");
    for(unsigned int i=0; i<modello->numerotreni(); i++)
        layout->getList()->addTrenoList(modello->getTreno(i));
    std::cout<<"post-carica";
}
void MainWindow::slotSalva(){
    std::cout<<"pre-save";
    modello->save("C:\\Users\\matbr\\Desktop\\nodata.jso");
    std::cout<<"post-save";
}
MainWindow::~MainWindow()
{
}

