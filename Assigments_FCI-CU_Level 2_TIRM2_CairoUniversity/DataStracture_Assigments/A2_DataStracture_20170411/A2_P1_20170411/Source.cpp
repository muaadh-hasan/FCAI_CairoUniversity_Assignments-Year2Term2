#include "Book.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;



int main(){
	Book b;
	int ch;
	int n;
	string t;
	while (n=true){
		cout << "\n Enter your choese : \n 1.Add Book \n 2.Search book by name \n 3.Search book by author \n 4.List books \n 5.Update available number of versions of a book \n put '0' to exit. \n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			{
				b.AddBook();
				break;
			}
		case 2:
			{
				cout << "Enter the name : " <<endl;
				cin>>t;
				b.Search_Book_byName(t);
				break;
			}
		case 3:
			{
				cout << "Enter the name : " <<endl;
				cin>>t;
				b.Search_Book_byAuthor(t);
				break;
			}
		case 4:
			{
				b.List_Books();
				break;
			}
		case 5:
			{
				cout << "Enter the name : " <<endl;
				cin>>t;
				b.Update_NumOfAvalibalVer(t);
				break;
			}
		case 0:
			{
				n = false;
				break;
			}

		default:
			{
				cout << "\nEnter form 1 to 5 or 0 to exit .. ^^ " << endl;
				break;
			}
		}
	}
	system("pause");
} 