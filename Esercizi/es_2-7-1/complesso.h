#ifndef COMPLESSO_H
#define COMPLESSO_H


class Complesso
{
private:
    double re;
    double im;
public:
    void iniz_compl(double,double);
    double reale() const;
    double immag() const;
    Complesso operator+(const Complesso&) const;
    Complesso operator-(const Complesso&) const;
    bool operator==(const Complesso&) const;
    bool operator<(const Complesso&) const;
    bool operator>(const Complesso&) const;

};

#endif // COMPLESSO_H
