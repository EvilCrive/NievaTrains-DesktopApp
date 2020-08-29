#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
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
#include "aggiuntalayout.h"
#include "modificalayout.h"

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
    void slotCerca();
    void slotResetSearch();
};
#endif // MAINWINDOW_H
