#ifndef TRAINLIST_H
#define TRAINLIST_H
#include <QListWidgetItem>
#include "../NievaTrains_P2/model/gerarchia/treno.h"
#include "Qontainer.h"

class TrainListWidget : public QListWidget {
    Q_OBJECT
public:
    TrainListWidget(QWidget * =nullptr);

    unsigned int getIndex() const;

    bool isSomeoneSelected() const;

    void unSelectIndex() const;
};
#endif // TRAINLIST_H
