#include "infolayout.h"
#include <QString>
#include <QVBoxLayout>
InfoLayout::InfoLayout(QWidget* p, QString str1, QString str2, QString str3, QString str4, QString str5): QDialog(p),
    first(new QLabel(this)),
    second(new QLabel(this)),
    third(new QLabel(this)),
    fourth(new QLabel(this)),
    fifth(new QLabel(this)),
    img(new QPixmap(":/risorse/InfoGenerali.jpg"))
{
    first->setText(str1);
    second->setText(str2);
    third->setText(str3);
    fourth->setText(str4);
    fifth->setText(str5);

    QVBoxLayout* ilayout(new QVBoxLayout(this));
    setWindowTitle("Informazioni Generali");

    QLabel* image = new QLabel(this);

    *img=(img->scaled(300,250));
    image->setPixmap(*img);
    ilayout->addWidget(image);
    ilayout->addWidget(first);
    ilayout->addWidget(second);
    ilayout->addWidget(third);
    ilayout->addWidget(fourth);
    ilayout->addWidget(fifth);

    image->resize(300,250);

    setLayout(ilayout);

    resize(350,500);
}

void InfoLayout::setMargin(int margin)
{
    first->setMargin(margin);
    second->setMargin(margin);
    third->setMargin(margin);
    fourth->setMargin(margin);
    fifth->setMargin(margin);
}



