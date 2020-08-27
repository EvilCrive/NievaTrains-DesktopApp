#include "view/mainwindow.h"
#include <QApplication>
#include <iostream>
#include "model/model.h"

int main(int argc, char *argv[])
//int main()
{

    QApplication a(argc, argv);
    MainWindow w(new Model());
    w.show();
    a.exec();


    /*   QApplication a(argc, argv);
     *   MainWindow w;
     *   w.show();
     *   return a.exec();
     *   Model m;
     *   m.addtrain("alby","crive",12,"bridge","Regionale",0.4,"Wood");
     *   m.print_all();
     *   m.load("../data.xml");
     *
     *   Model m;
     *   m.load("E:/tutto/uni/p2/progetto/Progetto_P2/qt project/NievaTrains_P2/file risorse/data.json");
     *   m.load(":/file risorse/data.json");
     *   m.save("E:/tutto/xd.json");
     *   std::cout<<m.getPesoM();
     */
    /*Model m;
    m.load("E:/tutto/uni/p2/progetto/Progetto_P2/qt project/NievaTrains_P2/file risorse/prova.json");*/

}

