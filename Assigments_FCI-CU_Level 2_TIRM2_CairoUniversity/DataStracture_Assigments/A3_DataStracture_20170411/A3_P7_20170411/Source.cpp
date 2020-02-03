#include <iostream>
#include<string>
using namespace std;

struct node {
   string data;
   int priority;
   node *next;
};

class priorityQueue
{
 private:
    node *front;
 public:
    priorityQueue()
    {
        front = NULL;
    }

    void enqueue(string value, int priority)
    {
      node *n = new node , *temp, *temp2;
      n->data = value;
      n->priority = priority;

       if (front == NULL) {
          front = n;
          n->next = NULL;
       }
       else if (priority > front->priority)
       {
          n->next = front;
          front = n;
       }
       else
        {
          temp = front;
          temp2 = NULL;
          while (temp != NULL && temp->priority >= priority)
          {
          temp2 = temp;
          temp=temp->next;
          }
          temp2->next = n;
          n->next = temp;
        }
     }
     string dequeue() {
           node *temp;
           string s = "";

           if(front == NULL)
           cout<<"Empty Priority Queue\n";

           else {
              s = front -> data;
              temp = front;
              front = front->next;
              delete temp;
           }
           return s;
        }
};


int main() {
      priorityQueue PQ;
      PQ.enqueue("World",10);
      PQ.enqueue("Hello",5);
      cout << PQ.dequeue() << "  " << PQ.dequeue() << endl;

	  system("pause");
}
