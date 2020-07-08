#include<iostream>
using namespace std;


int main()
{
    int n, m;  
    n = 5; // Number of processes 
    m = 3; // Number of resources 
    int allocArr[5][3] = { { 0, 1, 0 }, // P0    // Allocation Matrix 
                        { 2, 0, 0 }, // P1 
                        { 3, 0, 2 }, // P2 
                        { 2, 1, 1 }, // P3 
                        { 0, 0, 2 } }; // P4 
  
    int maxArr[5][3] = { { 7, 5, 3 }, // P0    // MAX Matrix 
                      { 3, 2, 2 }, // P1 
                      { 9, 0, 2 }, // P2 
                      { 2, 2, 2 }, // P3 
                      { 4, 3, 3 } }; // P4 

    int avai[3] = { 3, 3, 2 }; // Available Resources 

    int needArr[5][3];
    cout<<"Need Arr"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            needArr[i][j] = maxArr[i][j] - allocArr[i][j];
            cout<<needArr[i][j]<<" ";
        }
        cout<<endl;
    }
    //
    int pdone=0, pdoneArr[n];
    for(int j=0; j<n; j++)  pdoneArr[j] = -1;
    while(pdone!=n)
    {
        for(int i=0; i<n; i++)//for each P
        {
            //if P not done
            if(pdoneArr[i]==-1)
            {
                //check if R avai
                bool is_avai=true;
                for(int j=0; j<m; j++)
                {
                    if(needArr[i][j]>avai[j])
                    {
                        is_avai = false; break;
                    }
                }
                //
                if(is_avai)
                {
                    //execute the process
                    //and then give all R to A
                    //alloc to avai
                    for(int j=0; j<m; j++)
                    {
                        avai[j] += allocArr[i][j];
                    }
                    //mark P as done
                    pdoneArr[i] = 1;
                    pdone++;

                    cout<<"P"<<i<<" ";
                }
            }
        }
    }

    return 0;
}