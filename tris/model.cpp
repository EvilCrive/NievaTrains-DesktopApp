#include "model.h"

Model::Model()
{
    reset();
}

bool Model::move(unsigned short x, unsigned short y)
{
    if(x<0U || x>2 || y<0U || y>2)    return false;
    //se esiste un vincitore
    if(winner())
        return false;
    //se la cella è occupata
    if(grid[x*3 +y])
        return false;
    //altrimenti fare mossa
    grid[x*3 +y]= (turn ? player2 : player1);
    if(turn)    turn=false;
    else    turn=true;
    return true;
}

Player Model::winner() const
{
    for(unsigned short i=0; i<3; i++){
    //righe

        if(checkWinner(i*3,i*3+1,i*3+2))
            return grid[i*3];
    //colonne
        if(checkWinner(i,3+i,6+i))
            return grid[i];
    }
    //diagonali
    if(checkWinner(0,4,8))
        return grid[0];
    if(checkWinner(2,4,6))
        return grid[2];
    return none;
}

void Model::reset()
{
    turn=0;
    for(unsigned short i=0; i<9; i++)   grid[i]=none;
}

unsigned short Model::countFrame(Player p) const
{
    unsigned short count=0U;
    for(unsigned short i = 0U; i<9; i++){
        if(grid[i]==p)  count++;
    }
    return count;
}

Player Model::operator()(unsigned short row, unsigned short column) const
{
    if(row<0U || row>2 || column<0U || column>2)    return none;
    return grid[3*row+column];
}

bool Model::checkWinner(unsigned short i, unsigned short j, unsigned short k) const
{
    return grid[i] && (grid[i]==grid[j]) && (grid[i]==grid[k]);
}
