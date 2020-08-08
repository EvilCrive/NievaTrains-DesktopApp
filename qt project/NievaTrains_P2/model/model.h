#ifndef MODEL_H
#define MODEL_H

#include "model/Qontainer.h"
#include "model/gerarchia/bimode.h"

class Model
{
private:
    Qontainer<Treno*> list;
public:
    Model()=default;
    ~Model()=default;

//    void print_all()const;
    void push_end(Treno*);
    void print(unsigned int =0) const;
    void print_all() const;
    /*Treno* operator[](unsigned int) const;
    void erase(unsigned int);
    void clear();

    void addrandomtrain(std::string);
    unsigned int numerotreni() const;
    unsigned int numeroproduttori()const;
    float carburanteTreno(unsigned int)const;
    unsigned int kmPercorribili(unsigned int)const;*/

};

#endif // MODEL_H
