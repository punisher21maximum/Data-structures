#include<iostream>
using namespace std;

void swap(int * p1, int * p2)
{
    *(p1) = *(p1) + *(p2);
    *(p2) = *(p1) - *(p2);//*(p1) + *(p2) - *(p2) = *(p1)
    *(p1) = *(p1) - *(p2);//*(p1) + *(p2) - *(p1) = *(p2)
}

void disp(int arr[], int n)
{
    cout<<endl<<"n : "<<n<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<"  ";
}

void insertionSort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int j=i-1, item = arr[i];
        while(j>=0 and arr[j]<item)
        {
            arr[j+1] = arr[j]; j--;
        }
        arr[j+1] = item;
    }
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);
    disp(arr, n);

    //call sort func
    insertionSort(arr, n);

    disp(arr, n);    

    return 0;
}