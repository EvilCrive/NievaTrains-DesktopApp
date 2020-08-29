#include "model/model.h"
#include <iostream>

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include "view/supporto/nievaexception.h"


using std::cout;
using std::string;


void Model::print(unsigned int i) const
{
    int numero=i+1;
    cout<<"TRENO "<<numero<<": \n";
    list[i]->print();
    cout<<"\n\n\n";
}
std::string Model::treno2string(unsigned int i) const{
    int numero=i+1;
    std::string s="TRENO "+ std::to_string(numero)+": \n";
    s.append(list[i]->treno2string());
    s.append("\n\n\n");
    return s;
}
void Model::print_all() const
{
    for(unsigned int i=0; i<list.getSize();i++) print(i);
}
Treno *Model::operator[](unsigned int i) const
{
    if(i<list.getSize())    return list[i];
    else    return 0;
}
Treno* Model::getTreno(unsigned int i) const{
    return (*this)[i];
}
void Model::erase(unsigned int i)
{
    list.pop(i);
    lista_ricerca=list;
}
void Model::clear()
{
    while(list.getSize()>0) erase(0);
    lista_ricerca=list;
}

bool Model::isEmpty() const
{
    if(list.getSize()==0)   return 1;
    else    return 0;
}

 unsigned int  Model::getSpeedM() const
{
     unsigned int count=0;
     unsigned int i=0;
     for(;i< list.getSize(); i++){
       count+=list[i]->getSpeed();
     }
     if(!count)  return 0;
     else    return count/i;
}

double Model::getPesoM() const
{
    double count=0;
    unsigned int i=0;
    for(;i< list.getSize(); i++){
        count+=list[i]->getPeso();
    }

    if(!count)  return 0;
    else    return count/i;
}
double Model::getPesoT() const
{
    double toRet=0;
    unsigned int i=0;
    for(;i< list.getSize(); i++){
        if(toRet<list[i]->getPeso()) toRet=list[i]->getPeso();
    }
    return toRet;
}
unsigned int Model::getSpeedT() const
{
    double toRet=0;
    unsigned int i=0;
    for(;i< list.getSize(); i++){
        if(toRet<list[i]->getSpeed()) toRet=list[i]->getSpeed();
    }
    return toRet;
}
void Model::sostituisci(Treno* x, unsigned int y){
    if(x) list.switchItem(&x,y);lista_ricerca=list;
}
unsigned int Model::numerotreni() const
{
    int count=0;
    for(unsigned int i=0; i<list.getSize();i++){
        count++;
    }
    return count;
}
void Model::push_end(Treno *t)
{
    if(t)   list.push(&t);
    if(!(lista_ricerca==list))  lista_ricerca=list;
}

void Model::resetRicerca()
{
    if(!(lista_ricerca==list))  lista_ricerca=list;
}

void Model::searchNome(std::string n)
{
    for(auto it=lista_ricerca.cbegin();it!=lista_ricerca.cend(); ++it){
        if(n!=(*it)->getNome()){
            lista_ricerca.erase(*it);
            --it;
        }
    }
}
void Model::searchCostruttore(std::string n)
{
    for(auto it=lista_ricerca.cbegin();it!=lista_ricerca.cend(); ++it){
        if(n!=(*it)->getCostruttore()){
            lista_ricerca.erase(*it);
            --it;
        }
    }
}
void Model::searchMotoreIC(std::string n){
    for(auto it=lista_ricerca.cbegin();it!=lista_ricerca.cend(); ++it){
        Internal_Combustion* t=dynamic_cast<Internal_Combustion*>(*it);
        if(t){
            if(n!=t->getMotoreIC()){
                lista_ricerca.erase(*it);
                --it;
            }
        }
    }
}
void Model::searchCarburantevapore(std::string n){
    for(auto it=lista_ricerca.cbegin();it!=lista_ricerca.cend(); ++it){
        if((*it)->type()=="Steam"){
            Steam* t=static_cast<Steam*>(*it);
            if(n!=t->getCarburanteSteam()){
                lista_ricerca.erase(*it);
                --it;
            }
        }
    }
}

void Model::searchPeso(unsigned int n, bool b){
    for(auto it=lista_ricerca.cbegin();it!=lista_ricerca.cend(); ++it){
        if(b && (*it)->getPeso()<n){
            //maggiore
            lista_ricerca.erase(*it);
            --it;
        }else if(!b && (*it)->getPeso()>=n){
            //minore
            lista_ricerca.erase(*it);
            --it;
        }
    }
}
void Model::searchVelocita(unsigned int n, bool b){
    for(auto it=lista_ricerca.cbegin();it!=lista_ricerca.cend(); ++it){
        if(b && (*it)->getSpeed()<n){
            //maggiore
            lista_ricerca.erase(*it);
            --it;
        }else if(!b && (*it)->getSpeed()>=n){
            //minore
            lista_ricerca.erase(*it);
            --it;
        }
    }
}


void Model::searchEfficenzavapore(double n, bool b){
    for(auto it=lista_ricerca.cbegin();it!=lista_ricerca.cend(); ++it){
        if((*it)->type()=="Steam"){
            Steam* t=static_cast<Steam*>(*it);
            if(b && n<t->getEfficenzaSteam()){
                lista_ricerca.erase(*it);
                --it;
            }else if(b && n>=t->getEfficenzaSteam()){
                lista_ricerca.erase(*it);
                --it;
            }
        }
    }
}
void Model::searchEfficenzaelettrico(double n, bool b){
    for(auto it=lista_ricerca.cbegin();it!=lista_ricerca.cend(); ++it){
        Electric* t=dynamic_cast<Electric*>(*it);
        if(t){
            if(b && n<t->getEfficenzaElettrico()){
                lista_ricerca.erase(*it);
                --it;
            }else if(!b && n>=t->getEfficenzaElettrico()){
                lista_ricerca.erase(*it);
                --it;
            }
        }
    }
}
void Model::searchEfficenzaIC(double n, bool b){
    for(auto it=lista_ricerca.cbegin();it!=lista_ricerca.cend(); ++it){
        Internal_Combustion* t=dynamic_cast<Internal_Combustion*>(*it);
        if(t){
            if(b && n<t->getEfficenzaIC()){
                lista_ricerca.erase(*it);
                --it;
            }else if(b && n>=t->getEfficenzaIC()){
                lista_ricerca.erase(*it);
                --it;
            }
        }
    }
}
void Model::searchTrasmissioneelettrico(std::string n){
    for(auto it=lista_ricerca.cbegin();it!=lista_ricerca.cend(); ++it){
        Electric* t=dynamic_cast<Electric*>(*it);
        if(t){
            bool  test;
            if(n=="third rail") test=true;
            else if(n=="overhead lines")    test=false;
            //eccezione ?
            else    return;
            if(test!=t->getTrasmissioneElettrico()){
                lista_ricerca.erase(*it);
                --it;
            }
        }
    }
}
void Model::searchMotoreprimario(std::string n){
    for(auto it=lista_ricerca.cbegin();it!=lista_ricerca.cend(); ++it){
        Bimode* t=dynamic_cast<Bimode*>(*it);
        if(t){
            bool test;
            if(n=="ic") test=true;
            else if(n=="electric")    test=false;
            //eccezione ?
            else    return;
            if(test!=t->getMotorePrimario()){
                lista_ricerca.erase(*it);
                --it;
            }
        }
    }
}
void Model::searchTecnologiamaglev(std::string n){
    for(auto it=lista_ricerca.cbegin();it!=lista_ricerca.cend(); ++it){
        if((*it)->type()=="Maglev"){
            Maglev* t=static_cast<Maglev*>(*it);
            bool test;
            if(n=="eds") test=true;
            else if(n=="ems")    test=false;
            //eccezione ?
            else return;
            if(test!=t->getTecnologia()){
                lista_ricerca.erase(*it);
                --it;
            }
        }
    }
}

// INPUT OUTPUT JSON
//lista eccezioni
void Model::load(std::string path) try{
    std::string errors="";

    QFile loadFile(QString::fromStdString(path));
    if(!loadFile.open(QIODevice::ReadOnly)){
        //ecccezione
        throw new NievaException("Errore Caricamento Documento JSON");
    }
    QByteArray savedata=loadFile.readAll();
    loadFile.close();
    QJsonDocument doc(QJsonDocument::fromJson(savedata));
    //eccezione
    if(!doc.isArray())  throw new NievaException("Errore Sintassi Documento JSON:\n\tIl documento JSON deve essere un array di piu' oggetti (unico array JSON)");
    QJsonArray array(doc.array());
    clear();
    int count=0;
    for(auto it=array.begin(); it!=array.end();it++){
        try {
            QJsonObject object;
            if(it->isObject())  object=it->toObject();
            else    throw new NievaException("Errore Sintassi Documento JSON:\n\tIl documento JSON deve essere un array di piu' oggetti (errore nel trovare oggetto)");
            if(object.contains("type")){
                Treno* treno=nullptr;
                //eccezione :da unserialize
                try {
                    treno=treno->unserialize(object);
                } catch (NievaException* e) {
                    count++;
                    if(errors=="")  errors+=e->getMessage();
                    else    errors+="\n"+e->getMessage();
                }
                if(treno)   push_end(treno);
            }else{
                //eccezione
                throw new NievaException("Errore Sintassi Documento JSON:\n\tIl documento JSON deve contenere la variabile type");
            }
        } catch (NievaException* e) {
            if(errors=="")  errors+=e->getMessage();
            else    errors+="\n"+e->getMessage();
        }
    }
    //eccezione
    if(errors!=""){
        if(errors.find("Errore Sintassi Documento JSON")!=string::npos)   errors+="\nIl file non e' stato caricato";
        else    errors+="\n\n"+std::to_string(count)+" treni non sono stati caricati";
        throw new NievaException(errors);
    }

}catch(NievaException* e){
    //rithrowo le eccezioni al chiamante(controller)
    throw e;
}

//lista eccezioni
void Model::save(std::string path) const try{
    QFile saveFile(QString::fromStdString(path));
    if(!saveFile.open(QIODevice::WriteOnly)){
        //eccezione
        throw new NievaException("Errore Salvataggio Documento JSON");
    }
    QJsonArray array;
    for(unsigned int i=0; i<numerotreni();i++){
        QJsonObject obj;
        list[i]->serialize(obj);
        QJsonValue nodo(obj);
        array.push_back(nodo);
    }
    QJsonDocument doc(array);
    saveFile.write(doc.toJson());
    saveFile.close();
}
catch(NievaException* e){
    throw e;
}



