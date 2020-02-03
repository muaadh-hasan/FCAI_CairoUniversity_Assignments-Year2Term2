#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>


using std::string;
using std::map;
using std::pair;
using std::max_element;
using namespace std;


class Book_Info{
public:
	string Name,Author,Publish_Year;
	int NumOfAvalibalVer;
	friend istream& operator>>(istream& In , Book_Info& b);
	friend ostream& operator<<(ostream& Out,Book_Info& b);
};


class Book
{
private:
	map<string, Book_Info> Boo;
	
public:
	static int NumOfBooks;
	Book(){};
	void AddBook();
	void Search_Book_byName(string n);
	void Search_Book_byAuthor(string n);
	void List_Books();
	void Update_NumOfAvalibalVer(string);
	void Find_Book();
	void Display();

	~Book(void);
};




