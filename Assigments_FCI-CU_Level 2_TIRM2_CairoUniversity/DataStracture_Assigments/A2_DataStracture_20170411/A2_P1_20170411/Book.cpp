#include "Book.h"


istream& operator>>(istream& In , Book_Info& b){
	cout << "Enter The Name : "<<endl;In>>b.Name;
	cout << "Enter The Author : "<<endl;In>>b.Author;
	cout << "Enter The publish year : "<<endl;In>>b.Publish_Year;
	cout << "Enter The number of available versions : "<<endl;In>>b.NumOfAvalibalVer;
	return In;
}

ostream& operator<<(ostream& Out,Book_Info& b){
	Out << " Name : " << b.Name <<endl;
	Out << " Author : " << b.Author <<endl;
	Out << " publish year : " << b.Publish_Year <<endl;
	Out << " The number of available versions : " << b.NumOfAvalibalVer <<endl;
	return Out;
}


void Book::AddBook(){
	cout << "Please enter the Book info: ";
	Book_Info b;
    cin >> b;
	Boo[b.Name] = b;
}
void Book::Search_Book_byName(string n){
	if (Boo.find(n) != Boo.end())
        cout << Boo[n] << '\n';
	else 
		cout<<"Not found!! " <<endl;
}
void Book::Search_Book_byAuthor(string n){
	if (Boo.find(n) != Boo.end())
        cout << Boo[n] << '\n';
	else 
		cout<<"Not found!! " <<endl;
}
void Book::List_Books(){
	for (map<string, Book_Info>::iterator it = Boo.begin(); it != Boo.end(); it++){
        cout << it->first << '\n';
    }
}

void Book::Update_NumOfAvalibalVer(string c){
	if (Boo.find(c) != Boo.end()) {
        int new_NumOfAvalibalVer;
        cin >> new_NumOfAvalibalVer;
		Boo[c].NumOfAvalibalVer = new_NumOfAvalibalVer ;
    }
    else {
        cout << "The student can't be found.\n";
    }
}

int MaxNumber(vector<int> a){
	int Max = a[0];
	for(int i=i;i<a.size();i++){
			if(Max<a[i])
				Max = a[i];
	}
	for(int j=0;j<a.size();j++){if(Max == a[j])return j;}
}

bool cmp(const pair<string, Book_Info>& st1, const pair<string, Book_Info>& st2) {
	return st1.second.NumOfAvalibalVer < st2.second.NumOfAvalibalVer;
};

void Book::Find_Book(){
	if (Boo.size() > 0) {
        cout << max_element(Boo.begin(), Boo.end(), cmp)->second << '\n';
    }
    else {
        cout << "There exists no students.\n";
    }
}

Book::~Book(void){}
