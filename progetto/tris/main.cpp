#include "tictactoe.h"

#include <QApplication>
#include "controller.h"
#include "tictactoe.h"
#include "model.h"
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model m;
    Controller c(&m);
    TicTacToe v(&c);
    c.setView(&v);
    v.show();
    return a.exec();

}
