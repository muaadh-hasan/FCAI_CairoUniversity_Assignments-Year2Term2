#include "Fraction.h"

Fraction::Fraction()
 {
    n = 0;
    d = 1;
 }
Fraction::Fraction(int n,int d)
{
    this->n = n;
    this->d = d;
}
Fraction Fraction::operator+(const Fraction & F)
{
    Fraction res;
    res.n = (n * F.d) + (d* F.n);
    res.d = d * F.d;
    res.reduce();
    return res;
}
Fraction Fraction::operator-(const Fraction & F)
{
    Fraction res;
    res.n = (n * F.d) - (d* F.n);
    res.d = d * F.d;
    res.reduce();
    return res;
}
Fraction Fraction::operator*(const Fraction & F)
{
    Fraction res;
    res.n = n * F.n;
    res.d = d * F.d;
    res.reduce();
    return res;
}
Fraction Fraction::operator/(const Fraction & F)
{
    Fraction res;
    res.n = n * F.d;
    res.d = d * F.n;
    res.reduce();
    return res;
}
bool Fraction::operator>(const Fraction & F)
{
    return( (n * F.d) > (d * F.n) );
}
bool Fraction::operator>=(const Fraction & F)
{
     return( (n * F.d) >= (d * F.n) );
}
bool Fraction::operator<(const Fraction & F)
{
     return( (n * F.d) < (d * F.n) );
}
bool Fraction::operator<=(const Fraction & F)
{
     return( (n * F.d) <= (d * F.n) );
}
bool Fraction::operator==(const Fraction & F)
{
     return( (n * F.d) == (d * F.n) );
}
ostream& operator<<(ostream& out , const Fraction & F)
{
    if (F.d == 1)
    {
        out << F.n << endl;
    }
    else{
        out << F.n << " / " << F.d;
    }
    return out;
}
istream& operator>>(istream& in,  Fraction & F)
{
    char ch;
    in >> F.n >> ch  >> F.d;
    return in;
}
void Fraction::reduce()
{
    int x = n , y = d ;

    while (x != y)
    {
        if ( x > y)
        {
            x -= y;
        }
        else{
            y-=x;
        }
    }

    n /= x;
    d /= x;
}
