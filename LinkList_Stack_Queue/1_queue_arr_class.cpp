#include<iostream>
#include<stdio.h> 
#include<stdlib.h> 
using namespace std;
#define MAX 10              
/*
1]array
    1]struct
    2]class
1]link list
    1]struct
    2]class

*/
//array : class
class Queue{
    int front, rear;
public:
    int queue_arr[MAX];//the stack

    Queue() { front  = -1; rear = -1; }

    bool isFullQ();
    bool isEmptyQ();
    void enqueue(int data);
    int dequeue();
    void display();
};
bool Queue :: isEmptyQ()
{
    if(front==-1)
    {
        cout<<"\nQueue : Empty";
        return true;
    } 
    return false;
}
bool Queue :: isFullQ()
{
    if ( rear == (MAX-1) )
    {
        cout<<"\nQueue : Full";
        return true;
    }
    return false;
}
void Queue :: enqueue(int data)
{
    if( isFullQ() == false )
    {
        if( isEmptyQ() == true )
        {
            front = 0;
        }
        queue_arr[++rear] = data;
    }
}
int Queue :: dequeue()
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
void Queue :: display()
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

int main()
{
    Queue my_queue;

    for(int i=0; i<4; i++)
        my_queue.enqueue(i);

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
                my_queue.enqueue(data);
                cout<<"\nCont_add(1) Stop_add(0) : ";cin>>cont_add;
            }
        }
        else if(menu==2) my_queue.dequeue();
        else if(menu==3) my_queue.display();
        else if(menu==4) cont=0;
        else cout<<"\nBad menu choice";  
    }

    return 0;
}



