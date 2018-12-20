#include <iostream>
using namespace std;

class Persona{
private:
  string Nome;
  int AnnoNascita;
  int AnnoMorte;
public:
  Persona();
  Persona(string, int, int);
  string getNome() const;
  int getAnnodinascita() const;
  int getAnnodimorte() const;
  
};


ostream& operator<< (ostream& os,const Persona &p){
  return os<<"Si chiamava: "<<p.getNome()<<", nato nel "<<p.getAnnodinascita()<<" e morto nel "<<p.getAnnodimorte()<<endl;
}


Persona::Persona(): Nome("Eusebio"), AnnoNascita(1847), AnnoMorte(2000) {}

Persona::Persona(std::string N, int Nato, int Morto): Nome(N), AnnoNascita(Nato), AnnoMorte(Morto) {}

std::string Persona::getNome()const{
  return Nome;
}

int Persona::getAnnodinascita()const{
  return AnnoNascita;
}

int Persona::getAnnodimorte()const{
  return AnnoMorte;
}

int main(){
  cout<<"Dammi un nome"<<endl;
  string N1;
  int An1,Am1;
  getline(cin,N1);
  cout<<"Adesso dammi il suo anno di nascita e il suo anno di morte"<<endl;
  cin>>An1>>Am1;
  Persona defa;
  Persona definita(N1,An1,Am1);
  cout<<"La persona di default e'"<<defa<<endl;
  cout<<"La persona definita da te e'"<<definita<<endl;
  cout<<"Premi un tasto per finire..."<<endl;
  int a;
  cin>>a;
  cout<<"FINE"<<endl;
  
}
