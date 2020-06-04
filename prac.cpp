#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
};

void display(Node * head)
{
    Node * temp = head;
    cout<<endl;
    while(temp)
    {
        cout<<temp->data; temp = temp->next;
    }
}

void insert(Node ** head, int data, int index)
{
    Node * temp = (*head);

    
}

int main()
{
    Node * head = new Node(); //Node * sec = new Node(); Node * thi = new Node();
    head->data = 1; //sec->data = 2; thi->data = 3;
    head->next = NULL; //sec->next = thi; thi->next = NULL;

    display(head);

    cout<<head->data;

    return 0;
}