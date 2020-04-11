#ifndef MODEL_H
#define MODEL_H
enum Player { none=0, player1=1, player2=2};

class Model
{
public:
    Model();
    //svolgimento mossa
    bool move(unsigned short, unsigned short);
    //segnalazione vincitore
    Player winner() const;
    //reset
    void reset();
    unsigned short int countFrame(Player)const;
    Player operator()(unsigned short, unsigned short)const;

private:
    bool turn;
    Player grid[9];
    bool checkWinner(unsigned short, unsigned short, unsigned short) const;
};

#endif // MODEL_H
