#include "menubartrain.h"

MenuBarTrain::MenuBarTrain(QWidget* p):
    parent(p),
    file(new QMenu("File", this)),
    infoGenerali(new QAction("Info Generali",this)),
    serialize(new QAction("Esporta",file)),
    unserialize(new QAction("Importa",file)),
    autori(new QAction("Autori",this))
{
    file->addAction(serialize);
    file->addAction(unserialize);
    addMenu(file);
    addAction(infoGenerali);
    addAction(autori);

    connect(infoGenerali,SIGNAL(triggered()),parent,SLOT(slotShowInfoGenerali()));
    connect(serialize,SIGNAL(triggered()),parent,SLOT(slotSalva()));
    connect(unserialize,SIGNAL(triggered()),parent,SLOT(slotCarica()));
    connect(autori,SIGNAL(triggered()),parent,SLOT(slotAutori()));
}
