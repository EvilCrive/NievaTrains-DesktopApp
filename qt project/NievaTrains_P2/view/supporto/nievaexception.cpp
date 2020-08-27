#include "nievaexception.h"

NievaException::NievaException(QString m, QObject *parent) : message(m), QObject(parent)
{

}

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
