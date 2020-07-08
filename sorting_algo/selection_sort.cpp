#include<iostream>
using namespace std;

void disp(int arr[], int n)
{
    cout<<endl<<"n : "<<n<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<"  ";
}

void selectionSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int maxx = arr[0], maxx_index = 0;
        for(int j=1; j<n-i; j++)
        {
            if(arr[j]>maxx)
            {
                maxx = arr[j]; maxx_index = j;
            }
        }
        arr[maxx_index] = arr[n-i-1];//on max index copy last element
        arr[n-i-1] = maxx;//put last maxx at last
    }
}

int main()
{
    int arr[] = {3, 6, 8, 11, 4, 33};
    int n = sizeof(arr)/sizeof(arr[0]);
    disp(arr, n);

    //call sort func
    selectionSort(arr, n);

    disp(arr, n);

    return 0;
}