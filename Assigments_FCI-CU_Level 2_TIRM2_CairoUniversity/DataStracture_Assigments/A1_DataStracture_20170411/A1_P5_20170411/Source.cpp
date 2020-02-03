
#include <iostream>
#include <set>
#include <string>
#include<vector>
using namespace std;


void RecPermute(string soFar, string rest)
{
	vector<string> s;



if (rest == "") // No more characters
{
    int size = s.size();
    s.push_back(soFar);
    if (size != s.size())
    {
      cout << soFar << endl; // Print the word
    }

}

else // Still more chars
// For each remaining char
for (int i = 0; i < rest.length(); i++) {
string next = soFar + rest[i]; // Glue next char
string remaining = rest.substr(0, i)+ rest.substr(i+1);
RecPermute(next, remaining);
}
}

// "wrapper" function
void ListPermutations(string s) {
RecPermute("", s);
}
int main()
{
    ListPermutations("abc");

	system("pause");
}
