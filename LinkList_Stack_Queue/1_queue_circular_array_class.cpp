#include<iostream>
using namespace std;
#define MAX 5             
class CQueue{
    int front, rear;
public:
    int cqueue[MAX];//the stack

    CQueue() { front  = -1; rear = -1; }

    bool isFullQ();
    bool isEmptyQ();
    void enqueue(int data);
    int dequeue();
    void display();
};
bool CQueue :: isEmptyQ()
{
    if(front==-1 and rear==-1)
    {
        cout<<"\nQueue : Empty";
        return true;
    } 
    return false;
}
bool CQueue :: isFullQ()
{
    if ( (front==0 and rear==(MAX-1) ) or (rear==front-1) )
    {
        cout<<"\nQueue : Full";
        return true;
    }
    return false;
}
void CQueue :: enqueue(int data)
{
    if( isFullQ() == false )
    {
        if( isEmptyQ() == true )
        {
            front = 0;  
        }
        else if( rear==(MAX-1) )
        {
            rear = -1; 
        }
        cqueue[++rear] = data;
        display();
    }
}
int CQueue :: dequeue()
{
    int del_data = -1;
    if( isEmptyQ() == false )
    {
        del_data = cqueue[front];
        if( front == rear )
        {
            front = rear = -1;
        }
        else
        {
            if( front == (MAX-1) )
                front = -1;
            front++;
        }
        display();
    }
    return del_data;
}
void CQueue :: display()
{
    cout<<"\nFront : "<<front<<" Rear : "<<rear;
    if( isEmptyQ() == false )
    {
        cout<<"\nQueue Data : ";
        if( rear>=front )
        {
            for(int i=front; i<=rear; i++)
            {
                cout<<cqueue[i]<<"> ";
            }
        }
        else
        {
            for(int i=front; i<MAX; i++)
            {
                cout<<cqueue[i]<<"- ";
            }
            for(int i=0; i<=rear; i++)
            {
                cout<<cqueue[i]<<"< ";
            }
        }
        
        
    }
}

int main()
{
    CQueue my_queue;

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



