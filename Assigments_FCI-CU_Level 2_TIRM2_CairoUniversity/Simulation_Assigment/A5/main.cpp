#include <iostream>
#include <random>
#include <math.h>

using namespace std;
double GetMax(double AT,double CT)
{
    if(AT>CT)
        return AT;
    else
        return CT;
}
double GetMin(double AT,double CT)
{
    if(AT<CT)
        return AT;
    else
        return CT;
}
double arrSum(double a[] ,int s){
   int sum =0 ;
   for (int i=0 ; i<s ; i++) {
    sum+=a[i];
   }
   return sum ;
}
int main()
{
    default_random_engine generator;
    normal_distribution<> IAT(1.5,0.15);
    normal_distribution<> ST(6,1);
    int const max_customer =10000 ;
    double clerks_Salary = 20;
    double number_hours_per_day =10;
    double SystemSpaceAvailTimeArray = 0;
    double ServerAvailTimeArray[max_customer];
    double sales[max_customer];
    double waiting_cost[max_customer];
    double Inter_Arrival_Time[max_customer];
    double Arrival_Time[max_customer];
    double Waiting_Time[max_customer];
    double Service_Time[max_customer];
    double Start_Entrance[max_customer];
    double completion_Time[max_customer];
    double start_service_time[max_customer];
    double systemSpace1AvailTime[max_customer];
    double Profit,Profit1,Profit2;
    for (int j=1; j<3 ; j++)
    {
        for (int i =0; i<max_customer ; i++)
        {
            Inter_Arrival_Time[i] = IAT(generator) ;
            if(i==0)
            {
                Arrival_Time[i] =Inter_Arrival_Time[i];
                completion_Time[i] =0 ;
            }
            else
            {
                Arrival_Time[i] =Arrival_Time[i-1] + Inter_Arrival_Time[i];
            }
            if (Arrival_Time[i] > (10*60)) {
                break ;
            }

            Start_Entrance[i] = GetMax(Arrival_Time[i],SystemSpaceAvailTimeArray);

            if (Arrival_Time[i] < Start_Entrance[i]) {
                 continue;
            }
            sales[i] = 22 ;
            start_service_time[i] = GetMax(Arrival_Time[i],Start_Entrance[i]) ;
            Waiting_Time[i] =start_service_time[i] - Arrival_Time[i] ;
            waiting_cost[i] =Waiting_Time[i]*(10/60) ;
            Service_Time[i] =ST(generator);
            completion_Time[i] = start_service_time[i] + Service_Time[i];
            ServerAvailTimeArray[i] =GetMin(ServerAvailTimeArray[i],completion_Time[i]);
            systemSpace1AvailTime[i]=GetMin(systemSpace1AvailTime[i], completion_Time[i]);
        }
        double f1 = arrSum(sales,max_customer);
        double f2 = arrSum(waiting_cost,max_customer);

         Profit = f1 - f2;
         if (j==1)
            ServerAvailTimeArray = [0,0] ;
            SystemSpaceAvailTimeArray = [0,0,0];
             Profit1 = Profit - 200-(20*3*10);
         else
         ServerAvailTimeArray = [0,0,0,0,0,0] ;
         SystemSpaceAvailTimeArray = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
            Profit2= Profit - 2000-(20*6*10);
    }
    if (Profit1>Profit2){
        cout << "Use The First Configuration" <<endl ;
        cout << "Profit of first Configuration is : " <<  Profit1 << endl ;
        cout << "Profit of Second Configuration is : " <<  Profit2 << endl ;
    }
    else{
        cout << "Use The Second Configuration" << endl ;
        cout << "Profit of first Configuration is : " << Profit1 << endl ;
        cout << "Profit of Second Configuration is : " << Profit2<< endl ;
    }
    return 0;
}
