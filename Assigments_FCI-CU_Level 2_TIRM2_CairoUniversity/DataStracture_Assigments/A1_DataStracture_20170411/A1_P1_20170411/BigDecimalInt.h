#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <string>
#include <iostream>
using namespace std;


class BigDecimalInt
{
    public:
        BigDecimalInt();
        BigDecimalInt(string n);
        ~BigDecimalInt();
        BigDecimalInt& operator=(const BigDecimalInt& other);
        BigDecimalInt operator+( BigDecimalInt &rhs);
        BigDecimalInt operator-(BigDecimalInt &rhs);
        char Getsign() { return sign; }
        void Setsign(char val) { sign = val; }
        friend istream &operator>>( istream  &input, BigDecimalInt &b );
        friend ostream &operator<<( ostream &output, const BigDecimalInt &temp );
        int Size (){return num.size();}
		bool ok(const string &n);
    protected:
    private:
        string ten_complement(string& s,int n);
        int biggerMagnitude(const string &first, const string& second);
        string num;
        char sign;
};

#endif // BIGDECIMALINT_H