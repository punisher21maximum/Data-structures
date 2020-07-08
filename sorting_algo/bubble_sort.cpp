#include<iostream>
using namespace std;

void swap(int * p1, int * p2)
{
    int temp = *(p1);
    *(p1) = *(p2);
    *(p2) = temp;
}

void disp(int arr[], int n)
{
    cout<<endl<<"n : "<<n<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }
}

void bubbleSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main()
{
    int arr[] = {5, 1, 8, 12, 6}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    disp(arr, n);
    
    //call sort func
    bubbleSort(arr, n);

    disp(arr, n);

    return 0;
}