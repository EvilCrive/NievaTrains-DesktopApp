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

/**
 * @brief print stampa alcuni dati appartenenti al treno in posizione i (usata per debugging)
 * @param i= index nel contenitore
 */
void Model::print(unsigned int i) const
{
    cout<<"Dati "<<": \n";
    list[i]->print();
    cout<<"\n\n\n";
}
/**
 * @brief treno2string rappresenta le informazioni del treno in posizione i tramite una stringa
 * @param i= index nel contenitore
 * @return stringa contenente la rappresentazione del treno in questo formato
 */
std::string Model::treno2string(unsigned int i) const{
    int numero=i+1;
    std::string s="TRENO "+ std::to_string(numero)+": \n";
    if(list[i])
         s.append(list[i]->treno2string());
    s.append("\n\n\n");
    return s;
}
/**
 * @brief utilizza print per stampare alcune informazioni di tutti i treni all'interno del contenitore
 */
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
/**
 * @brief erase elimina il treno in posizione i
 * @param i= index nel contenitore
 */
void Model::erase(unsigned int i)
{
    list.pop(i);
}
/**
 * @brief clear elimina tutti i treni dal contenitore
 */
void Model::clear()
{
    while(list.getSize()>0) erase(0);
}
/**
 * @brief isEmpty verifica se il contenitore è vuoto o meno
 * @return booleano
 */
bool Model::isEmpty() const
{
    if(list.getSize()==0)   return 1;
    else    return 0;
}
/**
  * @brief getSpeedM calcola la velocità massima media tra tutti i treni nel contenitore
  * @return intero rappresentante la velocità massima media tra tutti i treni
  */
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
 /**
   * @brief getPesoM calcola il peso medio tra tutti i treni nel contenitore
   * @return intero rappresentante il peso medio tra tutti i treni
   */
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
/**
 * @brief getPesoT cerca il peso più alto tra i treni del contenitore
 * @return double rappresentante il peso più alto
 */
double Model::getPesoT() const
{
    double toRet=0;
    unsigned int i=0;
    for(;i< list.getSize(); i++){
        if(toRet<list[i]->getPeso()) toRet=list[i]->getPeso();
    }
    return toRet;
}
/**
 * @brief getSpeedT cerca la velocità massima più alta tra i treni del contenitore
 * @return intero rappresentante la velocità massima più alta
 */
unsigned int Model::getSpeedT() const
{
    double toRet=0;
    unsigned int i=0;
    for(;i< list.getSize(); i++){
        if(toRet<list[i]->getSpeed()) toRet=list[i]->getSpeed();
    }
    return toRet;
}
/**
 * @brief sostituisce il treno in posizione y con un nuovo treno
 * @param x= treno da sostituire al posto di quello presente nel contenitore
 * @param y= indice del treno da eliminare
 */
void Model::sostituisci(Treno* x, unsigned int y){
    if(x) list.switchItem(&x,y);

}
/**
 * @brief numerotreni ritorna la quantità di treni nel contenitore
 * @return
 */
unsigned int Model::numerotreni() const
{
    return list.getSize();
}
/**
 * @brief push_end aggiunge un treno in coda al contenitore
 * @param t= treno da aggiungere
 */
void Model::push_end(Treno *t)
{
    if(t)   list.push(&t);
}

// INPUT OUTPUT JSON
/**
 * @brief load carica da un file json rappresentante dei treni, gli stessi treni nel contenitore svuotando il contenuto precedente
 * @param path= percorso in cui si trova il file json
 */
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
/**
 * @brief save salva i treni del contenitore in un file esterno in formato json
 * @param path= percorso in cui salvare il file
 */
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



