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
    void erase(unsigned int =0);
    void clear();
    bool isEmpty() const;

    unsigned int getSpeedM() const;
    double getPesoM() const;
    unsigned int getSpeedT() const;
    double getPesoT() const;
    unsigned int numerotreni() const;
    void load(std::string);
    void save(std::string) const;
};

#endif // MODEL_H
