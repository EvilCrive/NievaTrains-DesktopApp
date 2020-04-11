#include "tictactoe.h"
#include "controller.h"

TicTacToe::TicTacToe(Controller* c, QWidget *parent)
    : QWidget(parent), controller(c)
{
    mainlayout= new QVBoxLayout(this);
    gridlayout= new QGridLayout(this);
    //aggiungere menu
    addMenu();
    //aggiungere celle(buttons)
    addButtons();
    setTicTacToeStyle();
    //aggiungere layouts
    mainlayout->addLayout(gridlayout);
    setLayout(mainlayout);
}

TicTacToe::~TicTacToe()
{

}

void TicTacToe::update(){

    for(unsigned short i=0U; i<9; i++){
        int p=controller->getPlayer(i/3,i%3);
        QLayoutItem* item=gridlayout->itemAtPosition(i/3,i%3);
        if(p != 0){
            QPushButton* button=static_cast<QPushButton*>(item->widget());
            if(p==1){
                button->setIcon(QIcon(":/resources/player1.png"));
            }
            if(p==2){
                button->setIcon(QIcon(":/resources/player2.png"));
            }
            button->setEnabled(false);
        }
    }
}

void TicTacToe::resetGrid(){
    for(unsigned short i=0U; i<9; i++){
        QLayoutItem* item=gridlayout->itemAtPosition(i/3,i%3);
        QPushButton* button=static_cast<QPushButton*>(item->widget());
        button->setIcon(QIcon());
        button->setEnabled(true);
    }
}

void TicTacToe::showWinner(){
    //! creare finestra messaggio (QDialog)
    QDialog* vincitore=new QDialog(this);
    QVBoxLayout* layoutW=new QVBoxLayout(vincitore);
    //! creare messaggio
    std::stringstream textW;
    int winner=controller->getWinner();
    if(winner)  textW<<"Il vincitore e' il player "<<winner;
    else    textW<<"Pareggio";
    //! inserire il messaggio nella finestra
    layoutW->addWidget(new QLabel(QString::fromStdString(textW.str()),vincitore));
    //! mostrare la finestra
    vincitore->show();
}

void TicTacToe::addButtons()
{
    //creare bottoni
    for(unsigned short i=0U; i<9; i++){
        TicTacToeButton* button=new TicTacToeButton(i/3,i%3,this);
        //connect(button,SIGNAL(clickedCell(unsigned short,unsigned short)),this,SLOT(cellHandler(unsigned short,unsigned short)));
        connect(button,SIGNAL(clickedCell(unsigned short, unsigned short)),controller,SLOT(move(unsigned short,unsigned short)));
        button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        gridlayout->addWidget(button,i/3,i%3);

       }
}

void TicTacToe::addMenu(){
    //Creare barra menu
    QMenuBar* menubar=new QMenuBar(this);
    //creare menu
    QMenu* menu=new QMenu("File",menubar);
    //azioni menu
    QAction* exit= new QAction("Exit",menu);
    QAction* reset= new QAction("Reset",menu);

    connect(reset,SIGNAL(triggered()),controller,SLOT(resetGame()));
    connect(exit,SIGNAL(triggered()),this,SLOT(close()));
    //aggiungi azioni e menubar al menu
    menu->addAction(reset);

    menu->addAction(exit);
    menubar->addMenu(menu);
    mainlayout->addWidget(menubar);


}

void TicTacToe::setTicTacToeStyle()
{
    gridlayout->setSpacing(0);
    setMinimumSize(QSize(400,400));
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QFile file(":/resources/style.css");
    file.open(QFile::ReadOnly);
    QString stylesheet= QLatin1String(file.readAll());
    setStyleSheet(stylesheet);

}

void TicTacToe::cellHandler(unsigned short x, unsigned short y) const
{
    QDialog* vincitore=new QDialog();
    QVBoxLayout* layoutW=new QVBoxLayout(vincitore);
    //! creare messaggio
    std::stringstream textW;
    textW<<"Hai cliccato la posizione :  "<< x<<" , "<<y;
    //! inserire il messaggio nella finestra
    layoutW->addWidget(new QLabel(QString::fromStdString(textW.str()),vincitore));
    //! mostrare la finestra
    vincitore->show();
}

