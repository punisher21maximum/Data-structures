#include<iostream>
#include<stdio.h> 
#include<stdlib.h> 
using namespace std;
#define MAX 10              

int front = -1, rear = -1;
int queue_arr[MAX]; 
 
bool  isEmptyQ()
{
    if(front==-1)
    {
        cout<<"\nQueue : Empty";
        return true;
    } 
    return false;
}
bool  isFullQ()
{
    if ( rear == (MAX-1) )
    {
        cout<<"\nQueue : Full";
        return true;
    }
    return false;
}
void  display()
{
    if( isEmptyQ() == false )
    {
        cout<<"\nQueue Data : ";
        for(int i=front; i<=rear; i++)
        {
            cout<<queue_arr[i]<<" ";
        }
    }
}
void  enqueue(int data)
{
    if( isFullQ() == false )
    {
        if( isEmptyQ() == true )
        {
            front = 0;
        }
        queue_arr[++rear] = data;
        display();
    }
}
int dequeue()
{
    int del_data = -1;
    if( isEmptyQ() == false )
    {
        del_data = queue_arr[front];
        if( front == rear )
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        display();
    }
    return del_data;
}
int main()
{

    for(int i=0; i<4; i++)
        enqueue(i);

    int menu, cont=1;

    while(cont)
    {
        cout<<"\n1.add 2.del 3.display 4.STOP : "; cin>>menu;
        if(menu==1) 
        {
            int cont_add=1;
            while(cont_add)
            {
                cout<<"\nEnter Data : "; int data; cin>>data; 
                enqueue(data);
                cout<<"\nCont_add(1) Stop_add(0) : ";cin>>cont_add;
            }
        }
        else if(menu==2) dequeue();
        else if(menu==3) display();
        else if(menu==4) cont=0;
        else cout<<"\nBad menu choice";  
    }

    return 0;
}



