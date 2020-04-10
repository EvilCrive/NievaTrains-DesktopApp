#include "bolletta.h"


bolletta::bolletta():first(0){}

bool bolletta::Vuota() const
{
    return first==0;
}

void bolletta::Aggiungi_Telefonata(telefonata t)
{
    first=new nodo(t,first);
}

void bolletta::Togli_Telefonata(telefonata t)
{
    nodo* p=first;
    nodo* prec=0;
    while(p && !(p->info==t)){
        prec=p;
        p=p->next;
    }
    if(p){
        if(prec){
            prec->next=p->next;
        }else{
            first=p->next;
        }
    }
    delete p;
}

telefonata bolletta::Estrai_Una()
{
    nodo* aux=first;
    first=first->next;
    telefonata r=aux->info;
    delete aux;
    return r;
}

void bolletta::print() const
{
    nodo* p=first;
    int cont=1;
    while(p){
        std::cout<<"TELEFONATE IN BOLLETTA: \n"<<cont<<") "<<p->info;
        cont++;
        p=p->next;
    }
}

bolletta::nodo::nodo():next(0){}

bolletta::nodo::nodo(const telefonata & t, bolletta::nodo * s):info(t),next(s){}

std::ostream &operator<<(std::ostream & os, const bolletta & b)
{
    b.print();
}
