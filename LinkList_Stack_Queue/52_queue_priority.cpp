#include<iostream>
using namespace std;
//sll
class Pnode
{
public: 
    int data, prty;
    Pnode * next;
    Pnode(int d, int p)
    {
        data = d; prty = p; next = NULL;
    }
};
bool isEmpty(Pnode * front)
{
    if(front == NULL)
    {
        cout<<"\nEmpty List"; return true;
    } 
    return false;
}
void display(Pnode * front)
{
    if( isEmpty(front) == false )
    {
        Pnode * temp = front;
        cout<<"\nData : ";
        while(temp)
        {
            cout<<temp->data<<" "; temp = temp->next;
        }
    }
}
void enqueue(Pnode ** front, Pnode ** rear, int data, int prty)
{
    Pnode * new_node = new Pnode(data, prty);

    if( isEmpty(*front) )
    {
        (*front) = (*rear) = new_node;
    }
    else
    {
        Pnode * temp = (*front);
        if(new_node->prty <= (*front)->prty)
        {
            new_node->next = (*front); (*front) = new_node;
        }
        while(temp and temp->next and new_node->prty <= temp->next->prty)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;               
    }
    cout<<"Added: "<<(*rear)->data<<endl;
}
int dequeue(Pnode ** front, Pnode ** rear)
{
    if( isEmpty(*front)==false )
    {
        Pnode * temp = (*front);
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
int peekqueue(Pnode ** front)
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
    Pnode * front = NULL;
    Pnode * rear = NULL;

    for(int i=0; i<8; i++)
        enqueue(&front, &rear, i, i+2);
    cout<<"\nFront : "<<front->data<<" rear : "<<rear->data;
    display(front);

    for(int i=0; i<4; i++)
        dequeue(&front, &rear);
    cout<<"\nFront : "<<front->data<<" rear : "<<rear->data;
    display(front);

    return 0;
}



















