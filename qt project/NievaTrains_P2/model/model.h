#ifndef MODEL_H
#define MODEL_H

#include "Qontainer.h"
#include "model/gerarchia/bimode.h"
#include "model/gerarchia/maglev.h"
#include "model/gerarchia/steam.h"
#include <QJsonObject>
class Model
{
private:
    Qontainer<Treno*> list;
    Qontainer<Treno*> lista_ricerca;
public:
    Model()=default;
    ~Model()=default;

    void push_end(Treno*);
    void sostituisci(Treno* x, unsigned int y);
    void print(unsigned int =0) const;
    std::string treno2string(unsigned int =0) const;
    void print_all() const;
    Treno* operator[](unsigned int) const;
    Treno* getTreno(unsigned int) const;
    Treno* getTrenoDisplay(unsigned int) const;
    void erase(unsigned int =0);
    void clear();
    void equalizza();
    bool isEmpty() const;

    unsigned int getSpeedM() const;
    double getPesoM() const;
    unsigned int getSpeedT() const;
    double getPesoT() const;
    unsigned int numerotreni() const;
    void load(std::string);
    void save(std::string) const;

    //ricerca
    void searchNome(std::string);
    void searchCostruttore(std::string);
    void searchPeso(unsigned int,bool);
    void searchVelocita(unsigned int,bool);
    void searchCarburantevapore(std::string);
    void searchEfficenzavapore(double, bool);
    void searchEfficenzaelettrico(double,bool);
    void searchEfficenzaIC(double,bool);

    void searchTrasmissioneelettrico(std::string);
    void searchMotoreIC(std::string);
    void searchMotoreprimario(std::string);
    void searchTecnologiamaglev(std::string);

    void resetRicerca();

};

#endif // MODEL_H
