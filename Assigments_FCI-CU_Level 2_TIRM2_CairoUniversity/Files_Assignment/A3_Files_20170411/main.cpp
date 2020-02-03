#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <strstream>
#include <iterator>

using namespace std;

// primary index
struct primary_index{
	char primary_key [6] ;
	int byet_ofset ;
} p_index ;
// secondary index
struct secondary_index{
	char primary_key [6] ;
	string instructor_name ;
} s_index ;
// course data
struct C_data{
	char cours_id [6] ;
	std::string cours_name ;
	std::string instructor_name ;
	int cours_week ;
} c_data ;

vector<primary_index> P_index ;
vector<secondary_index> S_index ;

const int max_size = 100 ;
char file_name[20] = "file.txt" ;
char primary_index_file[20] = "index_file.txt" ;
char secondary_index_file[20] = "secondary_file.txt" ;

istream& operator >> (istream& in ,  C_data& c_data) {
	cout << "Enter course Id : " ;
	in.getline(c_data.cours_id , 6);
	cout << "Enter course name : " ;
	getline(in , c_data.cours_name);
	cout << "Enter Instructor name : " ;
	getline(in , c_data.instructor_name);
	cout << "Enter course week : " ;
	in >> c_data.cours_week ;
	return in ;
}
ostream& operator << (ostream& out , const C_data& c_data){
	out <<"Course Id : " << c_data.cours_id << endl
		<<"Course name : " << c_data.cours_name << endl
		<<"Instructor name : " << c_data.instructor_name << endl
		<< "Week number : " << c_data.cours_week << endl ;
	return out ;
}
// check if file exist
bool check_file(char* _file_name){
	fstream file(_file_name);
	if (file.good()){
		file.close();
		return true ;
	}else{
		file.close();
		return false ;
	}
}
void change_index_state(bool _state){
	fstream file(file_name , ios::binary | ios::ate | ios::out | ios::in);
	file.seekp(0 ,  ios::beg);
	file.write((char*)&_state , sizeof(_state));
	file.close();
}
bool get_index_stste(){
	bool flag  ;
	fstream file(file_name , ios::in);
	file.seekg(0 , ios::beg);
	file.read((char*)&flag , sizeof(flag));
	file.close();
	return flag ;
}
void load_indexes(){
	bool flag = false ;
	if (!check_file(file_name)){
		fstream file(file_name ,ios::out);
		file.write((char*)&flag , sizeof(flag));
		file.close();
	}else if(!get_index_stste()){
		ifstream P_Index(primary_index_file ,  ios::binary | ios::in);
		ifstream S_Index(secondary_index_file , ios::binary | ios::in);
		S_Index.seekg(0 , ios::beg);
		while (true){
			P_Index.read((char*)&p_index , sizeof(p_index));
			//cout << p_index.byet_ofset << " " << p_index.primary_key << endl ;
			P_index.push_back(p_index);
			S_Index.read((char*)&s_index , sizeof(s_index));
			//cout << s_index.instructor_name << " " << s_index.primary_key << endl ;
			S_index.push_back(s_index);
			if (!S_Index.eof() && !P_Index.eof())
				break ;
		}
		/*
		for (int i = 0 ; i < P_index.size() ; i++){
			cout << P_index[i].primary_key << "  "<< P_index[i].byet_ofset << endl ;
		}
		for (int i = 0 ; i < S_index.size() ; i++){
			cout << S_index[i].primary_key << "  "<< S_index[i].instructor_name << endl;
		}*/
		P_Index.close();
		S_Index.close();

	}else{
		//reconstruct_index();
	}
}
void save_idexes(){
	bool flag = false ;
	ofstream P_Index(primary_index_file , ios::app | ios::binary);
	ofstream S_Index(secondary_index_file , ios::app | ios::binary);
	for (int i = 0 ; i < P_index.size() ; i++){
		P_Index.write((char*)&(P_index[i]) , sizeof(P_index[i]));
	}
	for (int i = 0 ; i < S_index.size() ; i++){
		S_Index.write((char*)&(S_index[i]) , sizeof(S_index[i]));
	}
	P_Index.close();
	S_Index.close();
	change_index_state(flag);
}
void add_course(){

	bool flag = true ; int length = 0 ; int address = 0 ; char buffer[max_size] ;
	change_index_state(flag);
	fstream file(file_name , ios::binary | ios::ate | ios::in | ios::out);

	cin >> c_data ;

	strcpy_s(buffer , c_data.cours_id);
	strcat_s(buffer , "$");
	strcat_s(buffer , c_data.cours_name.c_str());
	strcat_s(buffer , "$");
	strcat_s(buffer , c_data.instructor_name.c_str());
	strcat_s(buffer , "$");
	strcat_s(buffer , (char*)&c_data.cours_week );
	strcat_s(buffer , "$");

	length = strlen(buffer);
	cout << "length : " << length << endl ;
	file.seekp(0 , ios::end);

	//p_index.byet_ofset = file.tellp();
	file.write((char*)&length , sizeof(length));
	file.write(buffer , length) ;
	//strcpy_s(p_index.primary_key , c_data.cours_id);
	//strcpy_s(s_index.instructor_name , c_data.instructor_name.c_str());
	//strcpy_s(s_index.primary_key , c_data.cours_id);
	//P_index.push_back(p_index);
	//S_index.push_back(s_index);
	file.close();
}
void print_cours(){

	fstream file(file_name , ios::binary | ios::in );

	char cours_name[25] , instructor_name[25] , course_week[4] ;
	bool flag = true ; int length = 0 ,  address = 0 ; char * buffer ;
	int _count = 0 ;

	file.seekg(address , ios::beg);
	file.read((char*)&flag , sizeof(flag));

	while (!file.eof()){

		//file.seekg(address , ios::beg);
		//file.read((char*)&flag , sizeof(flag));
		cout << "flag : " << flag << endl ;
		file.read((char*)&length , sizeof(length));
		cout << "length : " << length << endl ;
		buffer = new char[length] ;
		file.read(buffer , length);
		cout << "buffer : " << buffer << endl ;
		istrstream strbuf(buffer);
/*
		while (buffer){
			strbuf.getline(c_data.cours_id  , 7 , '$');
			strbuf.getline(cours_name , 26 , '$');
			c_data.cours_name = cours_name ;
			strbuf.getline(instructor_name , 26 , '$');
			c_data.instructor_name = instructor_name ;
			strbuf.getline(course_week , 5 , '$');
			c_data.cours_week = int(course_week) ;
			break ;
		}
		*/
		delete buffer ;

		cout << c_data ;
		cin.clear();
		if(!file.eof()){
			cout << "ok" << endl ;
			break ;
		}

	}
	file.close();
}

void delete_course(){

}
void reconstruct_index(){

}

int main(){
	//change_index_state(true);
	//cout << get_index_stste() << endl ;
	//add_course();
	//save_idexes();
	//load_indexes();
	print_cours();
	system("pause");
}
