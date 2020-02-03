#include <iostream>
#include "stack.h"
#include "stack.cpp"
using namespace std;

int main()
{

    stack<int> A;
    cout << "Enter size of stack:" << endl;
    int Size,input;
    cin >> Size;
    cout << "enter the inputs: " << endl;
    for (int i=0;i<Size;i++){
    cin >> input;
    A.push(input);
    }

    cout << "stack 2:{";
    while(!A.empty())
    {
    cout <<"|" << A.top()<<"|";
    A.pop();
    }
    cout << "}" <<endl;

    stack<int> X(7,3);

    cout<<"stack 1:{";
    while(!X.empty())
    {
    cout<<"|"<< X.top()<<"|";
    X.pop();
    }
    cout << "}" << endl;
    return 0;
}

