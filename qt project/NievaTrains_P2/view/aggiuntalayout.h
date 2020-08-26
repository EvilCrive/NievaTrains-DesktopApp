#ifndef AGGIUNTALAYOUT_H
#define AGGIUNTALAYOUT_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QStringList>
#include <QPushButton>

class AggiuntaLayout: public QWidget
{
    Q_OBJECT

    QLabel *lab1,*lab2,*lab3,*lab4,*lab5,*lab6,*lab7,*lab8,*lab9,*lab10,*lab11,*lab12,*lab13;
    QLineEdit *nome, *costruttore, *efficenzaS, *efficenzaE, *speed, *peso;
    QComboBox *rotaia,*tipo, *carburante,*carburanteIC,*trasmissioneIC,*tecnologia,*primario;
    QPushButton *conferma, *annulla;

public:
    AggiuntaLayout(unsigned int x=0);
};

#endif // AGGIUNTALAYOUT_H
