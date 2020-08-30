#include "trainlist.h"
#include <iostream>
TrainListWidget::TrainListWidget(QWidget *parent):QListWidget (parent){
    connect(this,SIGNAL(itemSelectionChanged()),parent->parent(),SLOT(slotShowTreno()));
}

unsigned int TrainListWidget::getIndex() const
{
    return currentRow();
}
TrainListWidgetItem* TrainListWidget::getItem() const
{
    TrainListWidgetItem* item=static_cast<TrainListWidgetItem*>(currentItem());
    return item;
}
Treno* TrainListWidget::getItemByIndex(unsigned int x) const
{
    TrainListWidgetItem* it=static_cast<TrainListWidgetItem*>(item(x));
    std::cout<<"gettando treni"<<std::endl;
    return it->getTreno();
}
bool TrainListWidget::isSelected() const
{
    return !this->selectedIndexes().empty();
}

void TrainListWidget::addTrenoList(Treno* treno, unsigned int x){
    TrainListWidgetItem* item= new TrainListWidgetItem(treno, x);
    addItem(item);
}

void TrainListWidget::clear()
{
    for(int i=0; i<count(); ){
        //delete takeItem(0);
        erase(0);
    }
}

void TrainListWidget::erase(unsigned int x)
{
    std::cout<<"popped"<<std::endl;
    delete takeItem(x);
}


TrainListWidgetItem::TrainListWidgetItem(Treno* t,unsigned int index, QWidget *p ): QListWidgetItem(), t(t), parent(p), realIndex(index){
    setText(QString::fromStdString(t->getNome()));
}
unsigned int TrainListWidgetItem::getRealIndex() const{
    return realIndex;
}
Treno* TrainListWidgetItem::getTreno() const{
    t->print();
    return t;
}
