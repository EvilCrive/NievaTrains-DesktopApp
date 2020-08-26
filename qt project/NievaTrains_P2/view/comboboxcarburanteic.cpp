#include "comboboxcarburanteic.h"

ComboBoxCarburanteIC::ComboBoxCarburanteIC(QWidget * p): QComboBox(p)
{
    addItem("kerosene");
    addItem("petrol");
    addItem("diesel");
}
