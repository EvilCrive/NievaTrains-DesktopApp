#include "trainlist.h"
#include <iostream>
TrainListWidget::TrainListWidget(QWidget *parent):QListWidget (parent){
    connect(this,SIGNAL(itemSelectionChanged()),parent->parent(),SLOT(slotShowTreno()));
}

unsigned int TrainListWidget::getIndex() const
{
    return currentRow();
}
bool TrainListWidget::isSelected() const
{
    return !this->selectedIndexes().empty();
}

void TrainListWidget::addTrenoList(Treno* treno){
    TrainListWidgetItem* item= new TrainListWidgetItem(treno);
    addItem(item);
}

void TrainListWidget::clear()
{
    for(int i=0; i<count(); ){
        delete takeItem(0);
    }
}

void TrainListWidget::erase(unsigned int x)
{
    delete takeItem(x);
}

TrainListWidgetItem::TrainListWidgetItem(Treno* t, QWidget *p): QListWidgetItem(), t(t), parent(p){
    setText(QString::fromStdString(t->getNome()));
}
