#include "trainlist.h"

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

TrainListWidgetItem::TrainListWidgetItem(Treno* t, QWidget *p): QListWidgetItem(), t(t), parent(p){
    setText(QString::fromStdString(t->getNome()));
}
