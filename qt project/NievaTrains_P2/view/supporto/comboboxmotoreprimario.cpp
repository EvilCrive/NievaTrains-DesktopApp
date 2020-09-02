#include "comboboxmotoreprimario.h"

ComboBoxMotorePrimario::ComboBoxMotorePrimario(QWidget * p): QComboBox(p)
{
    addItem("Internal Combustion");
    addItem("Electric");

}
