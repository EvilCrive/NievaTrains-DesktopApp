#ifndef TRAINLIST_H
#define TRAINLIST_H
#include <QListWidgetItem>
#include <QListWidget>
#include "../../model/gerarchia/treno.h"

class TrainListWidgetItem : public QListWidgetItem
{
    Treno* t;
    QWidget* parent;
    unsigned int realIndex;

public:
    TrainListWidgetItem(Treno* t, unsigned int=0, QWidget * p=nullptr);
    unsigned int getRealIndex() const;
    Treno* getTreno() const;

};

class TrainListWidget : public QListWidget
{
    Q_OBJECT
public:
    TrainListWidget(QWidget * =nullptr);

    unsigned int getIndex() const;
    TrainListWidgetItem* getItem() const;
    Treno* getItemByIndex(unsigned int x) const;
    void addTrenoList(Treno* , unsigned int=0);
    void clear();
    void erase(unsigned int);
};

#endif // TRAINLIST_H
