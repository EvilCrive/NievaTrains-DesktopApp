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
    a.setWindowIcon(QIcon(":/risorse/favicon.ico"));
    a.exec();

}

