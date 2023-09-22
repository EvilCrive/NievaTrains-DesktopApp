#include "nievaexception.h"

NievaException::NievaException(std::string m, QObject *parent):  QObject(parent), message(QString::fromStdString(m))
{}

void NievaException::setMessage(std::string m)
{
    message=QString::fromStdString(m);
}

std::string NievaException::getMessage() const
{
    return message.toStdString();
}

std::string NievaException::print() const
{
    return "- Eccezione:: \n\t"+message.toStdString()+"\n";
}
