#ifndef MENUBARTRAIN_H
#define MENUBARTRAIN_H


#include <qmenubar.h>

class MenuBarTrain : public QMenuBar
{  Q_OBJECT

    QMenu* file ;

    QAction* infoGenerali;
    QAction* serialize;
    QAction* unserialize;

public:
    MenuBarTrain(QWidget* = nullptr);

};

#endif // MENUBARTRAIN_H
