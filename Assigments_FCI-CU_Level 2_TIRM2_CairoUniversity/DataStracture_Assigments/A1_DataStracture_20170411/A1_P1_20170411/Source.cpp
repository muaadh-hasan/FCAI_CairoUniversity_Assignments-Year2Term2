#include <iostream>
#include "BigDecimalInt.h"
using namespace std;

istream &operator>>( istream  &input, BigDecimalInt &b );
ostream &operator<<( ostream &output, const BigDecimalInt &temp );


int main()
{
    BigDecimalInt x,y,z;
    for(int i=0;i<5;i++)
    {
        cout<<"Enter two numbers x and y: ";
        cin>>x>>y;
        z=x+y;
        cout<<"x + y = "<<z<<endl;
        z=x-y;
        cout<<"x - y = "<<z<<endl;
    }
    //return 0;
	system("pause");
}



istream &operator>>( istream  &input, BigDecimalInt &b )
{
    string n,temp;
    input>>n;
    while(!b.ok(n))
    {
        cout<<"Invalid input, Enter a valid num: ";
        cin>>n;
    }
    if(n[0]=='-')
    {
        b.sign='-';
        temp=n.substr(1);
    }
    else
    {
        b.sign='+';
        temp=n;
    }
    if(temp.find_first_not_of('0')==string::npos)
        {
            b.sign='+';
            b.num="0";
        }
    else
        b.num=temp.substr(temp.find_first_not_of('0'));
    return input;

}
ostream &operator<<( ostream &output, const BigDecimalInt &temp )
{
    if (temp.sign=='-')
        output<<temp.sign;
    output<<temp.num;
    return output;
}