#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMenuBar>
#include <QPushButton>
#include <QIcon>
#include <QFile>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "tictactoebutton.h"

class Controller;

class TicTacToe : public QWidget
{
    Q_OBJECT

public:
    TicTacToe(Controller* c, QWidget *parent = nullptr);
    ~TicTacToe();
    void update();
    void resetGrid();
    void showWinner();
private:
    Controller* controller;
    QVBoxLayout* mainlayout;
    QGridLayout* gridlayout;
    void addButtons();
    void addMenu();
    void setTicTacToeStyle();
public slots:
    void cellHandler(unsigned short, unsigned short) const;
};
#endif // TICTACTOE_H
