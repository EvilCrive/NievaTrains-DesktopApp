#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "supporto/combotype.h"
#include <QListWidget>
#include <QTextBrowser>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QLineEdit>
#include "menubartrain.h"
#include "supporto/trainlist.h"
#include "mainlayout.h"
#include "model/model.h"
#include "model/gerarchia/treno.h"
#include "supporto/aggiuntalayout.h"
#include "supporto/modificalayout.h"

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    MenuBarTrain* menu;
    Model* modello;
    MainLayout* layout;
    AggiuntaLayout *layoutAdd;
    ModificaLayout *layoutMod;

public:
    MainWindow(Model* m,QWidget *parent = nullptr);
    ~MainWindow();
    void refreshList();
public slots:
    void slotShowInfoGenerali();
    void slotCarica();
    void slotSalva();
    void slotAutori();
    void slotShowTreno();
    void slotFlush();
    void slotRemoveTreno();
    void slotShowInserimentoTreno();
    void slotInserisciTreno();
    void slotShowModificaTreno();
    void slotModificaTreno();
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
