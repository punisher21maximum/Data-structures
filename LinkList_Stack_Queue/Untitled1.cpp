#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
};

void display(Node * head)
{  
    if(head==NULL) cout<<"empty list\n";
    else cout<<head->data<<" ";

    Node * temp = head->next;

    while(temp!=head)
    {
        cout<<temp->data<<" "; temp=temp->next;
    }
    cout<<endl;
}

void insert_sll(Node ** head, int data, int index)
{
    Node * temp = new Node();
    Node * new_node = new Node();
    new_node->data = data; new_node->next=NULL;

    if (index==0)
    {
        if((*head)==NULL)
        {
            (*head) = new_node;
        }
        else
        {
            new_node->next = (*head)->next;
            (*head)->next = new_node;
        }
    }
    else if(index==-1)
    {
        if((*head)==NULL)
        {
            (*head) = new_node;
        }
        else
        {
            temp = (*head);
            while(temp->next != (*head))
            {
                temp=temp->next;
            }
            temp->next = new_node;
            new_node->next = (*head);
        }        
    }
    else if(index>0)
    {
        temp = (*head);
        for(int i=0; i<index-1; i++)
        {
            if(temp->next!=(*head))
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
    for(int i=1; i<=10; i++)
    {
        insert_sll(&head, i, -1);
    }
    // insert_sll()
    display(head);

    return 0;
}
