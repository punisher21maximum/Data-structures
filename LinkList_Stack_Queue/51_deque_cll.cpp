#include<iostream>
using namespace std;
/*
pointers
1.linear Q
2.circular Q
3.
*/
//deque - double ended queue - require dll
class  Dqnode
{
public:
    int data;
    Dqnode * next; 
    Dqnode * prev;
    Dqnode(int d){ data=d; next=NULL; prev=NULL; }
};
class Deque
{
public:
    Dqnode * front; Dqnode * rear;
    Deque(){ front=NULL; rear=NULL; }

    bool isEmpty();
    void display();
    void insertFront(int data);
    void insertRear(int data);
    void delFront();
    void delRear();
};
bool Deque :: isEmpty()
{
    if(front==NULL)
    {
        cout<<"\nEmpty Queue"; return true;
    }
    return false;
}
void Deque :: display()
{
    if( not isEmpty() )
    {
        Dqnode * temp = front;
        cout<<"\nData : ";
        while(temp!=rear)
        {
            cout<<" "<<temp->data; temp= temp->next;
        }
        if(rear) cout<<" "<<rear->data;
    }    
}
void Deque :: insertFront(int data)
{
    Dqnode * new_node = new Dqnode(data);
    new_node->next = NULL; new_node->prev = NULL;

    if( isEmpty() )
    {
        front = rear = new_node;
    }
    else
    {
        if(rear==NULL)
        {
            rear->prev = new_node;
        }
        new_node->next = front;
        front->prev = new_node;
        front = new_node;
    }
}
void Deque :: insertRear(int data)
{
    Dqnode * new_node = new Dqnode(data);
    new_node->next = NULL; new_node->prev = NULL;

    if( isEmpty() )
    {
        front = rear = new_node;
    }
    else
    {
        if(front==NULL)
        {
            front->next = new_node;
        }
        rear->next = new_node;
        new_node->prev = rear;
        rear = new_node;
    }
}
void Deque :: delFront()
{
    if( not isEmpty() )
    {
        int data = front->data;
        if(front == rear)
        {
            front = rear = NULL;
        }
        front = front->next;
        front->prev = NULL;
        cout<<"\nDeleted : front : "<<data;
    }
}
void Deque :: delRear()
{
    if( not isEmpty() )
    {
        int data = rear->data;
        if(front == rear)
        {
            front = rear = NULL;
        }
        rear = rear->prev;
        rear->next = NULL;
        cout<<"\nDeleted : rear : "<<data;
    }
}
int main()
{
    Deque deque;
    for(int i=0; i<5; i++)
        deque.insertFront(i);
    for(int i=12; i<16; i++)
        deque.insertRear(i);
    deque.display();
    int menu, cont=1;
    while(cont)
    {
        cout<<"\n1.addFront 2.addRear 3.delFront 4.delRear 5.Disp 6.STOP : ";
        cin>>menu;
        if(menu==1 or menu==2)
        {
            cout<<"\nEnter Data : "; int data; cin>>data;
            if(menu==1) deque.insertFront(data);
            else deque.insertRear(data);
        }
        else if(menu==3) deque.delFront();
        else if(menu==4) deque.delRear();
        else if(menu==5) deque.display();
        else if(menu==6) cont=0;
        else cout<<"\nBad menu choice";
    }

    return 0;
}
