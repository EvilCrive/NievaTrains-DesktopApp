#ifndef TRENO_H
#define TRENO_H
#include <string>
#include <QJsonObject>

class Treno {
protected:
    enum Trotaia {maglev, strap, plate, bridge, barlow, flat_bottomed, double_headed,bullhead};
    enum Ttreno {alta_velocita, inter_city, regionale, commuter};
private:
    std::string nome;
    std::string costruttore;
    unsigned int speed;
    Trotaia tipo_rotaia;
    Ttreno tipo_treno;
public:
    Treno(const std::string& = "NoName", const std::string& ="NoBuilder", unsigned int =100, Trotaia =Trotaia::maglev, Ttreno =Ttreno::alta_velocita );
    virtual ~Treno() = default;

    std::string getNome() const;
    std::string getCostruttore() const;
    unsigned int getSpeed() const;
    std::string getTipo_rotaia() const;
    std::string getTipo_treno() const;

    void setNome(std::string);
    void setCostruttore(std::string);
    void setSpeed(unsigned int);
    void setTipo_rotaia(std::string);
    void setTipo_treno(std::string);

    virtual std::string type() const;
    virtual double carburanteNecessario(unsigned int) const =0; //km in input
    virtual unsigned int kmPercorribili(unsigned int) const =0; //carburante in input
    virtual void print()const;
 // virtual int calcolaCosto() const;
    virtual void serialize(QJsonObject&)=0;
    static Treno* unserialize(QJsonObject&);
 // virtual Treno* clone() const = 0;
};


#endif // TRENO_H
