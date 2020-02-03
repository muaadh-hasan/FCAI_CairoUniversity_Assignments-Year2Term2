#include <iostream>
#include "queue.h"
#include "queue.cpp"
using namespace std;

int main()
{
    queue<int>q;
    queue<int>q2(1,2);
    q.push(5);
    q.push(3);
    q.push(8);
    cout<<"Size = " << q.size()<<endl;
    while(!q.empty())
    {
    cout<<q.front()<< "  ";
    q.pop();
    }
    cout<<endl;
    cout<<"Size = " << q2.size()<<endl;
    while(!q2.empty())
    {
    cout<<q2.front()<< "  ";
    q2.pop();
    }
	system("pause");
}