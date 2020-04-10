#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <iostream>

class Persona
{
private:
    std::string nome, anno_nascita, anno_morte;
public:
    Persona(std::string);
    Persona(std::string, std::string, std::string);
    std::string Nome() const;
    std::string AnnoNascita() const;
    std::string AnnoMorte() const;
};

std::ostream& operator<<(std::ostream&,const Persona&);

#endif // PERSONA_H
