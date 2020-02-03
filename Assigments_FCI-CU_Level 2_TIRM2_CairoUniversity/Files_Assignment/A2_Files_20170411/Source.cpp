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
#define In_Out fstream f("try.txt", ios::in | ios::out | ios::binary);
#define In_Out_app fstream f("try.txt", ios::in | ios::out | ios::app);
#define In ifstream fi("try.txt");
#define Out ofstream fo("try.txt");

const char Delete  = '*';
const int maxBuffersize = 200;
const int size_of_Book = 68;

struct Book
{
    char ISBN[6];
    char title[20];
    char AUTHOR_NAME[20];
    char PRICE[6];
    char YEAR[6];
    char NUM_OF_PAGES[4];
	int RRN;
};

const static int maxRecordSize = 1000;

istream& operator>>(istream & in, Book &b)
{
	cin.ignore();
    cout << "\n Enter ISBN: ";
    in.getline(b.ISBN, 6);
    cout << " Enter title: ";
    in.getline(b.title, 20);
    cout << " Enter AUTHOR NAME: ";
    in.getline(b.AUTHOR_NAME, 20);
    cout << " Enter PRICE: ";
    in.getline(b.PRICE, 6);
    cout << " Enter YEAR: ";
    in.getline(b.YEAR, 6);
    cout << " Enter Number OF PAGES: ";
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

bool Add_Book(){
	In_Out
	Book b;
	cin >> b;
	
	b.RRN = -1;
    int fr = -1, ne = -1;
    char c;
    f.seekg(0,ios::beg);
    f.read((char*)&fr, sizeof(int));
    if(fr == -1)
    {
    	f.seekp(0, ios::end);
        b.RRN = f.tellp() / size_of_Book;
    }
    else
    {
    	b.RRN = fr;
        f.seekg(sizeof(int) + fr*size_of_Book, ios::beg);
        f.get(c);
		if (c != Delete) {return -1;}
        f.read((char*)&ne, sizeof(int));
        f.seekp(0,ios::beg);
        f.write((char*)&ne, sizeof(int));
        
        f.seekp(sizeof(int) + fr*size_of_Book, ios::beg);
    }
	int nextDel = -1;
    f.put(' ');
    f.write((char*)& nextDel, sizeof(int));
	f.write(b.ISBN, 6);
	f.write(b.title, 20);
	f.write(b.AUTHOR_NAME, 20);
	f.write(b.PRICE, 6);
	f.write(b.YEAR, 6);
	f.write(b.NUM_OF_PAGES, 4);
    
	cout << "DONE !" <<endl;
	f.close();
}

void print_book_by_title(){
	In_Out
	Book b;
	char ch[20];
	int n = 0 ;
	int s;
	cout << "Enter the title you want to print it : "<<endl;
	cin.ignore();
	cin.getline(ch,20);
	while(!f.eof()){
		char c;
		int nextDel = -1;
		f.get(c);
    
		if (c==Delete) {
			cout<<"deleted record"<<endl;
			return;
		}
    
		f.read((char*)&nextDel, sizeof(int));
		f.read(b.ISBN, 6);
		f.read(b.title, 20);
		f.read(b.AUTHOR_NAME, 20);
		f.read(b.PRICE, 6);
		f.read(b.YEAR, 6);
		f.read(b.NUM_OF_PAGES, 4);
		

		if(strcmp(b.title,ch)==0 && b.ISBN[0]!=Delete){
			n++;
			cout << b << endl;
			break;
		}	
	}
	f.close();
	
	if (n==0) cout << "There is no data in this title : "<< ch <<endl; 
}


void print_all(){
	In_Out
	Book b;
	while(!f.eof()){
		char c;
		int nextDel = -1;
		f.get(c);
    
		if (c==Delete) {
			cout<<"deleted record"<<endl;
			return;
		}
    
		f.read((char*)&nextDel, sizeof(int));
		f.read(b.ISBN, 6);
		f.read(b.title, 20);
		f.read(b.AUTHOR_NAME, 20);
		f.read(b.PRICE, 6);
		f.read(b.YEAR, 6);
		f.read(b.NUM_OF_PAGES, 4);
		
		cout << b << endl;
	}
	cin.clear();
	f.close();
}


void UpdateBook_by_ISBN(){
	In_Out
	Book b;
	int Offset = 0;
	int n = 0;
	char c[6];
	cout<<"Enter The ISBN you want to update it : "<<endl;
	cin.ignore();
	cin.getline(c,6);
	f.seekg(0);
	while(!f.eof()){
		short length;
		f.read((char*)&length,sizeof(length));
		char * record = new char[length];
		f.read(record,length);				
		istrstream strbuf(record);
		strbuf.getline(b.ISBN,6, '_');
		strbuf.getline(b.title,20, '_');
		strbuf.getline(b.AUTHOR_NAME,20, '_');
		strbuf.getline(b.PRICE,6, '_');
		strbuf.getline(b.YEAR,6, '_');
		strbuf.getline(b.NUM_OF_PAGES,4,'|');
		Offset+=length;
		if(strcmp(b.ISBN,c)==0 && b.ISBN[0]!=Delete){
			n=1;
			f.seekg((Offset - length)+2 ,ios::beg);
			cout<<"Enter the new Data : "<<endl;
			cin>>b;
			char record[maxRecordSize];
			strcpy(record,b.ISBN);strcat(record,"_");
			strcat(record,b.title);strcat(record,"_");
			strcat(record,b.AUTHOR_NAME);strcat(record,"_");
			strcat(record,b.PRICE);strcat(record,"_");
			strcat(record,b.YEAR);strcat(record,"_");
			strcat(record,b.NUM_OF_PAGES);strcat(record,"|");

			short length1 = strlen(record);
			if(length1>length){
				cout << "You can't Update here with larger size will add in the end of file " <<endl;
				f.seekg(0,ios::end);
				f.write((char *) &length1, sizeof(length1));
				f.write(record,length1);
				cout << "DONE !" <<endl;
				f.close();
				return;
			}
			f.write((char *) &length1, sizeof(length1));
			f.write(record,length1);
			cout << "DONE !" <<endl;
			f.close();
			break;
		}
	}
	if(n==0){cout << "There is no data in this title : "<< c <<endl;}
	f.close();
}


bool Delete_Book_by_ISBN(int RNN){
	In_Out;
	Book b;
	
//    int ch = 0;

    int fr = -1, numOfRecords = 0;
    char c;
    
    f.seekp(0, ios::end);
	numOfRecords = f.tellp()/ size_of_Book;
    if(RNN >= numOfRecords) return false;
	
    f.seekg(0,ios::beg);
    f.read((char*)&fr, sizeof(int));
    
	f.seekg(sizeof(int) + RNN * size_of_Book, ios::beg);
    f.get(c);
    if(c==' ') return false;
    
	f.seekp(sizeof(int) + RNN * size_of_Book, ios::beg);
	f.put(Delete);
    f.write((char*)& fr, sizeof(int));
    
    f.seekp(0,ios::beg);
    f.write((char*)& RNN, sizeof(int));
	/*
    if(ch==0)
    {
		cout<<"There is not data in this ISBN : " << ch << endl;
    }
	*/
}



int main(){
	In_Out
	int ch;
	Book b;
	cout << sizeof(b) <<endl;
	bool cheack = true;

	while (cheack == true){
		f.seekp(0,ios::end);
	    int pos = f.tellp();
	    if(pos <= 0)
	    {
	        int header = -1;
			f.write((char*) & header, sizeof(int));
	    }
		Massage
		cout << " \nEnter the chioce you want : \n 1.Add Book \n 2.Update book(by ISBN) \n 3.Delete Book(by ISBN) \n 4.print book(by title) \n 5.print all  \n 6.Compact_the_file \n 7. Exit"<<endl;
		cin>>ch;
		switch (ch){
			case 1:
				{
					Add_Book();
					break;
				}
			case 2:
				{
					UpdateBook_by_ISBN();
					break;
				}
			case 3:
				{
					int rrn;
					cout << "Enter the RRN " <<endl;
					cin>>rrn;
					Delete_Book_by_ISBN(rrn);
					break;
				}
			case 4:
				{
					print_book_by_title();
					break;
				}
			case 5:
				{
					print_all();
					break;
				}
			case 6:
				{
					cheack = false;
					break;
				}
		default:
				{
					cout << "No thing , you have to choese number from 1 to 6 only !! " << endl;
					break;
				}
		}

	}
	system("pause");
	return 0;
}