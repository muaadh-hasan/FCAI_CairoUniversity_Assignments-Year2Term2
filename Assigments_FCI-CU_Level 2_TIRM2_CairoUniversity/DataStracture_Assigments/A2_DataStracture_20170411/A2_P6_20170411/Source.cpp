#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int binary_Search(int a[],int low, int high , int x)
{

    while(low<high)
    {
    int mid = (low + high)/2;

    if(x == a[mid])
    {
        return mid+1;
    }
    else if(x > a[mid])
    {
        low = mid+1;
    }
    else{
        high = mid-1;
        }
    }

    if (x>a[low])
    {
        return low+1;
    }
    else{
        return low ;
    }

}

void insertion_Sort(int arr[], int n)
{
   int i, key, j;

   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
void modified_insertion_Sort(int arr[], int n)
{
    int idx, j, x;

    for (int i = 1; i < n; ++i)
    {
        j = i - 1;
        x = arr[i];

        idx = binary_Search(arr,0, j , x);

        while (j >= idx)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }

}
int main()
{
    int arr1[100000] , arr2[100000];
    srand(time(0));

    for(int i=0 ; i < 100000 ; i++)
    {
      arr1[i] = rand();
      arr2[i] = arr1[i];
    }

   clock_t startTime = clock();

   insertion_Sort(arr2, 100000);

   clock_t endTime = clock();

   clock_t diff = endTime - startTime;


   double timeInSeconds = (double)diff /   ( CLOCKS_PER_SEC);
   cout <<"Time of insertion Sort is : " <<  timeInSeconds  << endl ;

   startTime = clock();
   modified_insertion_Sort(arr1, 100000);

   endTime = clock();

   diff = endTime - startTime;

   timeInSeconds = (double)diff /   ( CLOCKS_PER_SEC);

   cout <<"Time of modified insertion Sort is : " <<  timeInSeconds  << endl ;

  system("pause");
}
