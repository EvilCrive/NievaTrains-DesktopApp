#ifndef INFOLAYOUT_H
#define INFOLAYOUT_H
#include <QWidget>
#include <QDialog>
#include <QLabel>

class InfoLayout: public QDialog
{
    Q_OBJECT

    QLabel* tot;
    QLabel* PesoM;
    QLabel* VelM;
    QLabel* PesoT;
    QLabel* VelT;
public:
    InfoLayout(QWidget * =nullptr, unsigned int tot=0, unsigned int varVelT=0, unsigned int varPesoT=0, double varVelM=0, double varPesoM=0);
};

#endif // INFOLAYOUT_H
