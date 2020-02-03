
#include <iostream>
#include <random>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>

using namespace std;


unsigned int PRNG(unsigned int seed1)
{
	static unsigned int nSeed= seed1 ;
    nSeed = (7777777 * nSeed + 2396403);
    return nSeed  % 32767;
}

int main()
{
	// Task 3

	cout << "\n        -------------Welcome to our program ( Yageen & Gobran & Taqi & Muaath )----------------"<<endl<<endl;


		cout << "\n        ------------- Task 3 ----------------"<<endl<<endl;

	int e = 0;
	int col_Profit[2];
	for (int i=0;i<2;i++){
		int Profit = 0;
		int Available_PCs = 1+e;
		for (int i=0;i<500;i++){
			default_random_engine generator(time(0));
			uniform_int_distribution<int> X(0,4);
			int Random_X = X(generator);
			if(Random_X > Available_PCs){
				Random_X -= Available_PCs;
				Random_X *= 100;
				Profit += ((Available_PCs * 450) - Random_X);
			}
			else if(Random_X < Available_PCs){
				Available_PCs -= Random_X;
				Available_PCs *= 50;
				Profit += ((Random_X*450) - Available_PCs);
			}
			else{
				Profit += (Random_X*450);
			}
			 Available_PCs += 1+e;
		}
		col_Profit[e] = Profit;
		e++;
	}
	if (col_Profit[0]/500 > col_Profit[1]/500){
		cout << "                        -->   The avreage Profit of # One is the best : " << col_Profit[0]/500 <<endl;
		cout << "                        -->   The avreage Profit of # Two is : " << col_Profit[1]/500 <<endl<<endl;
	}
	else
	{
		cout << "                        -->   The avreage Profit of # One is  : " << col_Profit[0]/500 <<endl;
		cout << "                        -->   The avreage Profit of # Two is the best : " << col_Profit[1]/500 <<endl<<endl;
	}
	


	
	cout << "\n        ------------- Task 2 ----------------"<<endl<<endl;

	// Task 2
	
	for (int nCount=0; nCount < 100; ++nCount)
    {	
		float float_number = (float) rand()/RAND_MAX;
		cout << float_number << "\t" ;
		if ((nCount+1) % 7 == 0)
            cout << endl;
    }
	
	cout << "___________________________________________"<<endl<<endl;

	static unsigned int seed;
	cout <<"Enter Your Seed From 4 Numbers "<<  endl ;
	cin >> seed;
    for (int nCount=0; nCount < 100; ++nCount)
    {
        cout<< ((PRNG(seed)%1000)/1000.0) << "\t";
        if ((nCount+1) % 5 == 0)
            cout << endl;
    }

	
	system("pause");
}
