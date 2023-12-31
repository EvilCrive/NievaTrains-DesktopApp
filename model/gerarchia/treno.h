#ifndef TRENO_H
#define TRENO_H
#include <string>
#include <QJsonObject>

class Treno {
private:
    std::string nome;
    std::string costruttore;
    unsigned int speed;
    unsigned int peso;
public:
    Treno(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100, unsigned int p=100);
    virtual ~Treno() = default;

    std::string getNome() const;
    std::string getCostruttore() const;
    unsigned int getSpeed() const;
    unsigned int getPeso() const;

    void setNome(std::string);
    void setCostruttore(std::string);
    void setSpeed(unsigned int);
    void setPeso(unsigned int);

    virtual std::string type() const;
    virtual void print()const;
    virtual std::string treno2string()const;
    virtual void serialize(QJsonObject&)=0;
    static Treno* unserialize(QJsonObject&);

    virtual double carburanteNecessario(unsigned int) const =0;
    virtual unsigned int kmPercorribili(unsigned int) const =0;
};


#endif // TRENO_H
