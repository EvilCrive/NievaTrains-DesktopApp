#include "comboboxtrasmissione.h"

ComboBoxTrasmissione::ComboBoxTrasmissione(QWidget *p): QComboBox(p)
{
    addItem("Overhead Line");
    addItem("Third Rail");
}
