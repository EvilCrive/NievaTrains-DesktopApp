#include "combofilter.h"

ComboFilter::ComboFilter(QWidget* p): QComboBox(p)
{
    addItem("Nome");
    addItem("Costruttore");
    addItem("Peso");
    addItem("Velocità");
    addItem("Motore IC");
    addItem("Efficenza IC");
    addItem("Trasmissione Elettrico");
    addItem("Efficenza Electric");
    addItem("Efficenza Vapore");
    addItem("Carburante Vapore");
    addItem("Tecnologia Maglev");
    addItem("Motore primario Bimode");

}
