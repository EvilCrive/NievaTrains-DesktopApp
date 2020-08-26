#include "mainlayout.h"

MainLayout::MainLayout(QWidget* p): QWidget(p),
    text1(new QLabel(this)),
    text2(new QLabel(this)),
    text3(new QLabel(this)),
    text4(new QLabel(this)),
    selectType(new ComboType(this)),
    infoTrain(new QTextBrowser(this)),
    flush(new QPushButton(this)),
    search(new QPushButton(this)),
    annulla(new QPushButton(this)),
    modifica(new QPushButton(this)),
    elimina(new QPushButton(this)),
    inserisci(new QPushButton(this)),
    searchBar(new QLineEdit(this))


{
    trainList=new TrainListWidget(this);
    trainList->setSelectionMode(QAbstractItemView::SingleSelection);
    setWindowTitle("Nieva Trains");
    text1->setText("Treni nel sistema");
    text2->setText("Informazioni specifiche");
    text3->setText("Inserisci treno");
    text4->setText("Cerca per nome");

    flush->setText("Flush");
    search->setText("Search");
    annulla->setText("Annulla");
    modifica->setText("Modifica");
    elimina->setText("Elimina");
    inserisci->setText("Inserisci");

    QHBoxLayout* layout=new QHBoxLayout(this);
    //layout->setMenuBar(new menuBarTrain);
    QVBoxLayout* left=new QVBoxLayout(this);
    QVBoxLayout* right=new QVBoxLayout(this);
    QHBoxLayout* searchField=new QHBoxLayout(this);
    QHBoxLayout* bts2=new QHBoxLayout(this);
    QHBoxLayout* bts3=new QHBoxLayout(this);

    left->addWidget(text1);
    left->addWidget(trainList);
    left->addWidget(flush);
    searchField->addWidget(searchBar);
    searchField->addWidget(search);
    searchField->addWidget(annulla);
    bts2->addWidget(modifica);
    bts2->addWidget(elimina);
    bts3->addWidget(selectType);
    bts3->addWidget(inserisci);
    right->addWidget(text4);
    right->addLayout(searchField);
    right->addWidget(text2);
    right->addWidget(infoTrain);
    right->addLayout(bts2);
    right->addWidget(text3);
    right->addLayout(bts3);
    layout->addLayout(left, 35);
    layout->addLayout(right, 65);
    setLayout(layout);

    //connect(flush,SIGNAL(clicked()),p,SLOT(slotFlush()));
}
TrainListWidget* MainLayout::getList() const{
    return trainList;
}
