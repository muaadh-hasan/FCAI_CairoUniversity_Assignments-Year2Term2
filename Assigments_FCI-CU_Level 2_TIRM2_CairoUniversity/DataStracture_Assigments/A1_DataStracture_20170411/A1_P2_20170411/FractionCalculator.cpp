#include "FractionCalculator.h"

void FractionCalculator::add()
{
    Fraction res;
    res = F1 + F2;
    cout << res;
}
void FractionCalculator::subtract()
{
    Fraction res;
    res = F1 - F2;
    cout << res;
}
void FractionCalculator::multiply()
{
    Fraction res;
    res = F1 * F2;
    cout << res;
}
void FractionCalculator::divide()
{
    Fraction res;
    res = F1 / F2;
    cout << res;
}
void FractionCalculator::input()
{
   char op;
   cout << " Enter First Fraction " << endl;
   cin >> F1;

   cout << " Enter operator " << endl;
   cin >> op;

   cout << " Enter Second Fraction " << endl;
   cin >> F2;

   if ( op == '+')
   {
     add();
   }

   else if ( op == '-')
   {
     subtract();
   }

   else if ( op == '*')
   {
     multiply();
   }

   else if ( op == '/')
   {
     divide();
   }


}
