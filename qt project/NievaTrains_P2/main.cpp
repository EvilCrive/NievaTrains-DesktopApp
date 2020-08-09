#include "view/mainwindow.h"

#include <QApplication>
#include <iostream>
#include "model/model.h"

//int main(int argc, char *argv[])
int main()
{
  /*  QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
    Model m;
    m.addtrain("alby","crive",12,"bridge","Regionale",0.4f,"Wood");
    m.print_all();
}
