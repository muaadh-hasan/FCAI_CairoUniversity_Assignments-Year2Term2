
//____________________________________________________
// Assignment # 1 - Files
// By : Muaath Hasan 20170411 & Gobran Asker 20160389
//----------------------------------------------------

#include <iostream>
#include <fstream>
#include<string>
#include<strstream>

using namespace std;

#define Massage cout<<"\n   Welcome to our programe ^^ ( Muaath Hasan & Gobran Asker )\n   --------------------------------------------------------- "<<endl;
#define In_Out fstream f("try.txt", ios::in | ios::out);
#define In ifstream fi("try.txt");
#define Out ofstream fo("try.txt");

const int maxBuffersize = 200;

struct Book
{
    char ISBN[6];
    char title[20];
    char AUTHOR_NAME[20];
    char PRICE[6];
    char YEAR[6];
    char NUM_OF_PAGES[4];
};

istream& operator>>(istream & in, Book &b)
{
    cout << "\n Enter ISBN: ";
    in.getline(b.ISBN, 6);
    cout << "\n Enter title: ";
    in.getline(b.title, 20);
    cout << "\n Enter AUTHOR NAME: ";
    in.getline(b.AUTHOR_NAME, 20);
    cout << "\n Enter PRICE: ";
    in.getline(b.PRICE, 6);
    cout << "\n Enter YEAR: ";
    in.getline(b.YEAR, 6);
    cout << "\n Enter Number OF PAGES: ";
    in.getline(b.NUM_OF_PAGES, 4);
    cout << endl;
    return in;
}

ostream& operator<<(ostream & os, Book &b)
{
    os <<"\n ISBN: " << b.ISBN ;
    os <<"\n title: " << b.title ;
    os <<"\n AUTHOR_NAME: "<<  b.AUTHOR_NAME;
    os <<"\n PRICE: " << b.PRICE ;
    os <<"\n YEAR: " << b.YEAR ;
    os <<"\n NUM_OF_PAGES: " << b.NUM_OF_PAGES << endl;

    return os;
}


void WriteBook(fstream & stream)
{
    Book b;
    cin >>b;
    char buffer[maxBuffersize];
    strcpy(buffer, b.ISBN);
    strcat(buffer, "|");
    strcat(buffer, b.title);
    strcat(buffer, "|");
    strcat(buffer, b.AUTHOR_NAME);
    strcat(buffer, "|");
    strcat(buffer, b.PRICE);
    strcat(buffer, "|");
    strcat(buffer, b.YEAR);
    strcat(buffer, "|");
    strcat(buffer, b.NUM_OF_PAGES);
    strcat(buffer, "|");

    short length = strlen(buffer);
    stream.write((char*)&length, sizeof(length));
    stream.write(buffer, length);

}

void AddBook(fstream & f)
{
    f.seekp(0, ios::end);
    WriteBook(f);

}

void Read_all_Book(fstream & i)
{
    Book b;
    short length;

    i.seekg(0, ios::beg);
    while (!i.eof())
    {
        i.read((char *)&length, sizeof(length));
        char* buffer = new char[length];
        i.read(buffer, length);

        istrstream strbuf(buffer);

        strbuf.getline(b.ISBN, 6, '|');
        strbuf.getline(b.title, 20, '|');
        strbuf.getline(b.AUTHOR_NAME, 20, '|');
        strbuf.getline(b.PRICE,6, '|');
        strbuf.getline(b.YEAR, 6, '|');
        strbuf.getline(b.NUM_OF_PAGES, 4, '|');

        if(b.ISBN != "*")
        {
            cout << b  << endl;
        }
        delete [] buffer;
    }

    i.clear();
}

void Read_by_title(fstream & i,char t[])
{
    Book b;
    short length;
    int ch = 0;
    i.seekp(0,ios::beg);
    while (!i.eof())
    {
        i.read((char *)&length, sizeof(length));
        char* buffer = new char[length];
        i.read(buffer, length);
        istrstream strbuf(buffer);
        strbuf.getline(b.ISBN, 6, '|');
        strbuf.getline(b.title, 20, '|');
        strbuf.getline(b.AUTHOR_NAME, 20, '|');
        strbuf.getline(b.PRICE,6, '|');
        strbuf.getline(b.YEAR, 6, '|');
        strbuf.getline(b.NUM_OF_PAGES, 4, '|');
        if (t == b.title )
        {
            cout<<"the data By title : " << b.title  << "is :"<<endl;
            cout << b << endl;
			ch = 1;
            break;
        }
        delete [] buffer;
    }
    if(ch==0)
    {
        cout<<"There is not data in this title : " << t << endl;
    }
}

void Delete_by_ISBN(fstream & i,char t[])
{
    Book b;
    short length;
    int ch = 0;
    i.seekp(0,ios::beg);
	int all_length = 0;
	string s;
    while (!i.eof())
    {
        i.read((char *)&length, sizeof(length));
		all_length +=length;
        char* buffer = new char[length];
        i.read(buffer, length);
        istrstream strbuf(buffer);
        strbuf.getline(b.ISBN, 6, '|');
        strbuf.getline(b.title, 20, '|');
        strbuf.getline(b.AUTHOR_NAME, 20, '|');
        strbuf.getline(b.PRICE,6, '|');
        strbuf.getline(b.YEAR, 6, '|');
        strbuf.getline(b.NUM_OF_PAGES, 4, '|');
		s = b.ISBN;
		if (t == s )
        {
			cout<<"the data By ISBN : " << b.ISBN  << "  Will delete ... :"<<endl;
            cout << b << endl;
			
			i.seekp(all_length,ios::beg);
			Book b;
    
			char buffer[maxBuffersize];
			(buffer, "*");
			strcat(buffer, "|");
			strcat(buffer, b.title);
			strcat(buffer, "|");
			strcat(buffer, b.AUTHOR_NAME);
			strcat(buffer, "|");
			strcat(buffer, b.PRICE);
			strcat(buffer, "|");
			strcat(buffer, b.YEAR);
			strcat(buffer, "|");
			strcat(buffer, b.NUM_OF_PAGES);
			strcat(buffer, "|");

			short length = strlen(buffer);
			i.write((char*)&length, sizeof(length));
			i.write(buffer, length);
			cout <<" DONE ! "<< endl;
			ch = 1;
            break;
        }
        delete [] buffer;
    }
    if(ch==0)
    {
        cout<<"There is not data in this ISBN : " << t << endl;
    }
}

void UpdateBook_by_ISBN(fstream & io, char I[])
{
    Book b;
    short length;
    int ch = 0;
    io.seekp(0,ios::beg);

    while (!io.eof())
    {
        io.read((char *)&length, sizeof(length));
        char* buffer = new char[length];
        io.read(buffer, length);
        istrstream strbuf(buffer);
        strbuf.getline(b.ISBN, 6, '|');
        strbuf.getline(b.title, 20, '|');
        strbuf.getline(b.AUTHOR_NAME, 20, '|');
        strbuf.getline(b.PRICE,6, '|');
        strbuf.getline(b.YEAR, 6, '|');
        strbuf.getline(b.NUM_OF_PAGES, 4, '|');
		if (I == b.ISBN && b.ISBN !="*")
        {
            cout<<"the data you want to edit is : "<<endl;
            cout << b  << endl;
            io.seekp(-length,ios::cur);
            cout<<"Enter the new data you want to edit it : "<<endl;
            WriteBook(io);
            ch = 1;
            break;
        }
        delete [] buffer;
    }
    if(ch==0)
    {
        cout<<"There is not data in this ISBN : " << I << endl;
    }
}

int main()
{
	Massage
    //AddBook(fo);

    In_Out
    /*
    for (int i=0;i<2;i++){
    	cout << "Enter Data for Book Number " << i+1 <<endl;
		WriteBook(f);
    }
    f.close();
    */
    //Read_all_Book(f);
    //char s[20];
	//cin>>s;
    //UpdateBook_by_ISBN(f,s);
    //Read_by_title(f,s);
	//Delete_by_ISBN(f,s);

    f.close();

    system("pause");
    return 0;
}

