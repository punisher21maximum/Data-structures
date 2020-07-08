#include<iostream>
using namespace std;

class Qnode
{
public: 
    int data;
    Qnode * next;
    Qnode(int d)
    {
        data = d; next = NULL;
    }
};
bool isEmpty(Qnode * front)
{
    if(front == NULL)
    {
        cout<<"\nEmpty List"; return true;
    } 
    return false;
}
void display(Qnode * front)
{
    if( isEmpty(front) == false )
    {
        Qnode * temp = front;
        cout<<"\nData : ";
        while(temp)
        {
            cout<<temp->data<<" "; temp = temp->next;
        }
    }
}
void enqueue(Qnode ** front, Qnode ** rear, int data)
{
    Qnode * new_node = new Qnode(data);

    if( isEmpty(*front) )
    {
        (*front) = (*rear) = new_node;
    }
    else
    {
        (*rear)->next = new_node;
        (*rear) = new_node;
    }
    cout<<"Added: "<<(*rear)->data<<endl;
}
int dequeue(Qnode ** front, Qnode ** rear)
{
    if( isEmpty(*front)==false )
    {
        Qnode * temp = (*front);
        int del_data = (*front)->data;
        cout<<"\nDeleted : "<<del_data;
        if((*front)==(*rear))
            (*front) = (*rear) = NULL;
        else 
            (*front) = (*front)->next; 
        display(*front);
        free(temp);
        return del_data;
    }    
    return -1;
}
int peekqueue(Qnode ** front)
{
    if( isEmpty(*front)==false )
    {
        cout<<"\nPeeked : "<<(*front)->data;
        display(*front);
        return (*front)->data;
    }    
    return -1;
}
int main()
{
    Qnode * front = NULL;
    Qnode * rear = NULL;

    for(int i=0; i<8; i++)
        enqueue(&front, &rear, i);
    cout<<"\nFront : "<<front->data<<" rear : "<<rear->data;
    display(front);

    for(int i=0; i<4; i++)
        dequeue(&front, &rear);
    cout<<"\nFront : "<<front->data<<" rear : "<<rear->data;
    display(front);

    return 0;
}



















