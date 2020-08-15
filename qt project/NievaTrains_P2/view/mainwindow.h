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

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QLabel* text1;
    QLabel* text2;
    QLabel* text3;
    QLabel* text4;

    ComboType* selectType;

    QListWidget* trainList;
    QTextBrowser* infoTrain;
    QPushButton* flush;
    QPushButton* search;
    QPushButton* annulla;
    QPushButton* modifica;
    QPushButton* elimina;
    QPushButton* inserisci;
    QLineEdit* searchBar;
    MenuBarTrain* menu;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
