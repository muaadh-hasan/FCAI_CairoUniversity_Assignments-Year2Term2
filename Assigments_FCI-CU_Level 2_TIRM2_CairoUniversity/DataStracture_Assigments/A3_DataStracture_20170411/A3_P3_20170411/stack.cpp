#include "stack.h"

template <class T>
stack<T>::stack()
{
    SIZE = 100;
    ArrOfData = new T[SIZE];
    Top = -1;

}

template <class T>
stack<T>::stack(T d , int x)
{
    SIZE = 100- x;
    ArrOfData = new T [SIZE];
    Top = -1;

    for(int i=0 ; i<x ; i++)
    {
        push(d);
    }

}

template <class T>
stack<T>::~stack()
{
    delete [] ArrOfData ;
}

template <class T>
T& stack<T>::top()
{
    if(Top != -1)
    {
        return ArrOfData[Top];
    }
}

template <class T>
void stack<T>::push(T x)
{
        if(Top>=SIZE-1){
            return;
        }
        else{
            Top ++ ;
            ArrOfData[Top] = x;
        }
}

template <class T>
void stack<T>::pop()
{
    if(Top == -1)
        return ;

    else{
        Top--;
    }
}




template <class T>
bool stack<T>::empty()
{
    return (Top==-1);
}
