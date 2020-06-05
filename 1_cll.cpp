#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
};

void display(Node * head)
{  
    if(head==NULL)
    {
        cout<<"Empty list\n";
    }
    else if(head->next==NULL)
    {
        cout<<head->data;
    }
    else
    {
        Node * temp = head;
        while(temp->next!=head)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data<<" ";
    }
    // else
    // {
    //     cout<<"disp else list\n";
    // }
    
}

void insert_sll(Node ** head, int data, int index)
{
    Node * temp = (*head);
    Node * new_node = new Node();
    new_node->data = data; new_node->next=NULL;

    if (index==0 or index==-1)
    {
        if((*head)==NULL)
        {
            (*head) = new_node;  (*head)->next=NULL;
        }
        else if((*head)->next==NULL)
        {
            (*head)->next = new_node;
            new_node->next = (*head);
            if(index==0)
            {
                (*head) = new_node;
            }  
        }
        else
        {       
            temp = (*head);
            while(temp->next != (*head))
            {
                temp=temp->next;
            }
            //temp is last
            temp->next = new_node;
            new_node->next = (*head);
            if(index==0)
            {
                (*head) = new_node;
            }    
        }
    }
    else if(index>0)
    {
        temp = (*head);
        for(int i=0; i<index-1; i++)
        {
            if(temp->next != (*head))
            {
                temp = temp->next;
            }
            else
            {
                cout<<"Index out of range\n";
                break;
            }
        }
        new_node->next = temp->next;
        temp->next = new_node->next;
    }
    else cout<<"enter insert index greater >= -1";
    
}

int main()
{
    // Node * head = new Node; Node * sec = new Node; Node * thi = new Node; 
    // head->data = 1; sec->data = 2; thi->data = 3;
    // head->next = sec; sec->next = thi; thi->next = head;
    
    Node * head = NULL;
    // for(int i=1; i<=10; i++)
    // {
    //     insert_sll(&head, i, 0);
    //     // display(head);
    // }
    for(int i=1; i<=10; i++)
    {
        insert_sll(&head, i, -1);
        // display(head);
    }
    // for(int i=1; i<=10; i++)
    // {
    //     insert_sll(&head, i+10, i);
    //     // display(head);
    // }
    insert_sll(&head, 100, 4);
    display(head);

    return 0;
}