#ifndef MODEL_H
#define MODEL_H

#include "Qontainer.h"
#include "model/gerarchia/bimode.h"
#include "model/gerarchia/maglev.h"
#include "model/gerarchia/steam.h"

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
    void addtrain(std::string nome, unsigned int speed, std::string EnumtipoRotaia, std::string EnumtipoTreno, float efficenza, std::string EnumtipoCarburanteSteam, std::string tipo ="Steam");
    void addtrain(std::string nome, unsigned int speed, std::string EnumtipoRotaia, std::string EnumtipoTreno, std::string tecnologia, std::string tipo ="Maglev");
    void addtrain(std::string nome, unsigned int speed, std::string EnumtipoRotaia, std::string EnumtipoTreno, std::string carburante, std::string trasmissione, float efficenza, std::string tipo ="Internal_Combustion");
    void addtrain(std::string nome, unsigned int speed, std::string EnumtipoRotaia, std::string EnumtipoTreno, std::string trasmissione, float efficenza, std::string tipo ="Electric");
    void addtrain(std::string nome, unsigned int speed, std::string EnumtipoRotaia, std::string EnumtipoTreno, std::string carburanteIC, std::string trasmissioneIC, float efficenzaIC, std::string trasmissioneElettrico, float efficenzaElettrico, std::string motorePrimario, std::string tipo ="Bimode");
    unsigned int numerotreni() const;

  //  unsigned int numeroproduttori()const;
  /*  float carburanteTreno(unsigned int)const;
    unsigned int kmPercorribili(unsigned int)const;*/

};

#endif // MODEL_H
