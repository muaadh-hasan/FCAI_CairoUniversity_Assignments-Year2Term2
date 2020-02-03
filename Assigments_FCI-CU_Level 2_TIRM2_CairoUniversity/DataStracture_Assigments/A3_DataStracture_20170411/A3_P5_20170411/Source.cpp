#include <iostream>
#include <stack>
#include<string>
using namespace std;
bool isPalindrome(string a)
{
    string temp = "";
    stack<char> s;
    for(int i =0 ; i < a.size() ; i++)
    {
        s.push(a[i]);
    }
    while (!s.empty())
    {
        temp += s.top();
        s.pop();
    }
    return a==temp;
}
int main()
{
    string s = "abba" , s2 = "cbcbc";
    if (isPalindrome(s))
      cout << "Palindrome" << endl;
    else
      cout << "Not Palindrome" << endl;

    if (isPalindrome(s2))
      cout << "Palindrome" << endl;
    else
      cout << "Not Palindrome" << endl;
	system("pause");
}