#include "combotype.h"

ComboType::ComboType(QWidget* p): QComboBox (p)
{
    addItem("Vapore");
    addItem("Elettrico");
    addItem("Internal Combustion");
    addItem("Maglev");
    addItem("Bimode");

}
