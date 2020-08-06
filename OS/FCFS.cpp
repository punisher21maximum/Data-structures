#include<iostream>
using namespace std;

void disp(int arr[], int n, string msg)
{
    cout<<endl<<msg<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }
}

void atheleteSort(int arr1[], int arr2[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int maxx = arr1[0], maxx_index = 0;
        for(int j=1; j<n-i; j++)
        {
            if(arr1[j]>maxx)
            {
                maxx = arr1[j]; maxx_index = j;
            }
        }
        //maxx_index and n-i-1
        arr1[maxx_index] = arr1[n-i-1];//on max index copy last element
        arr1[n-i-1] = maxx;//put last maxx at last

        int temp2 = arr2[maxx_index];
        arr2[maxx_index] = arr2[n-i-1];
        arr2[n-i-1] = temp2;
    }
}

int maxx(int a, int b)
{
    if(a>b) return a;
    return b;
}

void FCFS(int ATarr[], int BTarr[], int n)
{
    /*
    athelete sort wrt to ATarr
    */
    atheleteSort(ATarr, BTarr, n);
    //set clk
    int clk = 0; 
    //find ST
    int STarr[n];
    for(int i=0; i<n; i++)
    {
        STarr[i] = maxx(clk, ATarr[i]);
        clk += BTarr[i];
    }

    cout<<"AT   BT  ST  CT  WT  TAT\n";
    for(int i=0; i<n; i++)
    {
        cout<<ATarr[i]<<"  "
        <<BTarr[i]<<"  "
        <<STarr[i]<<"  "
        <<STarr[i]+BTarr[i]<<"  "
        <<STarr[i]-ATarr[i]<<"  "
        <<STarr[i]+BTarr[i]-ATarr[i];
        cout<<endl;
    }
}

int main()
{
    int ATarr[] = {0, 3, 6};
    int BTarr[] = {5, 9, 6};
    int n = sizeof(ATarr)/sizeof(ATarr[0]);

    FCFS(ATarr, BTarr, n);

    return 0;
}
/*
1.gantt chart
2.
*/