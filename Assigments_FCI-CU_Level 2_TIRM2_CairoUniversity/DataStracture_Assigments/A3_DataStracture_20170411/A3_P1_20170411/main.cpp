#include <iostream>

using namespace std;

template<class type>
class node
{
public:
    type data;
    node<type>* next;
    node(){next= nullptr;}
    node(const type& item, node<type>* ptr= nullptr)
    {
        data = item;
        next = ptr;
    }

};

template<class type>
class LinkedList
{
protected:
    node<type> * head;
    node<type> * tail;
public:
    LinkedList()
    {
        head = tail = new node<type>();
    }
    LinkedList(const LinkedList<type>&& other) = delete;
    LinkedList(LinkedList<type>&& other) = delete;
    ~LinkedList ()
    {
        while (head->next != nullptr)
        {
            node<type>* temp = head;
            head= head->next;
            delete temp;
        }
        delete head;
    }

    LinkedList<type>& operator= (const LinkedList<type>& other)= delete;
    LinkedList<type>& operator=(LinkedList<type>&& other)= delete;


    class iterator
    {
        friend class LinkedList;
        private:
            node<type>* nodeptr;
            iterator (node<type> * newptr)
            {
                nodeptr = newptr;
            }
        public:
        iterator()
        {
            nodeptr = nullptr;
        }

        iterator operator++(int)
        {
            iterator temp = *this;
            nodeptr = nodeptr->next;
            return temp;
        }

        /*void operator--(int)
        {
e            iterator temp = *this;
            nodeptr = nodeptr->next;
            return temp
        }
        */
        type& operator*() const
        {
            return nodeptr->next->data;
        }
        bool operator!=(const iterator& itr)const
        {
            return nodeptr != itr.nodeptr;
        }
        bool operator==(const iterator& itr)const
        {
            return nodeptr == itr.nodeptr;
        }
    };
    iterator insert(iterator position, const type& value)
    {
        node<type>* newNode = new node<type>(value, position.nodeptr->next);
        if(position.nodeptr == tail)
            tail = newNode;
        position.nodeptr->next = newNode;
        return position;
    }

    iterator erase(iterator position)
    {
        node<type> * toDelete = position.nodeptr->next;
        position.nodeptr->next = position.nodeptr->next->next;
        if(toDelete == tail)
            tail=position.nodeptr;
        delete toDelete;
        return position;
    }
    iterator begin()const
    {
        return iterator(head);
    }
    iterator end()const
    {
        return iterator(tail);
    }
    friend bool areIdentical(LinkedList& a, LinkedList& b)
    {
        while (a.head != a.tail && b.head != b.tail)
        {
            if (a.head->data != b.head->data)
                return false;

            a.head = a.head->next;
            b.head = b.head->next;
        }
        return true;
    }

};
int main()
{
    LinkedList<int> v1;
    auto iter = v1.begin();
    iter = v1.insert(iter,2);
    iter++;
    iter = v1.insert(iter,3);
    iter++;
    iter = v1.insert(iter,5);

    auto it = v1.end();
    it = v1.insert(it,9);
    v1.insert(v1.begin(),10);
    v1.insert(v1.end(),8);

    auto itr = v1.begin();
    itr++;
    v1.erase(itr);
    for (auto itr = v1.begin(); itr != v1.end(); itr++)
        cout<< *itr << " ";
    cout << endl;

    LinkedList<int> v;
    iter = v.begin();
    iter = v.insert(iter,2);
    iter++;
    iter = v.insert(iter,3);
    iter++;
    iter = v.insert(iter,5);

    it = v.end();
    it = v.insert(it,9);
    v.insert(v.begin(),10);
    v.insert(v.end(),8);

    itr = v.begin();
    itr++;
    v1.erase(itr);
    for (auto itr = v.begin(); itr != v.end(); itr++)
        cout<< *itr << " ";
    cout << endl;

    cout << areIdentical(v,v1) << endl;
    return 0;
}
