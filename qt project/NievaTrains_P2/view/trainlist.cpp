#include "trainlist.h"
#include <iostream>
TrainListWidget::TrainListWidget(QWidget *parent):QListWidget (parent){}

unsigned int TrainListWidget::getIndex() const
{
    return (unsigned int)this->selectedIndexes()[0].row();
}
void TrainListWidget::unSelectIndex() const
{
    this->selectedIndexes().clear();
}
void TrainListWidget::addTrenoList(Treno* treno){
    TrainListWidgetItem* item= new TrainListWidgetItem(treno);

    addItem(item);
}

void TrainListWidget::clear()
{
    for(int i=0; i<count(); )   delete takeItem(0);

}

TrainListWidgetItem::TrainListWidgetItem(Treno* t, QWidget *p): QListWidgetItem(), t(t), parent(p){
    setText(QString::fromStdString(t->getNome()));
}
