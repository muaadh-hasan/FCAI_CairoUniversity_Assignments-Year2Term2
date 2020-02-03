#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include<vector>
#include <ctime>
using namespace std;

double GetMax(double M,double Y)
{
    if(M>Y)
        return M;
    else
        return Y;
}

double GetMin(double A1,double A2,double A3)
{
    if(A1<A2 && A1<A3)
        return A1;
    else if(A2<A1 && A2<A3)
        return A2;
    else
        return A3;
}

double arraySum(double a[], int n)  
{ 
    int sum  = 0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
    return sum; 
} 
double arraySum(vector<double> &v,int n)  
{ 
    int sum  = 0;
	for(int i=0;i<n;i++){
		sum += v[i];
	}
    return sum;
} 

const int timeOfRuns = 200;

int main ()
{
    default_random_engine generator(time(0));

    //exponential_distribution<double> IAT(1);
    //uniform_int_distribution<> ST_ATM_1(1,5);
    normal_distribution<> IAT(1,0.2);
	normal_distribution<> ST_C((1/6),(4/6));


    double Inter_Arrival_Time[timeOfRuns];
    double Arrival_Time[timeOfRuns];
    double Service_Start_Time_C[timeOfRuns];
    double Waiting_Time[timeOfRuns];
    double Service_Time_C[timeOfRuns];
    double completion_Time_C[timeOfRuns];
    double Time_In_System[timeOfRuns];
	double T_C[timeOfRuns];

	float CashierAvailTime = 0;

	//Start First Phase
	for(int i=0;i<timeOfRuns;i++){
		Inter_Arrival_Time[i]=IAT(generator);
        if(i==0)
            Arrival_Time[i] = Inter_Arrival_Time[i];
        else
            Arrival_Time[i] =Arrival_Time[i-1] + Inter_Arrival_Time[i];
		Service_Start_Time_C[i] =GetMax(Arrival_Time[i],CashierAvailTime);
		Service_Time_C[i] = ST_C(generator);
		completion_Time_C[i] = Service_Start_Time_C[i] + Service_Time_C[i];
		CashierAvailTime = GetMin(CashierAvailTime,1,completion_Time_C[i]);
		T_C[i] = completion_Time_C[i] - Arrival_Time[i];
	}
	sort(completion_Time_C,completion_Time_C+timeOfRuns);
	double Avg_T_C = arraySum(T_C,timeOfRuns) / timeOfRuns;

	// End First Phase

	// Start Second Phase
	normal_distribution<> ST_S(2,(1/3));
	double T_Salad[timeOfRuns];
	double Completion_Salad[timeOfRuns];
	double Service_Time_Salad[timeOfRuns];
	double Start_Service_Salad[timeOfRuns];
	double Arr_SALAD[timeOfRuns];
	for(int i=0;i<timeOfRuns;i++){Arr_SALAD[i] = completion_Time_C[i];}
	double SaladAvailTimeArray = 0;
	//for(int i=0;i<timeOfRuns;i++){SaladAvailTimeArray[i] = 0 ;}

	for(int i=0;i<timeOfRuns;i++){
		Start_Service_Salad[i] = GetMax(Arr_SALAD[i],SaladAvailTimeArray);
		Service_Time_Salad[i] = ST_S(generator);
		Completion_Salad[i] = Start_Service_Salad[i] + Service_Time_Salad[i];
		SaladAvailTimeArray = GetMin(SaladAvailTimeArray,Start_Service_Salad[i],Completion_Salad[i]);
		T_Salad[i] = Completion_Salad[i] - Arr_SALAD[i];
	}

	double Avg_T_Salad = arraySum(T_Salad,timeOfRuns) / timeOfRuns;
	sort(Completion_Salad,Completion_Salad+timeOfRuns);
	// End Second Phase

	double Arr_SOUP2 = 0;
	normal_distribution<> Arr_Soup_rand(1,(1/4));
	vector<double> Arr_SOUP;

	int n_Salad_Soup = 0;
	for(int i=0;i<timeOfRuns;i++){
		Arr_SOUP2 = Arr_Soup_rand(generator);
		if(Arr_SOUP2<0.6){
			n_Salad_Soup+=1;
			Arr_SOUP.push_back(Completion_Salad[i]);
		}
	}

	// Start Third Phase
	double SoupAvailTimeArray = 0;
	vector<double> Start_Service_Soup;
	vector<double> Service_Time_Soup;
	vector<double> Completion_Soup;
	vector<double> T_soup;
	normal_distribution<> ST_Soup(1,(1/4));

	for(int i=0;i<n_Salad_Soup;i++){
		Start_Service_Soup.push_back(GetMax(Arr_SOUP[i],SoupAvailTimeArray));
		Service_Time_Soup.push_back(ST_Soup(generator));
		Completion_Soup.push_back(Start_Service_Soup[i] + Service_Time_Soup[i]);
		SoupAvailTimeArray = GetMin(SoupAvailTimeArray,Start_Service_Soup[i],Completion_Soup[i]);
		T_soup.push_back(Completion_Soup[i] - Arr_SOUP[i]);
	}
	double Avg_T_Soup = arraySum(T_soup,n_Salad_Soup) / n_Salad_Soup;

	cout<<"Average time a customer spends paying & getting food" <<endl;
	cout<<"\n if getting salad only is: %4.2f " << Avg_T_C + Avg_T_Salad  <<endl;
	cout<<"\n if getting both is: %4.2f " << Avg_T_C + Avg_T_Salad  + Avg_T_Soup <<endl;

	return 0;
	system("pause");
}