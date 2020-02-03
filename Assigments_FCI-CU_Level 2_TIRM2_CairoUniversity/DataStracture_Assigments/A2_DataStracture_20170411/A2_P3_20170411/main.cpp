#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Searcher
{
private:
    vector<string> data;
    vector<string> data2;

public:
    Searcher(){
        ifstream File ("wordlist.txt");
        string X;

        for(int i=0;i<90000;i++){
            File >> X;
            data2.push_back(X);
        }

        File.close();
    }

    //Loads required num of words from file
    void LoadData(string FileName, int size)
    {
        ifstream File(FileName.c_str());
        string s;
        data.clear();

        for (int i=0 ; i < size ; i++)
        {
            File >> s;
            data.push_back(s);
        }
        File.close();
    }

    // Looks for a given item in the data & return its index or -1
    int binarySearch(string word, int &c)
    {
        int low = 0, high = data.size()-1;
        while(low<high)
        {
            int mid = (low + high)/2;

            if(word.compare(data[mid])==0)
                return mid+1;
            else if(word.compare(data[mid])>0)
                low = mid+1;
            else
                high = mid-1;

            c++;
        }

        return -1;
    }
    // Gets time & num of comparisons
    void testPerformance(double & time, int & NoOfCompare, int n)
    {
        int idx = rand() % n;
        string word = data[idx];
        int x = binarySearch(word,NoOfCompare);

        clock_t Start_t = clock();
        clock_t End_t = clock();
        time += ((double)(End_t-Start_t)/(CLOCKS_PER_SEC));
    }

    void testPerformance2(double & time, int & NoOfCompare, int n, int n2)
    {
        int idx = (rand() % (n2-n)) + n2;
        string word = data2[idx];
        int x = binarySearch(word,NoOfCompare);

        clock_t Start_t = clock();
        clock_t End_t = clock();
        time += ((double)(End_t-Start_t)/(CLOCKS_PER_SEC));
    }

};



int main()
{
    double  AverageTime = 0.0, AvgNumOfComp = 0.0;

    int i = 10000;

    cout << " Found Item Analysis " << endl ;
    while (i<=80000)
    {

        Searcher s;
        string fileName = "wordlist.txt";
        s.LoadData(fileName, i);
        srand(time(0));
        cout << i <<  "number of words "<< endl;
        for(int j =0 ; j < 100 ; j++)
        {
            double T=0.0;
            int NoComp=0;
            s.testPerformance(T,NoComp,i);
            AvgNumOfComp += NoComp;
            AverageTime +=T;
        }

        i+=10000;
        cout << "Average Time: " << AverageTime  <<endl;
        cout << "Average number of comparison: " << AvgNumOfComp/100 << endl ;

    }

    cout <<"_________________________________________________" << endl ;

    AverageTime = 0.0;
    AvgNumOfComp = 0.0;
    i = 10000;
    for(int i=10000;i<=80000;i+=10000)
    {

        Searcher s;
        string fileName = "wordlist.txt";
        s.LoadData(fileName, i);
        srand(time(0));

        cout << i <<  " number of words "<< endl;
        for(int j =0 ; j < 100 ; j++)
        {
            double T=0.0;
            int NoComp=0;
            s.testPerformance2(T,NoComp,i+1,i+10000);
            AvgNumOfComp += NoComp;
            AverageTime +=T;
        }

        cout << "Average Time: " << AverageTime  <<endl;
        cout << "Average number of comparison: " << AvgNumOfComp/100 << endl;
    }
    return 0;
}
