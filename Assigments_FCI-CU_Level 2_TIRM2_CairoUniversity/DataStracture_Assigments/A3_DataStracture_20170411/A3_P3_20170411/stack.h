#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;


template <class T>
class stack
{
private:
    T * ArrOfData;
    int SIZE;
    int Top;
public:
stack();
stack(T,int);
~stack();
void push(T);
void pop();
T& top();
int size();
bool empty();

};
#endif
