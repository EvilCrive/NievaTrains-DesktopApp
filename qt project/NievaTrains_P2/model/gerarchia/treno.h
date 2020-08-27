#ifndef TRENO_H
#define TRENO_H
#include <string>
#include <QJsonObject>

class Treno {
protected:
   // enum Trotaia {maglev, strap, plate, bridge, barlow, flat_bottomed, double_headed,bullhead};
   // enum Ttreno {alta_velocita, inter_city, regionale, commuter};
private:
    std::string nome;
    std::string costruttore;
    unsigned int speed;
    unsigned int peso;
   // Trotaia tipo_rotaia; //togliere
  //  Ttreno tipo_treno; //togliere
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
    void setTipo_rotaia(std::string);
    void setTipo_treno(std::string);

    virtual std::string type() const;
    virtual void print()const;
    virtual std::string print2()const;
 // virtual int calcolaCosto() const;
    virtual void serialize(QJsonObject&)=0;
    static Treno* unserialize(QJsonObject&);
 // virtual Treno* clone() const = 0;
};


#endif // TRENO_H
