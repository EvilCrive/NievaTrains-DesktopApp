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
    void print(unsigned int =0) const;
    void print_all() const;
    Treno* operator[](unsigned int) const;
    void erase(unsigned int =0);
    void clear();

    //add train overloaded in base al tipo
    void addtrain(std::string nome, std::string builder, unsigned int speed, std::string EnumtipoRotaia, std::string EnumtipoTreno, double efficenza, std::string EnumtipoCarburanteSteam, std::string tipo ="Steam");
    void addtrain(std::string nome, std::string builder, unsigned int speed, std::string EnumtipoRotaia, std::string EnumtipoTreno, std::string tecnologia, std::string tipo ="Maglev");
    void addtrain(std::string nome, std::string builder, unsigned int speed, std::string EnumtipoRotaia, std::string EnumtipoTreno, std::string carburante, std::string trasmissione, double efficenza, std::string tipo ="Internal_Combustion");
    void addtrain(std::string nome, std::string builder, unsigned int speed, std::string EnumtipoRotaia, std::string EnumtipoTreno, std::string trasmissione, double efficenza, std::string tipo ="Electric");
    void addtrain(std::string nome, std::string builder, unsigned int speed, std::string EnumtipoRotaia, std::string EnumtipoTreno, std::string carburanteIC, std::string trasmissioneIC, double efficenzaIC, std::string trasmissioneElettrico, double efficenzaElettrico, std::string motorePrimario, std::string tipo ="Bimode");
    unsigned int numerotreni() const;
    void load(std::string);
    void save(std::string);
  //unsigned int numeroproduttori()const;
  //varie ricerche
  //calcolo costo

};

#endif // MODEL_H
