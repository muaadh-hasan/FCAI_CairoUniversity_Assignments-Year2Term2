#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include<vector>
#include <ctime>

using namespace std ;



double triangular(double Min,double Mode,double Max)
{
    double  R=0.0 ;
    R = rand() %10;
    if ( R == (( Mode -  Min) / ( Max -  Min)))
        return  Mode;
    else if ( R < (( Mode -  Min) / ( Max -  Min)))
        return  (Min + sqrt( R * ( Max -  Min) * ( Mode - Min)));
    else
        return (Max - sqrt((1 - R) * ( Max -  Min) * ( Max -  Mode)));
}

double ST_ATM_2()
{
    return triangular(2,4,3.3);
}

double GetMax(double IAT,double ATMs)
{
    if(IAT>ATMs)
        return IAT;
    else
        return ATMs;
}

double Max(double A[],int s)
{
	double Max = A[0];
	for(int i=0;i<s;i++){
    if(A[i]>Max)
        Max = A[i];
	}
	return Max;
}

double GetMin(double Atm1,double Atm2,double Atm3)
{
    if(Atm1<Atm2 && Atm1<Atm3)
        return Atm1;
    else if(Atm2<Atm1 && Atm2<Atm3)
        return Atm2;
    else
        return Atm3;
}

const int timeOfRuns = 10000;

int main ()
{
    default_random_engine generator(time(0));

    exponential_distribution<double> IAT(1);
    uniform_int_distribution<> ST_ATM_1(1,5);
    normal_distribution<> ST_ATM_3(3,0.5);

    double Inter_Arrival_Time[timeOfRuns];
    double Arrival_Time[timeOfRuns];
    double Service_Start_Time[timeOfRuns];
    double Waiting_Time[timeOfRuns];
    double Service_Time[timeOfRuns];
    double completion_Time[timeOfRuns];
    double Time_In_System[timeOfRuns];
    double Atm1[timeOfRuns],Atm2[timeOfRuns],Atm3[timeOfRuns];
    Atm1[0]=Atm2[0]=Atm3[0]=0;
    int counter1 =0 ;
    int counter2 =0 ;
    int NumOfChangeInATM1 =0 ;
	int NumOfChangeInATM2 =0 ;
	int NumOfChangeInATM3 =0 ;
    double sum =0 ;


    for (int i=0 ; i<timeOfRuns ; i++)
    {
        Inter_Arrival_Time[i]=IAT(generator);
        if(i==0)
            Arrival_Time[i] =Inter_Arrival_Time[i];
        else
            Arrival_Time[i] =Arrival_Time[i-1] + Inter_Arrival_Time[i];
        if(i==0)
            Service_Start_Time[i] =Arrival_Time[i];
        else
            Service_Start_Time[i] =GetMax(Arrival_Time[i],GetMin(Atm1[i],Atm2[i],Atm3[i]));
        if(i==0)
        {
            Service_Time[i] =ST_ATM_1(generator);
            completion_Time[i] =Service_Start_Time[i] + Service_Time[i];
        }
        else
        {
            if(Atm1[i]<Atm2[i] &&

                    Atm1[i]<Atm3[i])
            {
                Service_Time[i]= ST_ATM_1(generator);
                completion_Time[i] = Service_Start_Time[i] + Service_Time[i];
            }
            else if(Atm2<Atm1 &&Atm2<Atm3)
            {
                Service_Time[i]= ST_ATM_2();
                completion_Time[i] = Service_Start_Time[i] +Service_Time[i];
            }
            else
            {
                Service_Time[i]= ST_ATM_3(generator);
                completion_Time[i] = Service_Start_Time[i] +Service_Time[i];
            }
        }
        Waiting_Time[i] = Service_Start_Time[i] - Arrival_Time[i];
        Time_In_System[i] =completion_Time[i] - Arrival_Time[i];
        if(i==0)
            Atm1[i] =completion_Time[i];
        else
        {
            if(Atm1[i-1]<=Atm2[i-1]&& Atm1[i-1]<=Atm3[i-1])
                Atm1[i] =completion_Time[i];
            else
                Atm1[i] =Atm1[i-1];
            if(Atm2[i-1]<=Atm1[i-1]&& Atm2[i-1]<=Atm3[i-1])
                Atm2[i] =completion_Time[i];
            else
                Atm2[i] =Atm2[i-1];
            if(Atm3[i-1]<Atm1[i-1]&& Atm3[i-1]<Atm2[i-1])
                Atm3[i] =completion_Time[i];
            else
                Atm3[i] =Atm3[i-1];
        }
    }



    cout <<                                     "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _Welcome to Your Program Multi Service Queuing Model _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n" << endl;
    //cout <<"IAT " << setw(15)<<" AT"<< setw(20)<<"SST"<<setw (15)<<"WT"<<setw(15)<<"ST"<< setw(15)<<"CT"<<setw(15)<<"T_In_System"<<setw(15)<<"ATM1"<< setw(15)<<"ATM2"<<setw(15) <<"ATM3"<< endl;
   // cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<< endl ;
    for (int j=0 ; j< timeOfRuns ; j++)
    {
       // cout << Inter_Arrival_Time[j] << setw(15) <<Arrival_Time[j] << setw(15)<< Service_Start_Time[j] <<setw(15) << Waiting_Time[j] <<setw(15) <<Service_Time[j] <<setw(15)<<completion_Time[j]<<setw(15)<< Time_In_System[j] << setw(15)<< Atm1[j]<< setw(15)<<Atm2[j]<<setw(15)<<Atm3[j] <<endl ;
    }


     for (int i=0 ;i<timeOfRuns ; i++) {

        if (Waiting_Time[i] > 1)
            counter1++ ;
        if (Waiting_Time[i] > 0)
            counter2++ ;
     }


     for (int n=0 ; n<timeOfRuns ; n++){
        if (n==0)
           sum = Waiting_Time[n]+Waiting_Time[n+1] ;
        else
            sum += Waiting_Time[n] ;
     }

	 double Total_srvice_timeATM1 = 0;
	 for (int n=0 ; n<timeOfRuns ; n++){
			Total_srvice_timeATM1 +=  Atm1[n] ;
     }

	 double Total_srvice_timeATM2 = 0;
	 for (int n=0 ; n<timeOfRuns ; n++){
			Total_srvice_timeATM2 +=  Atm2[n] ;
     }

	 double Total_srvice_timeATM3 = 0;
	 for (int n=0 ; n<timeOfRuns ; n++){
			Total_srvice_timeATM3 +=  Atm3[n] ;
     }


     for (int s=0; s<timeOfRuns; s++) {
        if (Atm1[s] != Atm1[s+1])
          NumOfChangeInATM1++ ;
     }
	 for (int s=0; s<timeOfRuns; s++) {
        if (Atm1[s] != Atm1[s+1])
          NumOfChangeInATM2++ ;
     }
	 for (int s=0; s<timeOfRuns; s++) {
        if (Atm1[s] != Atm1[s+1])
          NumOfChangeInATM3++ ;
     }

	 



     cout <<"\n\nThe Average Waiting Time =" << float(sum/timeOfRuns)<< endl;
     cout << "The Probability Of Waiting = " << float((counter2/timeOfRuns) * 100) << "v%" << endl ;
     cout << "The Probability Of Waiting more than 1 Minute =" <<float((counter1/timeOfRuns) * 100)<<" %" << endl ;
     cout << "The Maximum Waiting Time =" << Max(Waiting_Time,timeOfRuns) << endl ;
	 cout << "Utilization of the first ATM machine = " << Atm1[timeOfRuns-1]/Total_srvice_timeATM1 << endl ;
	 cout << "Utilization of the second ATM machine = " << Atm2[timeOfRuns-1]/Total_srvice_timeATM2 << endl ;
	 cout << "Utilization of the third ATM machine = " << Atm3[timeOfRuns-1]/Total_srvice_timeATM3 << endl ;




	 system("pause");
    return 0;

}
