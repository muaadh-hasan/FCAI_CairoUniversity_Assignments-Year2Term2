#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;
class Fraction
{
private:
    int n , d;
    void reduce();
public:
    Fraction();
    Fraction(int,int);
    Fraction operator+(const Fraction &);
    Fraction operator-(const Fraction &);
    Fraction operator*(const Fraction &);
    Fraction operator/(const Fraction &);
    bool operator>(const Fraction &);
    bool operator>=(const Fraction &);
    bool operator<(const Fraction &);
    bool operator<=(const Fraction &);
    bool operator==(const Fraction &);
    friend ostream& operator<<(ostream& , const Fraction & );
    friend istream& operator>>(istream& ,  Fraction & );
};
#endif // FRACTION_H
