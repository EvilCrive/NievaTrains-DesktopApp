#ifndef TODO_H
#define TODO_H
#include <string>
using std::string;

class ToDo
{
    friend std::ostream& operator<<(std::ostream&, const ToDo&);
private:
    string text;
public:
    ToDo(string);

    bool operator==(const ToDo&)const;
    bool operator!=(const ToDo&)const;
};

std::ostream& operator<<(std::ostream&, const ToDo&);

#endif // TODO_H
