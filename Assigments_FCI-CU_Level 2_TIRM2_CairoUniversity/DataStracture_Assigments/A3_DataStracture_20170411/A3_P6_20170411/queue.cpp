#include "queue.h"

template <class T>
queue<T>::queue()
{
    max_size = 100;
    data = new T [max_size];
     Size = 0 ;
     Front = 0;
     rear = -1;

}

template <class T>
queue<T>::queue(T d , int x)
{
    max_size = 100 - x;
    data = new T [max_size];
     Size = 0 ;
     Front = 0;
     rear = -1;

    for(int i=0 ; i<x ; i++)
    {
        push(d);
    }

}


template <class T>
queue<T>::~queue()
{
    delete [] data ;
}

template <class T>
void queue<T>::push(T x)
{
        if(Size>=max_size-1)
        {
            return;
        }
        else{
            rear  = (rear+1) % max_size ;
            data[rear] = x;
            Size++;
        }
}

template <class T>
void queue<T>::pop()
{
    if(Size == 0)
        return ;
    else
    {
        Front = (Front+1) % max_size;
        Size--;
    }
}


template <class T>
T& queue<T>::front()
{
    if(Size!=0)
    {
        return data[Front];
    }
}

template <class T>
bool queue<T>::empty()
{
    return (Size==0);
}

template <class T>
int queue<T>::size()
{
    return Size;
}
