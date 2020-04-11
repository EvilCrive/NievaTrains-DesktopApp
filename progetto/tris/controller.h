#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "model.h"
#include "tictactoe.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(Model* modello, QObject *parent = nullptr);
    void setView(TicTacToe* vista);
    int getPlayer(unsigned short x, unsigned short y)const;
    int getWinner() const;

public slots:
    void move(unsigned short, unsigned short);
    void resetGame();

private:
    TicTacToe* view;
    Model* model;

};

#endif // CONTROLLER_H
