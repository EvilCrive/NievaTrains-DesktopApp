#ifndef TRENO_H
#define TRENO_H
#include <string>
enum Trotaia {
    maglev, strap, plate, bridge, barlow, flat_bottomed, double_headed,
        bullhead
};
enum Ttreno {
    alta_velocita, inter_city, regionale, commuter
};


class Treno {
private:
    std::string nome;
    unsigned int id;
    std::string costruttore;
    unsigned int speed;
    Trotaia tipo_rotaia;
    Ttreno tipo_treno;

public:
    Treno();
    virtual ~Treno() = default;
   // virtual Treno* clone() const = 0;

    std::string getNome() const;
    unsigned int getId() const;
    std::string getCostruttore() const;
    unsigned int getSpeed() const;
    Trotaia getTipo_rotaia() const;
    Ttreno getTipo_treno() const;

    void setNome(std::string nome);
    void setId(unsigned int id);
    void setCostruttore(std::string costruttore);
    void setSpeed(unsigned int speed);
    void setTipo_rotaia(std::string tipo_rotaia);
    void setTipo_treno(std::string tipo_treno);

    virtual int calcolaCosto() const;
    float carburanteNecessario(unsigned int km) const;
    unsigned int kmPercorribili(unsigned int carburante) const;

    virtual void serialize();
    static Treno* unserialize();
};

#endif // TRENO_H
