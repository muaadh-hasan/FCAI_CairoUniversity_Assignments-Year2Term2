#include <iostream>
#include <random>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
using namespace std;

int const RunTimes = 1000;

int Calculate_DirectLabor(double D)
{
    int c1;
    double r = D ;
    if (r<=0.0 & r<0.1)
    {
        c1 = 43  ;
    }
    else if (r<=0.1& r<0.3)
    {
        c1 = 44 ;
    }
    else if (r<=0.3& r<0.7)
    {
        c1 = 45  ;
    }
    else if (r<=0.7& r<0.9)
    {
        c1 = 46  ;
    }
    else
    {
        c1 = 47  ;
    }
    return c1;
}


/*int Calculate_PartsCostPerUnit(double D){
	return 80 + D *(100-80);
}*/


void pseudorandom_number_generator(){
	default_random_engine generator(time(0));
	uniform_real_distribution<double> Task_2( 0.0, 1.0 );
	for(int i=0;i<100;i++){
		cout << Task_2(generator) << " " ;
	}
}





int main ()
{

	cout << "-------------Welcome to our program ( Yageen & Gobran & Taqi & Muaath )----------------"<<endl;
	//cout<<"Run Times      "<<"DIRECT LABOR        "<<"PARTS COAST            "<<"         DEMAND                "<<"      PROFIT"<<endl;

    default_random_engine generator(time(0));

	int RandomDirectLabor[RunTimes];
    int RandomPartsCostPerUnit[RunTimes];
    double RandomDemand[RunTimes];
	int Profit[RunTimes];
	//c2
    uniform_int_distribution<int> Part_Cost(80,100) ;
	//for funq c1
	uniform_real_distribution<double> Dircet_Cost( 0.0, 1.0 );
	//for x
	normal_distribution<double> Demand(15000.0, 4500.0);

	for(int i=0;i<RunTimes;i++){
		RandomPartsCostPerUnit[i] =  Part_Cost(generator);
		RandomDirectLabor[i] = Calculate_DirectLabor(Dircet_Cost(generator));
		RandomDemand[i] =  Demand(generator);
		Profit[i] = (249-RandomDirectLabor[i]-RandomPartsCostPerUnit[i])*RandomDemand[i]-1000000;
	}
	/*
	for (int i=0 ; i<RunTimes ; i++)
    {
        cout<<"  "<< i+1 <<"               "<<RandomDirectLabor[i]<<"                   "<<RandomPartsCostPerUnit[i]<<"                          "<<RandomDemand[i]<<"                    "<<Profit[i]<<endl;
    }


    cout<<"\n ------------------------------------------------------------ \n";
	*/
    

	int Maximum_Loss = Profit[0];
	int Maximum_Profit = Profit[0];

	for (int i = 0; i < RunTimes; i++)
    {
        if (Profit[i] > Maximum_Profit)
        {
            Maximum_Profit = Profit[i];
        }
        else if (Profit[i] < Maximum_Loss)
        {
            Maximum_Loss = Profit[i];
        }
    }

	cout <<"The maximum profit is : "<< Maximum_Profit << endl;
    cout <<"The minimum profit (Loss) is : "<< Maximum_Loss << endl;

	int sum=0;
    int AVG;

    for(int i=0 ; i<RunTimes ; i++)
    {
        sum+=Profit[i];
    }
    AVG=sum/RunTimes;
    cout<<"The Average of the profit is : "<<AVG<<endl;


    float count=0;
    for(int i=0 ; i<RunTimes ; i++)
    {
        if (Profit[i]<0)
            count++;
    }
    cout<<"Number of Loss is : "<<count<<endl;
	double probability_of_loss = (count / RunTimes);
	cout << "probability_of_loss is : " << float (probability_of_loss)<< "%" << endl;

	// Hitogram


	ofstream Bar("Histogram.txt");
	for(int i=0 ; i<RunTimes ; i++)
    {
		Bar << Profit[i] << endl;
	}
	cout << "_________________________________________ " << endl;

	// task 2
	//pseudorandom_number_generator();

	/*
	ofstream Bar("BarChart.svg");

	Bar<<"<svg width=\"1000\" height=\"1000\"\n";
    Bar<<"xmlns=\"http://www.w3.org/2000/svg\">\n";
    Bar<<"<line x1=\"150\" y1=\"600\" x2=\"150\" y2=\"850\"\n";
    Bar<<"style=\"stroke:purple;stroke-width:3\"/>\n";
    Bar<<"<line x1=\"150\" y1=\"600\" x2=\"600\" y2=\"600\"\n";
    Bar<<"style=\"stroke:purple;stroke-width:3\"/>\n";
	for(int i=0 ; i<RunTimes ; i++)
    {
		Bar<<"<rect x=\"200\" y=\"600\" width=\"50\" height=\""<<Profit[i]<<"\"\n";
		Bar<<"style=\"fill:blue;\"/>\n";
	}
	Bar<<"</svg>\n";
	*/
	system("pause");
    return 0;
}
