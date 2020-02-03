#include <iostream>
#include <list>
using namespace std;
void merge (list<int> l1 , list<int> l2)
{

    list<int>::iterator it1 = l1.begin();
    list<int>::iterator it2 = l2.begin();

    while (it1!=l1.end() && it2!=l2.end())
    {
        if(*it1 > *it2)
        {
            l1.insert(it1,*it2);
            it1++;
            it2++;
        }

        else if (*it1 < *it2)
        {

        it1++;
        }
        else{
            it2++;
        }
    }

    while (it2!=l2.end())
    {
        l1.push_back(*it2);
        it2++;
    }

  for (it1=l1.begin(); it1!=l1.end(); it1++)
    cout <<*it1 <<" ";

}
int main()
{
    list<int> l1 ;
    list<int> l2 ;

    l1.push_back(3);
    l1.push_back(5);
	l1.push_back(5);

    l1.push_back(17);
    l1.push_back(30);



    l2.push_back(1);
	l2.push_back(1);

    l2.push_back(5);
    l2.push_back(70);

    merge(l1,l2);


	system("pause");
    return 0;
}
