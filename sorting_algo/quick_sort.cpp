#include<iostream>
using namespace std;

void disp(int arr[], int n)
{
    cout<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<"  ";
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];

    int index=l;
    for(int i=l; i<r; i++)
    {
        if(arr[i]<pivot)
        {
            int temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
            index++;
        }
    }
    arr[r] = arr[index];
    arr[index] = pivot;
    return index;
}

void quickSort(int arr[], int l, int r)
{
    if(l>=r) return;
    int partition_index = partition(arr, l, r);
    quickSort(arr, l, partition_index-1);
    quickSort(arr, partition_index+1, r);
}

int main()
{
    int arr[] = {6, 23, 1, 34, -12, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    disp(arr, n);
    //call sort func 
    quickSort(arr, 0, n-1);
    disp(arr, n);

    return 0;
}