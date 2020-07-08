#include<iostream>
using namespace std;

void disp(int arr[], int n)
{
    cout<<endl<<"n : "<<n<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<"  ";
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m-l+1, n2 = r-m;
    int left[n1], right[n2];

    for(int i=0; i<n1; i++)
        left[i] = arr[l+i];

    for(int j=0; j<n2; j++)
        right[j] = arr[m+1+j]; 

    int i=0, j=0, k=l;

    while(i<n1 and j<n2)
    {
        if(left[i]<=right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while(i<n1)
        arr[k++] = left[i++];

    while(j<n2)
        arr[k++] = right[j++];

}

void mergeSort(int arr[], int l, int r)
{
    if (r <= l) return;
    //find mid
    int m = l + (r-l)/2;
    //split 
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    //merge
    merge(arr, l, m, r);
}

int main()
{
    int arr[] = {3, 7, -1, 67, -12, 45, 3, 77};
    int n = sizeof(arr)/sizeof(arr[0]);
    disp(arr, n);
    //call sort func
    mergeSort(arr, 0, n-1);
    disp(arr, n);

    return 0;
}