#include <iostream>
#include <vector>

using namespace std;

bool non_degenerate(vector<int> & v,int Size)
{
    for(int i=0;i<Size-2;i++){
        for(int j=i+1;j<Size-1;j++){
             for(int k=j+1;k<Size;k++){
                 if( (v[i]+v[j])>v[k] && (v[i]+v[k])>v[j] && (v[k]+v[j])>v[i]  ){
                     return true;
                 }
             }
        }
    }
    return false;
}
int main()
{
    vector<int> v;
    vector<int> v1;
    int Size,input;
    cout << "enter size of vector: " << endl;
    cin >> Size;

    for(int i=0;i<Size;i++){
        cin >> input;
        v.push_back(input);
    }

    if( non_degenerate(v,Size) == true )
    {
      cout << "can generate non-degenerate triangle.....";
    }
    else{
          cout << "cannot construct a non-degenerate triangle..";
    }
    return 0;
}
