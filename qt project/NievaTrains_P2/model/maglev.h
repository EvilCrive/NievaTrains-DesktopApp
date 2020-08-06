#ifndef MAGLEV_H
#define MAGLEV_H
#include "treno.h"

enum Ttech {
  eds, ems
};

class Maglev: public Treno {
private:
    Ttech tecnologia;
public:
    Maglev();
    virtual ~Maglev() = default;
    virtual Maglev* clone() const = 0;

    Ttech getTecnologia() const;

    void setTecnologia(std::string tecnologia);
};

#endif // MAGLEV_H
