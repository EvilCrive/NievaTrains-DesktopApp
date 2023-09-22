#include "trainlist.h"
#include <iostream>
TrainListWidget::TrainListWidget(QWidget *parent):QListWidget (parent){
    connect(this,SIGNAL(itemSelectionChanged()),parent->parent(),SLOT(slotShowTreno()));
}
/**
 * @brief getIndex ritorna l'indice della lista selezionato al momento
 * @return int rappresentante l'indice della lista
 */
unsigned int TrainListWidget::getIndex() const {
    return currentRow();
}
/**
 * @brief getItem l'item della lista selezionato al momento
 * @return item della lista
 */
TrainListWidgetItem* TrainListWidget::getItem() const {
    TrainListWidgetItem* item=static_cast<TrainListWidgetItem*>(currentItem());
    return item;
}
/**
 * @brief getItem seleziona il treno estratto dall'item della lista in posizione indicata dal parametro
 * @param x= indice della lista
 * @return campo treno dell'item in posizione x
 */
Treno* TrainListWidget::getItemByIndex(unsigned int x) const
{
    TrainListWidgetItem* it=static_cast<TrainListWidgetItem*>(item(x));
    return it->getTreno();
}
/**
 * @brief addTrenoList aggiunge un nuovo item alla lista
 * @param treno= treno da aggiungere
 * @param x= posizione reale nel suo contenitore del treno
 */
void TrainListWidget::addTrenoList(Treno* treno, unsigned int x){
    TrainListWidgetItem* item= new TrainListWidgetItem(treno, x);
    addItem(item);
}
/**
 * @brief clear svuota la lista
 */
void TrainListWidget::clear()
{
    for(int i=0; i<count(); ){
         delete takeItem(0);;
    }
}
/**
 * @brief erase elimina l'item in posizione x
 * @param x= indice della lista
 */
void TrainListWidget::erase(unsigned int x)
{
    delete takeItem(x);
}

TrainListWidgetItem::TrainListWidgetItem(Treno* t,unsigned int index, QWidget *p ): QListWidgetItem(), t(t), parent(p), realIndex(index){
    setText(QString::fromStdString(t->getNome()));
}
/**
 * @brief getRealIndex ritorna la posizione originale del treno rispetto a tutti gli altri senza considerare i filtri
 * @return intero rappresentante la posizione del treno
 */
unsigned int TrainListWidgetItem::getRealIndex() const{
    return realIndex;
}
Treno* TrainListWidgetItem::getTreno() const{
    return t;
}
