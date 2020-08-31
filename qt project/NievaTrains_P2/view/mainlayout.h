#ifndef MAINLAYOUT_H
#define MAINLAYOUT_H
#include <QMainWindow>
#include <QLabel>
#include "supporto/combotype.h"
#include "supporto/combofilter.h"
#include <QListWidget>
#include <QTextBrowser>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QLineEdit>
#include "supporto/trainlist.h"
#include <string>

class MainLayout: public QWidget
{
    Q_OBJECT

    QLabel* text1;
    QLabel* text2;
    QLabel* text3;
    QLabel* text4;

    ComboType* selectType;
    ComboFilter* selectFilter;

    TrainListWidget *trainList;

    QTextBrowser* infoTrain;
    QPushButton* flush;
    QPushButton* search;
    QPushButton* annulla;
    QPushButton* modifica;
    QPushButton* elimina;
    QPushButton* inserisci;
    QLineEdit* searchBar;

    QLineEdit* kmPerBar;
    QLineEdit* carbNecessarioBar;
    QPushButton* kmPer;
    QPushButton* carbNecessario;

public:
    int estraiTrenoSelezionato() const;
    void stampaDettagliTreno(std::string s) const;
    int getTrenoInserimento() const;
    int getFiltro() const;
    std::string getParametroRicerca() const;
    unsigned int getKm() const;
    unsigned int getCarb() const;
    void flushList();
    void eliminaTreno(unsigned int);
    MainLayout(QWidget * =nullptr);
    TrainListWidget *getList() const;

};

#endif // MAINLAYOUT_H
