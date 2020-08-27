#include "comboboxtrasmissione.h"

ComboBoxTrasmissione::ComboBoxTrasmissione(QWidget *p): QComboBox(p)
{
    addItem("overhead lines");
    addItem("third rail");
}
