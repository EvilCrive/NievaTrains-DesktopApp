#include "modello.h"

Modello::Modello()
{

}

Modello::~Modello()
{
    for(auto it=lista.begin(); it!=lista.end(); it++){
        delete *it;
    }
}

void Modello::aggiungi(std::string s)
{
    lista.push_back(new ToDo(s));
}

void Modello::togli(std::string s)
{
    auto it=lista.begin();
    while(it!=lista.end()){
        if(**it==ToDo(s)){
            delete *it;
            lista.erase(it);
            it=lista.end();
        }
        it++;
    }
}

void Modello::save(std::string path)
{
    std::ofstream file;
    file.open(path);
    for(auto it=lista.begin();it!=lista.end();it++){
        file<<**it<<std::endl;
    }
    file.close();

}
