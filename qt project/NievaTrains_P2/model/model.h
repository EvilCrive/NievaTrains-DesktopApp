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


    //add train overloaded in base al tipo
    /*
    void addtrainSteam(std::string nome, std::string builder,unsigned int peso, unsigned int speed, double efficenza, std::string EnumtipoCarburanteSteam, std::string tipo ="Steam");
    void addtrainMaglev(std::string nome, std::string builder, unsigned int peso, unsigned int speed, std::string tecnologia, std::string tipo ="Maglev");
    void addtrainIC(std::string nome, std::string builder,unsigned int peso, unsigned int speed, std::string carburante, double efficenza, std::string tipo ="Internal_Combustion");
    void addtrainElectric(std::string nome, std::string builder,unsigned int peso, unsigned int speed, std::string trasmissione, double efficenza, std::string tipo ="Electric");
    void addtrainBimode(std::string nome, std::string builder,unsigned int peso, unsigned int speed, std::string carburanteIC, double efficenzaIC, std::string trasmissioneElettrico, double efficenzaElettrico, std::string motorePrimario, std::string tipo ="Bimode");
*/
    unsigned int numerotreni() const;
    void load(std::string);
    void save(std::string) const;
  //unsigned int numeroproduttori()const;
  //varie ricerche
  //calcolo costo

};

#endif // MODEL_H
