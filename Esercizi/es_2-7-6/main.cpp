#include <iostream>
#include "persona.h"
using std::cout;
using std::endl;

int main()
{
    Persona Aldo("Aldo","1970","1990");
    Persona Alby("Alby");
    cout << Aldo <<endl<< Alby << endl << endl;
    return 0;
}

/*
 *  Persona(std::string);
    Persona(std::string, std::string, std::string);
    std::string Nome() const;
    std::string AnnoNascita() const;
    std::string AnnoMorte() const;
};

std::ostream& operator<<(std::ostream&,const Persona&);
*/
