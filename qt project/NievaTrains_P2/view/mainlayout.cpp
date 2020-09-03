#include "mainlayout.h"
#include "menubartrain.h"
#include "model/model.h"
#include <iostream>

MainLayout::MainLayout(QWidget* p): QWidget(p),
    text1(new QLabel(this)),
    text2(new QLabel(this)),
    text3(new QLabel(this)),
    text4(new QLabel(this)),
    selectType(new ComboType(this)),
    selectFilter(new ComboFilter(this)),
    infoTrain(new QTextBrowser(this)),
    flush(new QPushButton(this)),
    search(new QPushButton(this)),
    annulla(new QPushButton(this)),
    modifica(new QPushButton(this)),
    elimina(new QPushButton(this)),
    inserisci(new QPushButton(this)),
    searchBar(new QLineEdit(this)),
    kmPerBar(new QLineEdit(this)),
    carbNecessarioBar(new QLineEdit(this)),
    kmPer(new QPushButton(this)),
    carbNecessario(new QPushButton(this))


{
    trainList=new TrainListWidget(this);
    trainList->setSelectionMode(QAbstractItemView::SingleSelection);
    setWindowTitle("Nieva Trains");
    text1->setText("Treni nel sistema");
    text2->setText("Informazioni specifiche");
    text3->setText("Inserisci treno");
    text4->setText("Cerca");

    flush->setText("Svuota");
    search->setText("Cerca");
    annulla->setText("Annulla");
    modifica->setText("Modifica");
    elimina->setText("Elimina");
    inserisci->setText("Inserisci");
    carbNecessario->setText("Calcola carburante");
    kmPer->setText("Calcola Km");
    carbNecessarioBar->setPlaceholderText("Inserisci i Km da percorrere");
    kmPerBar->setPlaceholderText("Inserisci il carburante disponibile");

    QHBoxLayout* layout=new QHBoxLayout(this);
    QVBoxLayout* left=new QVBoxLayout();
    QVBoxLayout* right=new QVBoxLayout();
    QHBoxLayout* searchField=new QHBoxLayout();
    QHBoxLayout* bts2=new QHBoxLayout();
    QHBoxLayout* bts3=new QHBoxLayout();
    QHBoxLayout* km=new QHBoxLayout();
    QHBoxLayout* carb=new QHBoxLayout();

    left->addWidget(text1);
    left->addWidget(trainList);
    left->addWidget(flush);
    searchBar->setPlaceholderText("Cerca");
    searchBar->setValidator(new QRegExpValidator(QRegExp("[A-Z0-9a-z<>=, ]{0,50}/i")));//aggiungere il . se si vuole usare la rierca dell'efficenza elettrico su windows
    carbNecessarioBar->setValidator(new QRegExpValidator(QRegExp("[0-9]{0,50}/i")));
    kmPerBar->setValidator(new QRegExpValidator(QRegExp("[0-9]{0,50}/i"))); 
    searchField->addWidget(searchBar);
    searchField->addWidget(selectFilter);
    searchField->addWidget(search);
    searchField->addWidget(annulla);
    bts2->addWidget(modifica);
    bts2->addWidget(elimina);
    bts3->addWidget(selectType);
    bts3->addWidget(inserisci);
    km->addWidget(kmPerBar);
    km->addWidget(kmPer);
    carb->addWidget(carbNecessarioBar);
    carb->addWidget(carbNecessario);
    right->addWidget(text4);
    right->addLayout(searchField);
    right->addWidget(text2);
    right->addWidget(infoTrain);
    right->addLayout(bts2);
    right->addLayout(km);
    right->addLayout(carb);
    right->addWidget(text3);
    right->addLayout(bts3);
    layout->addLayout(left, 35);
    layout->addLayout(right, 65);
    setLayout(layout);


    connect(flush, SIGNAL(clicked()),p,SLOT(slotFlush()));
    connect(elimina, SIGNAL(clicked()),p,SLOT(slotRemoveTreno()));
    connect(inserisci, SIGNAL(clicked()),p,SLOT(slotShowInserimentoTreno()));
    connect(modifica, SIGNAL(clicked()),p,SLOT(slotShowModificaTreno()));
    connect(search, SIGNAL(clicked()), p, SLOT(slotCerca()));
    connect(annulla, SIGNAL(clicked()), p, SLOT(slotResetSearch()));
    connect(kmPer, SIGNAL(clicked()), p, SLOT(slotKmPercorribili()));
    connect(carbNecessario, SIGNAL(clicked()), p, SLOT(slotCarburanteNecessario()));

}
/**
 * @brief estraiTrenoSelezionato ritorna l'indice del treno selezionato nella lista dei treni
 * @return intero rappresentante un indice
 */
int MainLayout::estraiTrenoSelezionato() const{
    return trainList->getIndex();
}
TrainListWidget* MainLayout::getList() const{
    return trainList;
}
/**
 * @brief stampaDettagliTreno stampa nell'apposito spazio la stringa che gli viene passata (che rappresenterà un treno in questo formato)
 * @param s= treno in formato stringa
 */
void MainLayout::stampaDettagliTreno(std::string s) const{
    infoTrain->clear();
    infoTrain->setText(QString::fromStdString(s));
}
/**
 * @brief flushList svuota la lista dei treni
 */
void MainLayout::flushList(){
    infoTrain->clear();
    trainList->clear();
}
void MainLayout::eliminaTreno(unsigned int t)
{
    trainList->erase(t);
}
int MainLayout::getTrenoInserimento() const{
    return selectType->currentIndex();
}
int MainLayout::getFiltro() const{
    return selectFilter->currentIndex();
}
std::string MainLayout::getParametroRicerca() const{
    return searchBar->text().toStdString();
}
unsigned int MainLayout::getKm() const{
    return kmPerBar->text().toUInt();
}
unsigned int MainLayout::getCarb() const{
    return carbNecessarioBar->text().toUInt();
}
