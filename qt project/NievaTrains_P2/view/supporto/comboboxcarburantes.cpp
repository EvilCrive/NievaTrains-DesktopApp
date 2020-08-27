#include "comboboxcarburantes.h"

ComboBoxCarburanteS::ComboBoxCarburanteS(QWidget *p): QComboBox(p)
{
    addItem("Coal");
    addItem("Wood");
    addItem("Oil");

}
