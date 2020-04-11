#include "tictactoebutton.h"


TicTacToeButton::TicTacToeButton(unsigned short X, unsigned short Y, QWidget * parent)
    :QPushButton(parent), x(X), y(Y)
{
    connect(this,SIGNAL(clicked()),this,SLOT(cellEmitter()));
}

void TicTacToeButton::cellEmitter()
{
    emit clickedCell(x,y);
}
