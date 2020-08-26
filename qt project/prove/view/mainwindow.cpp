#include "mainwindow.h"
#include "combotype.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    list(new Model),
      text1(new QLabel(this)),
      text2(new QLabel(this)),
      text3(new QLabel(this)),
      text4(new QLabel(this)),
      selectType(new ComboType(this)),
      trainListWidget(new TrainListWidget(this)),
      infoTrain(new QTextBrowser(this)),
      flush(new QPushButton(this)),
      search(new QPushButton(this)),
      annulla(new QPushButton(this)),
      elimina(new QPushButton(this)),
      inserisci(new QPushButton(this)),
      searchBar(new QLineEdit(this)),
      menu(new MenuBarTrain(this))

{

    // GENERAZIONE GRAFICA
    setWindowTitle("Nieva Trains");
    text1->setText("Treni nel sistema");
    text2->setText("Informazioni specifiche");
    text3->setText("Inserisci treno");
    text4->setText("Cerca per nome");

    flush->setText("Flush");
    search->setText("Search");
    annulla->setText("Annulla");
    elimina->setText("Elimina");
    inserisci->setText("Inserisci");

    QHBoxLayout* layout=new QHBoxLayout(this);
    layout->setMenuBar(menu);
    QVBoxLayout* left=new QVBoxLayout(this);
    QVBoxLayout* right=new QVBoxLayout(this);
    QHBoxLayout* searchField=new QHBoxLayout(this);
    QHBoxLayout* bts3=new QHBoxLayout(this);

    left->addWidget(text1);
    left->addWidget(trainListWidget);
    left->addWidget(flush);
    searchField->addWidget(searchBar);
    searchField->addWidget(search);
    searchField->addWidget(annulla);
    bts3->addWidget(selectType);
    bts3->addWidget(inserisci);
    right->addWidget(text4);
    right->addLayout(searchField);
    right->addWidget(text2);
    right->addWidget(infoTrain);
    right->addWidget(elimina);
    right->addWidget(text3);
    right->addLayout(bts3);
    layout->setMenuBar(menu);
    layout->addLayout(left, 35);
    layout->addLayout(right, 65);


    QWidget *placeholderWidget = new QWidget;
    placeholderWidget->setLayout(layout);
    setCentralWidget(placeholderWidget);

}

MainWindow::~MainWindow()
{
}

