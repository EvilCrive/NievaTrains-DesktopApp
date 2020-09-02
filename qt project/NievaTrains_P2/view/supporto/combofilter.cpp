#include "combofilter.h"

ComboFilter::ComboFilter(QWidget* p): QComboBox(p)
{
    addItem("Nome");
    addItem("Costruttore");
    addItem("Peso");
    addItem("Velocità");
    addItem("Motore IC");
    addItem("Potenza IC");
    addItem("Trasmissione Elettrico");
    addItem("Efficenza Elettrico");
    addItem("Temperatura Vapore");
    addItem("Carburante Vapore");
    addItem("Tecnologia Maglev");
    addItem("Motore primario Bimode");

}
