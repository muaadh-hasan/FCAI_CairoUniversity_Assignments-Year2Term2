#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;


template <class T>
class queue
{
private:
    T * data;
    int max_size ,Size;
    int Front , rear;
public:
queue();
queue(T,int);
~queue();
void push(T);
void pop();
T& front();
int size();
bool empty();

};
#endif // QUEUE_H
