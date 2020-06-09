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
            if(index==0) (*head) = new_node;
               
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
            if(index==0) (*head) = new_node;
                 
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
        temp->next = new_node;
    }
    else cout<<"enter insert index greater >= -1";
    
}

void updateByIndex(Node ** head, int data, int index)
{
    Node * temp = (*head);
    Node * new_node = new Node();
    new_node->data = data; new_node->next=NULL;

    if (index==0 or index==-1)
    {
        if((*head)==NULL)
        {
            cout<<"Empty list : Cant update\n";
        }
        else if((*head)->next==NULL or index==0)
        {
            (*head)->data = data;  
        }
        else
        {       
            temp = (*head);
            while(temp->next != (*head))
            {
                temp=temp->next;
            }
            //temp is last
            temp->data = data;  
        }
    }
    else if(index>0)
    {
        temp = (*head);
        for(int i=0; i<index; i++)
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
        temp->data = data;
    }
    else cout<<"enter insert index greater >= -1";
    
}

void deleteByIndex(Node ** head, int index)
{
    Node * temp = (*head);

    if (index==0 or index==-1)
    {
        if((*head)==NULL)
        {
            cout<<"Empty list : Cant update\n";
        }
        else if((*head)->next==NULL)
        {
            (*head) = NULL; 
        }
        else
        {       
            temp = (*head);
            while(temp->next->next != (*head))
            {
                temp=temp->next;
            }
            //temp is second last
            if(index==-1)  temp->next = temp->next->next; 
            else if(index==0)
            {
                temp=temp->next;
                //temp is last now
                (*head)=(*head)->next;
                temp->next = (*head); 
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
        //temp->next is to deleted
        if(temp->next == (*head)) 
        {
            cout<<"Del Index 1 more than length of list\n";
        }
        else
        {
            temp->next = temp->next->next;
        }
    }
    else cout<<"enter insert index greater >= -1";
    
}

void deleteByValue(Node ** head, int value)
{
    Node * temp = (*head);
    
    if((*head)==NULL) cout<<"Empty list : cant del\n";//empty
    else if((*head) and (*head)->data == value)//del head
    {
        if((*head)->next==NULL) (*head)=NULL;//1 item
        else//>1 item
        {
            temp = (*head);
            while(temp->next!=(*head))
                temp=temp->next;
            (*head) = (*head)->next;
            temp->next = (*head);
        }
    }
    else
    {
        if((*head)->next==NULL)  
        {
            cout<<"index out of range : cant del\n";
        }
        else
        {
            temp = (*head);
            while(temp->next!=(*head))
            {
                if(temp->next->data==value)
                {
                    temp->next = temp->next->next;
                    return;
                }
                temp=temp->next;   
            } 
            cout<<"index out of range : cant del\n";
        }
    }

}

int countNodes(Node * head)
{
    Node * temp = head;
    int count;

    cout<<endl;
    while(temp and temp->next and temp->next!=head)
    {
        temp = temp->next;
        count++;
    }

    cout<<"Count "<<count<<endl;
    return count;
}

int main()
{
    // Node * head = new Node; Node * sec = new Node; Node * thi = new Node; 
    // head->data = 1; sec->data = 2; thi->data = 3;
    // head->next = sec; sec->next = thi; thi->next = head;
    
    Node * head = NULL;
    for(int i=1; i<=1; i++)
    {
        insert_sll(&head, i, -1);
    }
    display(head);
    countNodes(head);
    return 0;
}