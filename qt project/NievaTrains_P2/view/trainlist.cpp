#include "trainlist.h"

TrainListWidget::TrainListWidget(QWidget *parent):QListWidget (parent){
    connect(this,SIGNAL(itemSelectionChanged()),parent->parent(),SLOT(slotShowTreno()));
}

unsigned int TrainListWidget::getIndex() const
{
    return (unsigned int)this->selectedIndexes()[0].row();
}
bool TrainListWidget::isSelected() const
{
    return !this->selectedIndexes().empty();
}

void TrainListWidget::addTrenoList(Treno* treno){
    TrainListWidgetItem* item= new TrainListWidgetItem(treno);

    addItem(item);
}

TrainListWidgetItem::TrainListWidgetItem(Treno* t, QWidget *p): QListWidgetItem(), t(t), parent(p){
    setText(QString::fromStdString(t->getNome()));
}
