#include<iostream>
using namespace std;            

struct StackNode
{
    int data;
    StackNode * next;
};
StackNode * createNewNode(int data)
{
    StackNode * newNode = new StackNode();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
bool is_empty2(StackNode * root)
{
    if(root == NULL)
    {
        cout<<"\nStack Empty : Failed"<<endl;
        return true;
    }
    return false;
}
void  push(StackNode ** root, int data)
{
    StackNode * newNode = createNewNode(data);
    newNode->next = (*root);
    (*root) = newNode;
    cout<<"Pushed : "<<data<<endl;
}
int  pop(StackNode ** root)
{
    if( is_empty2((*root)) == false )
    {
        int popped = (*root)->data;
        cout<<"Popped : "<<popped;
        (*root) = (*root)->next;
        return popped;
    }
    return -1;
}
void  peek(StackNode * root)
{
    if( is_empty2((root)) == false )
    {
        cout<<"Peek : "<<root->data;
    }
}
void  display(StackNode * root)
{
    if( is_empty2(root) == false )
    {
        StackNode * temp = root;
        while(temp)
        {
            cout<<"Data : "<<temp->data<<endl;
            temp = temp->next;
        }
    }
}
int main()
{
    StackNode * my_stack = NULL;
    display(my_stack);
    for(int i=0; i<5; i++)
    {
        push(&my_stack, i);
    }

    display(my_stack);
    peek(my_stack);

    return 0;
}



















































