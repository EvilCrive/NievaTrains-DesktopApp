#include "combotype.h"

ComboType::ComboType(QWidget* parent):
    QComboBox (parent)
{
    addItem("Tipo");
    addItem("Bimode");
    addItem("Elettrico");
    addItem("Internal Combustion");
    addItem("Maglev");
    addItem("Vapore");
}
