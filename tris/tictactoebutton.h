#ifndef TICTACTOEBUTTON_H
#define TICTACTOEBUTTON_H

#include <QPushButton>

class TicTacToeButton : public QPushButton
{
    Q_OBJECT
public:
    TicTacToeButton(unsigned short, unsigned short, QWidget* = nullptr);

signals:
    void clickedCell(unsigned short, unsigned short);
private:
    unsigned short x,y;

private slots:
    void cellEmitter();


};

#endif // TICTACTOEBUTTON_H
