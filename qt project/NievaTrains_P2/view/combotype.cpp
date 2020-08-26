#include "combotype.h"

ComboType::ComboType(QWidget* parent):
    QComboBox (parent)
{
    addItem("Vapore");
    addItem("Bimode");
    addItem("Elettrico");
    addItem("Internal Combustion");
    addItem("Maglev");

}
