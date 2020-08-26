#ifndef TRAINLIST_H
#define TRAINLIST_H
#include <QListWidgetItem>
#include <QListWidget>
#include "../NievaTrains_P2/model/gerarchia/treno.h"
#include "Qontainer.h"

class TrainListWidget : public QListWidget
{
    Q_OBJECT
public:
    TrainListWidget(QWidget * =nullptr);

    unsigned int getIndex() const;
    void unSelectIndex() const;
    void addTrenoList(Treno* );
    void clear();
};

class TrainListWidgetItem : public QListWidgetItem
{
    Treno* t;
    QWidget* parent;

public:
    TrainListWidgetItem(Treno* t, QWidget * p=nullptr);

};
#endif // TRAINLIST_H
