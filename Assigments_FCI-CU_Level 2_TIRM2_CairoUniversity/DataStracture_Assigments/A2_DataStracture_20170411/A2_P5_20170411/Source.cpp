#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 =  right - mid;

    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1+ j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l+r)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int Partition(int A[], int left, int right)
{
	int x = A[left];
	int i = left;
	for (int j = left+1; j<=right ; j++)
    {
        if (A[j] < x )
        {
			i = i + 1 ;
			swap(A[i], A[j]);
        }
    }
	swap(A[i], A[left]);
	return i;
}
void Quick_Sort(int A[], int left,int right)
{
  if (left >= right)
    return;
  else
  {
    int middle = Partition(A, left, right);
    Quick_Sort(A, left, middle-1 );
    Quick_Sort(A, middle+1, right);
  }
}


int main()
{

	cout << "\n       ------------ -------------Welcome to our program (  Gobran & Taqi & Muaath )----------------------------------"<<endl<<endl;

    int size = 5000;

    while (size <=100000)
    {

    int * arr1 = new int [size] , *arr2 = new int [size];
    srand(time(0));

    for(int i=0 ; i < size ; i++)
    {
      arr1[i] = rand();
      arr2[i] = arr1[i];
    }

   clock_t startTime = clock();

   mergeSort(arr2, 0 , size-1);

   clock_t endTime = clock();

   clock_t diff = endTime - startTime;


   double timeInSeconds = (double)diff /   ( CLOCKS_PER_SEC);
   cout <<"Time of " <<size<<" items using merge Sort  is : " <<  timeInSeconds  << endl ;

   startTime = clock();

   Quick_Sort(arr1, 0, size-1);

   endTime = clock();

   diff = endTime - startTime;

   timeInSeconds = (double)diff / ( CLOCKS_PER_SEC);

   cout <<"Time of " <<size<<" items using Quick Sort is : " <<  timeInSeconds  << endl << "-----------------------------"<<endl;

    delete arr1 , arr2;

    size +=5000;
    }
system("pause");
    return 0;
}