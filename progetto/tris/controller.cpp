#include "controller.h"


Controller::Controller(Model *modello, QObject *parent): QObject(parent), view(nullptr), model(modello){}

void Controller::setView(TicTacToe *vista)
{
    view=vista;
}

int Controller::getPlayer(unsigned short x, unsigned short y) const
{
    return (*model)(x,y);
}

int Controller::getWinner() const
{
    return model->winner();
}

void Controller::move(unsigned short x, unsigned short y)
{
    model->move(x,y);
    view->update();
    if(model->winner() || (model->countFrame(player1)+model->countFrame(player2))==9){
        view->showWinner();
        resetGame();
    }

}

void Controller::resetGame()
{
    model->reset();
    view->resetGrid();
}
