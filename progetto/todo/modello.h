#ifndef MODELLO_H
#define MODELLO_H

#include "todo.h"
#include <list>
#include <fstream>
using std::list;

class Modello
{
private:
    list<ToDo*> lista;

public:
    Modello();
    ~Modello();
    void aggiungi(string);
    void togli(string);
    void save(string);

};

#endif // MODELLO_H
