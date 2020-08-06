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

void atheleteSort(int arr1[], int arr2[], int arr3[], int arr4[], int n)
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

        temp2 = arr3[maxx_index];
        arr3[maxx_index] = arr3[n-i-1];
        arr3[n-i-1] = temp2;

        temp2 = arr4[maxx_index];
        arr4[maxx_index] = arr4[n-i-1];
        arr4[n-i-1] = temp2;
    }
}

void  findOrder(int PriorityArr[], int ATarr[], int BTarr[], int DoneOrderArr[], int n)
{
    int clk=0, max_priority, max_priority_process=-1, done_P=1;
    
    while(done_P!=n+1)
    {
        cout<<"\n--\n";
        max_priority = 100; 
        for(int i=0; i<n; i++)
        {
            cout<<"P : "<<i<<endl;
            if(ATarr[i] <= clk and DoneOrderArr[i] == 0)
            {
                cout<<"AT not done P : "<<i<<endl;
                if(PriorityArr[i]<max_priority)//max priority
                {
                    cout<<"Priority P : "<<i<<endl;
                    cout<<"max_P max_P_i "<<max_priority<<" "<<max_priority_process<<endl;
                    max_priority = PriorityArr[i]; max_priority_process = i;
                    cout<<"max_P max_P_i "<<max_priority<<" "<<max_priority_process<<endl;
                }
                else if(PriorityArr[i]==max_priority)
                {
                    if(ATarr[i]<ATarr[max_priority_process])//AT
                    {
                        max_priority_process = i;
                    }
                    else if(ATarr[i]==ATarr[max_priority_process])//process ID
                    {
                        if(i<max_priority_process)
                            max_priority_process = i;
                    }
                }
            }
        }
        cout<<"\n ************ \nmax_P max_P_i "<<max_priority<<" "<<max_priority_process<<endl;
        if(max_priority == -1)
        {
            clk+=1;
            cout<<"\nClk "<<clk;
        }
        else
        {
            DoneOrderArr[max_priority_process] = done_P;
            done_P++;
            clk+=BTarr[max_priority_process];
            cout<<"\nClk done_P"<<clk<<" "<<done_P;
            disp(DoneOrderArr, n, "DoneOrder");
        }
        disp(DoneOrderArr, n, "DoneOrder");
    }
    disp(DoneOrderArr, n, "DoneOrder");
    // atheleteSort(DoneOrderArr, ATarr, BTarr, n);
}

int maxx(int a, int b)
{
    if(a>b) return a;
    return b;
}

void findST(int STarr[], int ATarr[], int BTarr[], int n)
{
    int clk = 0; 

    for(int i=0; i<n; i++)
    {
        STarr[i] = maxx(clk, ATarr[i]);
        clk += BTarr[i];
    }
}

void PriorityFunc(int PriorityArr[], int ATarr[], int BTarr[], int n)
{
    /*
    athelete sort wrt to ATarr
    */
    int DoneOrderArr[n]; for(int i=0; i<n; i++) DoneOrderArr[i] = 0;
    findOrder(PriorityArr, ATarr, BTarr, DoneOrderArr, n);
    atheleteSort(DoneOrderArr, PriorityArr, ATarr, BTarr, n);
    int STarr[n]; 
    findST(STarr, ATarr, BTarr, n);


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
    int PriorityArr[] = { 2, 1, 4, 3 };
    int ATarr[] = { 0, 0, 0, 0 };
    int BTarr[] = { 21, 3, 6, 2 }; 

    int n = sizeof(ATarr)/sizeof(ATarr[0]);

    PriorityFunc(PriorityArr, ATarr, BTarr, n);

    return 0;
}
/*
1.find order
2.athelete sort by order
3.ST and WT, TAT, CT
*/