#include "controller.h"
#include "check.h"



Controller::Controller(Check * v, QObject *parent)
    :QObject(parent),model(new Modello()),view(v)
{

}

Controller::~Controller()
{
    if(model)   delete model;
}

void Controller::addItem() const
{

    QString elemento=view->getTag();
    if(elemento.trimmed().isEmpty())   return;
    model->aggiungi(elemento.QString::toStdString());
    view->add();
}

void Controller::removeItem() const
{
    QString selectedElement=view->selectedItem();
    if (!selectedElement.isEmpty()){
        model->togli(selectedElement.toStdString());
        view->remove();
    }
}

void Controller::save() const
{
    model->save(view->savePath().toStdString());
}

