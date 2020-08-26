#ifndef MAINLAYOUT_H
#define MAINLAYOUT_H
#include <QMainWindow>
#include <QLabel>
#include "combotype.h"
#include <QListWidget>
#include <QTextBrowser>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QLineEdit>
#include "menubartrain.h"
#include "trainlist.h"
#include "model/model.h"
#include "model/gerarchia/treno.h"
#include <string>

class MainLayout: public QWidget
{
    Q_OBJECT

    QLabel* text1;
    QLabel* text2;
    QLabel* text3;
    QLabel* text4;

    ComboType* selectType;

    TrainListWidget *trainList;

    QTextBrowser* infoTrain;
    QPushButton* flush;
    QPushButton* search;
    QPushButton* annulla;
    QPushButton* modifica;
    QPushButton* elimina;
    QPushButton* inserisci;
    QLineEdit* searchBar;


public:
    int estraiTrenoSelezionato() const;
    void stampaDettagliTreno(std::string s) const;
    int getTrenoInserimento() const;
    void flushList();
    void eliminaTreno(unsigned int);
    MainLayout(QWidget * =nullptr);
    TrainListWidget *getList() const;

};

#endif // MAINLAYOUT_H
