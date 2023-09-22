#ifndef NIEVAEXCEPTION_H
#define NIEVAEXCEPTION_H

#include <QObject>

class NievaException : public QObject
{
    Q_OBJECT
public:
    explicit NievaException(std::string ="", QObject *parent = nullptr);
    void setMessage(std::string);
    std::string getMessage() const;
    std::string print() const;
private:
    QString message;
};

#endif // NIEVAEXCEPTION_H
