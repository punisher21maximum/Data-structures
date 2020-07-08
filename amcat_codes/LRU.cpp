#include<iostream>
using namespace std;
void dispFrame(int frame[], int num_of_page_frame)
{
    cout<<"Frame : ";
    for(int j=0; j<num_of_page_frame; j++)
    {
        cout<<frame[j]<<" ";
    }
}

void disp(int curr_page, int hit, int frame[], int lru, int num_of_page_frame)
{
    
    cout<<"Curr page : "<<curr_page<<endl;
    dispFrame(frame, num_of_page_frame);
    cout<<"   lru : "<<frame[lru];
    if(hit==0) cout<<"\nMiss"<<endl;
    else cout<<"\nHit"<<endl;
}

int main()
{
    int num_of_page_frame = 4;  int hit=0, lru=0, faults=0;
    int frame[num_of_page_frame];
    for(int i=0; i<num_of_page_frame; i++) frame[i] = -1;
         
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
    
    for(int i=0; i<(sizeof(pages)/sizeof(pages[i])); i++)
    {
        int curr_page = pages[i]; 
        hit=0;
        //check if in frame
        for(int j=0; j<num_of_page_frame; j++)
        {
            if(frame[j] == curr_page)
            {
                hit = 1; break; cout<<"Hit : "<<curr_page<<endl;
            }
        }
        //if miss
        cout<<endl<<"-------------------------------"<<endl;
        disp(curr_page, hit, frame, lru, num_of_page_frame);
        if(hit == 0)
        {
            frame[lru] = curr_page;
            lru = (lru+1)%num_of_page_frame;
            faults++;
        }
        disp(curr_page, hit, frame, lru, num_of_page_frame);    
    }

    return 0;
}