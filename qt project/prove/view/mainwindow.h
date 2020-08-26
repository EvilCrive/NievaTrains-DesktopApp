#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Model* list;
    QLabel* text1;
    QLabel* text2;
    QLabel* text3;
    QLabel* text4;

    ComboType* selectType;

    TrainListWidget *trainListWidget;
    QTextBrowser* infoTrain;
    QPushButton* flush;
    QPushButton* search;
    QPushButton* annulla;
    QPushButton* elimina;
    QPushButton* inserisci;
    QLineEdit* searchBar;
    MenuBarTrain* menu;

public slots:


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
