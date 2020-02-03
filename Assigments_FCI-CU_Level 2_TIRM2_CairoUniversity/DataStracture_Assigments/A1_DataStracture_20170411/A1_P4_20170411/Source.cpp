#include <iostream>
#include <string>

using namespace std;


int power(int a,int n){
	if(n==0)
		return 0;
	else if (n==1)
		return a;
	else
		return (a * power(a,n-1));
}

int power2(int a,int n){
	if(n==0)
		return 0;
	else if (n==1)
		return a;
	else if(n%2==0)
		return (power(a,n/2) * power(a,n/2));
	else
		return a * (power(a,n/2) * power(a,n/2));
}

int main (){

	cout << power(5,3) << endl;
	cout << power2(5,3) << endl;


	system("pause");
}
