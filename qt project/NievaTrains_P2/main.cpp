#include "view/mainwindow.h"

#include <QApplication>
#include "model/gerarchia/bimode.h"
#include <iostream>
#include <vector>
#include "model/gerarchia/steam.h"
#include "model/model.h"

//int main(int argc, char *argv[])
int main()
{
  /*  QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/

    /*Qontainer<Bimode> prova;
    Bimode a;
    prova.push(&a);
    std::cout<<prova[0].getSpeed();*/

    Model m;
    Bimode primo;
    Electric secondo;
    m.push_end(&primo);
    m.push_end(&secondo);
    m.print();
}
