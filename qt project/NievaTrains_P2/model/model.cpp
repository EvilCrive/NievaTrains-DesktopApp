#include "model/model.h"
#include <iostream>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
using std::cout;
using std::string;


void Model::print(unsigned int i) const
{
    int numero=i+1;
    cout<<"TRENO "<<numero<<": \n";
    list[i]->print();
    cout<<"\n\n\n";
}
void Model::print_all() const
{
    for(unsigned int i=0; i<list.getSize();i++) print(i);
}
Treno *Model::operator[](unsigned int i) const
{
    return list[i];
}
Treno* Model::getTreno(unsigned int i) const{
    return list[i];
}
void Model::erase(unsigned int i)
{
    list.pop(i);
}
void Model::clear()
{
    for(unsigned int i=0; i<list.getSize();i++) erase(0);
    erase(0);
}

 unsigned int  Model::getSpeedM() const
{
     unsigned int count=0;
     unsigned int i=0;
     for(;i< list.getSize(); i++){
       count+=list[i]->getSpeed();
     }


     return count/i; /*cast implicito a unsigned int*/
}

double Model::getPesoM() const
{
    double count=0;
    unsigned int i=0;
    for(;i< list.getSize(); i++){
        count+=list[i]->getPeso();
    }

    return count/i;
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
        if(toRet<list[i]->getSpeed()) toRet=list[i]->getPeso();
    }
    return toRet;
}
void Model::addtrain(std::string nome, std::string builder, unsigned int speed, std::string EnumtipoRotaia, std::string EnumtipoTreno, double efficenza, std::string EnumtipoCarburanteSteam, std::string tipo)
{
    if(tipo=="Steam"){
        //creazione oggetto treno_Steam di default
        Treno* t=new Steam();
        //set dei vari campi dati tramite setters
        t->setNome(nome);t->setSpeed(speed);t->setCostruttore(builder);t->setTipo_rotaia(EnumtipoRotaia);t->setTipo_treno(EnumtipoTreno);
        static_cast<Steam*>(t)->setEfficenzaSteam(efficenza);static_cast<Steam*>(t)->setCarburanteSteam(EnumtipoCarburanteSteam);
        //push in coda al contenitore
        push_end(t);
    }
}
void Model::addtrain(std::string nome, std::string builder, unsigned int speed, std::string EnumtipoRotaia, std::string EnumtipoTreno, std::string tecnologia, std::string tipo)
{
    if(tipo=="Maglev"){
        //creazione oggetto treno_Maglev di default
        Treno* t=new Maglev();
        //set dei vari campi dati tramite setters
        t->setNome(nome);t->setSpeed(speed);t->setCostruttore(builder);t->setTipo_rotaia(EnumtipoRotaia);t->setTipo_treno(EnumtipoTreno);
        static_cast<Maglev*>(t)->setTecnologia(tecnologia);
        //push in coda al contenitore
        push_end(t);
    }
}
void Model::addtrain(std::string nome, std::string builder, unsigned int speed, std::string EnumtipoRotaia, std::string EnumtipoTreno, std::string carburante, std::string trasmissione, double efficenza, std::string tipo)
{
    if(tipo=="Internal_Combustion"){
        //creazione oggetto treno_Interrnal_Combustion di default
        Treno* t= new Internal_Combustion();
        //set campi dati
        t->setNome(nome);t->setSpeed(speed);t->setCostruttore(builder);t->setTipo_rotaia(EnumtipoRotaia);t->setTipo_treno(EnumtipoTreno);
        dynamic_cast<Internal_Combustion*>(t)->setCarburanteIC(carburante); dynamic_cast<Internal_Combustion*>(t)->setTrasmissioneIC(trasmissione); dynamic_cast<Internal_Combustion*>(t)->setEfficenzaIC(efficenza);
        //push nel contenitore
        push_end(t);
    }
}
void Model::addtrain(std::string nome, std::string builder, unsigned int speed, std::string EnumtipoRotaia, std::string EnumtipoTreno, std::string trasmissione, double efficenza, std::string tipo)
{
    if(tipo=="Electric"){
        //creazione oggetto treno_Electric di default
        Treno* t= new Electric();
        //set campi dati
        t->setNome(nome);t->setSpeed(speed);t->setCostruttore(builder);t->setTipo_rotaia(EnumtipoRotaia);t->setTipo_treno(EnumtipoTreno);
        dynamic_cast<Electric*>(t)->setTrasmissioneElettrico(trasmissione);dynamic_cast<Electric*>(t)->setEfficenzaElettrico(efficenza);
        //push nel contenitore
        push_end(t);
    }
}
void Model::addtrain(std::string nome, std::string builder, unsigned int speed, std::string EnumtipoRotaia, std::string EnumtipoTreno, std::string carburanteIC, std::string trasmissioneIC, double efficenzaIC, std::string trasmissioneElettrico, double efficenzaElettrico, std::string motorePrimario, std::string tipo)
{
    if(tipo=="Bimode"){
        //creazione oggetto treno_Bimode di default
        Treno* t= new Bimode();
        //set campi dati
        t->setNome(nome);t->setSpeed(speed);t->setCostruttore(builder);t->setTipo_rotaia(EnumtipoRotaia);t->setTipo_treno(EnumtipoTreno);
        dynamic_cast<Bimode*>(t)->setCarburanteIC(carburanteIC);dynamic_cast<Bimode*>(t)->setTrasmissioneIC(trasmissioneIC);dynamic_cast<Bimode*>(t)->setEfficenzaIC(efficenzaIC);
        dynamic_cast<Bimode*>(t)->setTrasmissioneElettrico(trasmissioneElettrico);dynamic_cast<Bimode*>(t)->setEfficenzaElettrico(efficenzaElettrico);dynamic_cast<Bimode*>(t)->setMotorePrimario(motorePrimario);
        //push nel contenitore
        push_end(t);
    }
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
    list.push(&t);
}

// INPUT OUTPUT JSON


void Model::load(std::string path)
{
    QFile loadFile(QString::fromStdString(path));
    if(!loadFile.open(QIODevice::ReadOnly)){
        std::cout<<"no";
        //ecccezione
    }
    QByteArray savedata=loadFile.readAll();
    loadFile.close();

    QJsonDocument doc(QJsonDocument::fromJson(savedata));
    QJsonArray array(doc.array());
    clear();
    for(auto it=array.begin(); it!=array.end();it++){
        QJsonObject object=it->toObject();
        if(object.contains("type") && object["type"].isString()){
            Treno* treno=treno->unserialize(object);
            //eccezione
            push_end(treno);
        }
    //eccezione
    }
}
void Model::save(std::string path) const
{
    QFile saveFile(QString::fromStdString(path));
    if(!saveFile.open(QIODevice::WriteOnly)){
        std::cout<<"no";
        //eccezione
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

