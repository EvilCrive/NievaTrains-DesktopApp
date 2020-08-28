#ifndef MAGLEV_H
#define MAGLEV_H
#include "model/gerarchia/treno.h"

class Maglev: public Treno {
private:
    bool tecnologia;
public:
    Maglev(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100,  unsigned int p=100, bool=false);

    bool getTecnologia() const;

    void setTecnologia(bool);

    std::string type() const;
    void print() const;
    std::string treno2string() const;
    virtual void serialize(QJsonObject&);
};

#endif // MAGLEV_H
