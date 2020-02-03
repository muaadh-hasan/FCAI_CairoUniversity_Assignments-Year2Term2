#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	map<string, int> M;
	string c;
	string ch = "done";
	cout << "enter the string : " << endl;
	cin>>c;
	while (c!=ch)
	{
		if (M.find(c) != M.end()){
			M[c]++;
		}
		else
			M[c] = 1;
		cin>>c;
	}
	for (map<string, int>::iterator it = M.begin(); it != M.end(); it++){
		cout << it->first  << " , " << it->second << '\n';
	}
	
	for (map<string, int>::iterator it = M.begin(); it != M.end();){
		string s = it->first;
		map <string , int > :: iterator it2 = ++it;
		if(s[0] == 'a'){
			M.erase(s);
			it = it2;
		}
	}

	cout << "erase all words that start with letter 'a' " <<endl;
	for (map<string, int>::iterator it = M.begin(); it != M.end(); ++it){
		cout << it->first  << " , " << it->second << '\n';
	}


	system("pause");
}