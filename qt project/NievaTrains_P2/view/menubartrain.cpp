#include "menubartrain.h"

MenuBarTrain::MenuBarTrain(QWidget* p):
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
}
