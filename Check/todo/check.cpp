#include "check.h"

Check::Check(QWidget *parent) : QWidget(parent),controller(new Controller(this)), list(new QListWidget()),tag(new QLineEdit())
{
    /** bisogna aggiungere il controller

    */

    //creo layouts
    QVBoxLayout* mainlayout= new QVBoxLayout();
    QVBoxLayout* menulayout= new QVBoxLayout();
    QHBoxLayout* secondlayout= new QHBoxLayout();
    QVBoxLayout* thirdlayout= new QVBoxLayout();
    QVBoxLayout* inslayout= new QVBoxLayout();
    //creo il menu
    QMenuBar* menubar= new QMenuBar();
    QMenu* menu= new QMenu("File",menubar);
    QAction* save=new QAction("Save",menu);
    QAction* exit=new QAction("Exit",menu);
    //assemblo il menu
    menubar->addMenu(menu);
    menu->addAction(save);
    menu->addAction(exit);
    menulayout->addWidget(menubar);
    //assemblo main layout
    mainlayout->addLayout(menulayout);
    mainlayout->addLayout(secondlayout);
    //assemblo i layouts
    secondlayout->addWidget(list);
    secondlayout->addLayout(thirdlayout);
    thirdlayout->addLayout(inslayout);
    //creo layout inserimento e bottoni
    QPushButton* addbutton= new QPushButton("aggiungi");
    QPushButton* removebutton=new QPushButton("rimuovi");
    inslayout->setSpacing(0);
    inslayout->addWidget(tag);
    inslayout->addWidget(addbutton);
    thirdlayout->addWidget(removebutton);
    //setto layout principale
    setLayout(mainlayout);
    /** connects
    */

    connect(addbutton,SIGNAL(clicked()),controller,SLOT(addItem()));
    connect(removebutton,SIGNAL(clicked()),controller,SLOT(removeItem()));
    connect(exit,SIGNAL(triggered()),this,SLOT(close()));
    connect(save,SIGNAL(triggered()),controller,SLOT(save()));

}


QString Check::getTag() const
{
    return tag->text();

}

QString Check::selectedItem() const
{
    if(!list->selectedItems().empty())
        return list->selectedItems().first()->text();
    else
        return "\0";
}

void Check::add() const
{
    list->addItem(tag->text());
}

void Check::remove() const
{
    qDeleteAll(list->selectedItems());
}

QString Check::savePath()
{
    return QFileDialog::getSaveFileName(this, "Salva il File", "",
                                                                            "File di Testo (*.txt)");

}

