#include "comboboxmotoreprimario.h"

ComboBoxMotorePrimario::ComboBoxMotorePrimario(QWidget * p): QComboBox(p)
{
    addItem("Electric");
    addItem("Internal Combustion");
}
