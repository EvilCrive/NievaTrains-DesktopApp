#include "complesso.h"

void Complesso::iniz_compl(double r, double i)
{
    re=r;
    im=i;
}

Complesso Complesso::operator+(const Complesso& c) const
{
    Complesso r;
    r.iniz_compl(re+c.re,im+c.im);
    return r;
}

Complesso Complesso::operator-(const Complesso& c) const
{
    Complesso r;
    r.iniz_compl(re-c.re,im-c.im);
    return r;
}

bool Complesso::operator==(const Complesso& c) const
{
    return (re==c.re)&&(im==c.im);
}

bool Complesso::operator<(const Complesso& c) const
{
    return (re<c.re) || ((re==c.re)&&(im<c.im));
}

bool Complesso::operator>(const Complesso& c) const
{
    return (re>c.re) || ((re==c.re)&&(im>c.im));
}

double Complesso::reale() const
{
    return re;
}

double Complesso::immag() const
{
    return im;
}
