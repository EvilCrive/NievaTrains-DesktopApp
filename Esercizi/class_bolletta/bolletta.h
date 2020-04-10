#ifndef BOLLETTA_H
#define BOLLETTA_H
#include "telefonata.h"

class bolletta
{
public:
    bolletta();
    bool Vuota() const;
    void Aggiungi_Telefonata(telefonata);
    void Togli_Telefonata(telefonata);
    telefonata Estrai_Una();
    void print() const;
private:
    class nodo{
    public:
        telefonata info;
        nodo*next;
        nodo();
        nodo(const telefonata&, nodo*);
    };
    nodo* first;

};

std::ostream& operator<<(ostream&, const bolletta&);
#endif // BOLLETTA_H
