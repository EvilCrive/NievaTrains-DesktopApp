#include "todo.h"

ToDo::ToDo(string t)
    :text(t)
{

}

bool ToDo::operator==(const ToDo & t) const
{
    return text==t.text;
}

bool ToDo::operator!=(const ToDo & t) const
{
    return !(*this==t);
}

std::ostream& operator<<(std::ostream & os, const ToDo & t)
{
    return os<<t.text;
}
