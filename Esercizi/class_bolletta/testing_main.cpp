#include "testing_main.h"
#include <iostream>
using std::cout;
using std::endl;
void testing_orario()
{
    orario a, b(10), c(9,10), d(12,40,20);
    cout<<"Testiamo se funzionano i metodi."<<endl;
    cout <<"1) ore() minuti() e secondi(): "<<d.Ore()<<" "<<d.Minuti()<< " " <<d.Secondi()<<endl<<"OK!"<<endl;
    cout <<"2) cout orario: \nmezzanotte  "<<a<<"\nle dieci  "<<b<<"\nle nove e dieci  "<<c<<"\nle dodici e quaranta e venti  "<<d<<endl;
    a.AvanzaUnOra();orario r=b.UnOraPiuTardi();
    cout<<"3) avanza un ora e unorapiutardi : \n"<<a<<"\n"<<r<<endl;
    cout<<"4) stampasecondi  ";
    d.StampaSecondi();
    cout<<"5) somma e differenza"<<"19e 10:-> "<<(b+c)<<"  0 e 50 ->"<<(b-c)<<endl;
    cout<<"6) == < e >  \n== "<<"a==orario()"<<(a==(orario().UnOraPiuTardi()))<<"   b==c  "<<(b==c)<<"\n";
    cout<<"< \na<b "<<(a<b)<<"  b<a "<<(b<a)<<"\n>  \na>b "<<(a>b)<<" b>a "<<(b>a)<<endl<<endl;
}

telefonata testing_telefonata(int alfa)
{
    telefonata prima;
    telefonata seconda(1,2,"014");
    telefonata terza(3,6,"41905");
    telefonata quarta(1,2,"12");
    telefonata quinta(3,6,"41905");
    if(alfa==1) return prima;
    if(alfa==2) return seconda;
    if(alfa==3) return terza;
    if(alfa==4) return quarta;
    if(alfa==5) return quinta;
    std::cout<<prima<<seconda<<terza<<quarta<<quinta<<std::endl;
    bool uno=terza==quinta;
    bool due=quarta==seconda;
    std::cout<<uno<<"\n"<<due<<"\n\n";
    return telefonata();
}

void testing_bolletta()
{

    bolletta aa;
    aa.Aggiungi_Telefonata(testing_telefonata(1));
    aa.Aggiungi_Telefonata(testing_telefonata(2));
    aa.Aggiungi_Telefonata(testing_telefonata(3));
    aa.Aggiungi_Telefonata(testing_telefonata(4));
    aa.Aggiungi_Telefonata(testing_telefonata(5));
    std::cout<<aa;
}
