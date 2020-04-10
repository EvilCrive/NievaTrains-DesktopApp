#include <iostream>
#include "complesso.h"
#include "orario.h"
using namespace std;

int main()
{

/*! MAIN per Class COMPLESSO
    Complesso a, b, c, d;
    a.iniz_compl(1,2);
    b.iniz_compl(3,6);
    c.iniz_compl(4,4);
    d.iniz_compl(4,3);
    cout<<"Testiamo se funzionano i metodi."<<endl;
    cout <<"1) void_iniz() reale() e immag(): "<<a.reale()<<" "<<a.immag()<< " " << endl<<"OK!"<<endl;
    Complesso somma1=a+b;
    Complesso somma2=c+d;
    cout <<"2) somma: "<<somma1.reale()<<" "<<somma1.immag()<<"; "<<somma2.reale()<<" "<<somma2.immag()<<" \nOK!\n";
    Complesso differenza1=c-b;
    Complesso differenza2=d-a;
    cout <<"3) differenza: "<<differenza1.reale()<<" "<<differenza1.immag()<<"; "<<differenza2.reale()<<" "<<differenza2.immag()<<" \nOK!\n";
    Complesso uguaglianza=b-a-a;
    cout <<"4) uguaglianza: "<<"(1,2)==(1,2) "<<(uguaglianza==a)<<"; (1,2)==(3,6) "<<(a==b) <<" \nOK!\n";
    cout <<"5) minore: "<<"(1,2)<(3,6)S "<<(a<b)<<"; (3,6)<(1,2)N "<<(b<a)<<"; (4,4)<(4,3)N "<<(c<d)<<"; (4,3)<(4,4)S "<<(d<c)<<" \nOK!\n";
    cout <<"6) maggiore: "<<"(1,2)>(3,6)N "<<(a>b)<<"; (3,6)>(1,2)S "<<(b>a)<<"; (4,4)>(4,3)S "<<(c>d)<<"; (4,3)>(4,4)N "<<(d>c)<<" \nOK!\n";
*/
// separatore omegalul
/*! MAIN per Class Orario
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
    cout<<"< \na<b "<<(a<b)<<"  b<a "<<(b<a)<<"\n>  \na>b "<<(a>b)<<" b>a "<<(b>a)<<endl;


*/

    return 0;
}
