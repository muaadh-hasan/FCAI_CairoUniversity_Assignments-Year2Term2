#include <iostream>
#include <Stack>
using namespace std;

bool VALID(string s);
int main()
{
    if (VALID("([{}])(){}[]{[]}"))
        cout << "valid"<<endl;
    else
        cout << "invalid"<<endl;

    if (VALID("({)}"))
        cout << "valid"<<endl;
    else
        cout << "invalid "<<endl;

    if (VALID("({/*)}]]]]]]}*/})"))
        cout << "valid"<<endl;
    else
        cout << "invalid "<<endl;

    if (VALID("({/*[][[]]]]]})"))
        cout << "valid"<<endl;
    else
        cout << "invalid "<<endl;

    if (VALID("[{/*******/}]"))
        cout << "valid"<<endl;
    else
        cout << "invalid "<<endl;

    return 0;
}

//valid function..
bool VALID(string s)
{
    stack<char> Stack;
    for(int i=0 ; i<s.size() ; i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{' )
        {
            if(Stack.empty())
                Stack.push(s[i]);
            else if(Stack.top()!='/')
            {
                Stack.push(s[i]);
            }
        }
        else if (s[i] == '/'){
            if(s[i+1]=='*'){
                Stack.push(s[i]);
            }
        }

        else if (s[i]=='*'){
            if(s[i+1]=='/'){
                if(Stack.top()=='/')
                    Stack.pop();
                else
                    return 0;
            }
        }

        else if (s[i]==')'){
            if(Stack.empty())
                return 0;
            else if(Stack.top()=='/')
                continue;
            else if (Stack.top() == '(')
                Stack.pop();
            else
                return 0;
        }

        else if (s[i]==']'){
            if(Stack.empty())
                return 0;
            else if(Stack.top() == '/' )
                continue;
            else if (Stack.top() == '[')
                Stack.pop();
            else
                return 0;
        }

        else if (s[i]=='}'){
            if(Stack.empty())
                return 0;
            else if(Stack.top()=='/')
                continue;
            else if (Stack.top() == '{')
                Stack.pop();
            else
                return 0;
        }
    }

    return Stack.empty();
}
