#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
//#include "combotype.h"
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
#include "mainlayout.h"
#include "model/model.h"
#include "model/gerarchia/treno.h"
#include "aggiuntalayout.h"

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    MenuBarTrain* menu;
    Model* modello;
    MainLayout* layout;


public:
    MainWindow(Model* m,QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slotShowInfoGenerali();
    void slotCarica();
    void slotSalva();
    void slotAutori();
    void slotShowTreno();
    void slotFlush();
    void slotRemoveTreno(Treno*);
    void slotInserimentoTreno();
/*    void slotMostraTreno(Treno*);
    void slotEsporta();
    void slotImporta();

    void slotModificaTreno(Treno*);
    void slotShowInserisci();
    void slotEliminaTreno(Treno*);
    void slotCerca();
    void slotAnnullaRicerca();

    //void slotConfermaCreazione(VISTA::getDialogCreazione, VISTA::getTendina);
    void slotAnnullaCreazione();*/
};
#endif // MAINWINDOW_H
