#include <iostream>
#include <queue>
using namespace std;

class stack{

private:
    queue<int>queue1;
public:

void push(int x)
{
  queue1.push(x);
}

void pop()
{
    if (queue1.empty())
      return;
    else
    {

    for (int i=0; i<queue1.size()-1; i++)
    {
      queue1.push(queue1.front());
       queue1.pop();
    }

   queue1.pop();

    }

}

int top()
{
    for (int i=0; i<queue1.size()-1; i++)
    {
       queue1.push(queue1.front());
       queue1.pop();
    }

        int x = queue1.front();
        queue1.push(queue1.front());
       queue1.pop();
    return x ;
}
};
int main()
{
    stack stak1;
   stak1.push(6);
    stak1.push(8);
   stak1.push(3);
   stak1.pop();
    cout<<stak1.top();
   system("pause");
}