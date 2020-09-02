#include "comboboxtrasmissione.h"

ComboBoxTrasmissione::ComboBoxTrasmissione(QWidget *p): QComboBox(p)
{
    addItem("Overhead Lines");
    addItem("Third Rail");
}
