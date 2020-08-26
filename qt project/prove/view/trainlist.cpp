#include "trainlist.h"

TrainListWidget::TrainListWidget(QWidget *parent):QListWidget (parent){}

unsigned int TrainListWidget::getIndex() const
{
    return (unsigned int)this->selectedIndexes()[0].row();
}

bool TrainListWidget::isSomeoneSelected() const
{
    return !this->selectedIndexes().empty();
}

void TrainListWidget::unSelectIndex() const
{
    this->selectedIndexes().clear();
}
