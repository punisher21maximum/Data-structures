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
class Stack{
    int top;
public:
    int arr[MAX];//the stack

    Stack() { top = -1; }

    bool is_full();
    bool is_empty();
    int push(int data);
    int pop();
    int peek();
    void display();
};
bool Stack :: is_empty()
{
    if(top == -1) return true;
    return false;
}
bool Stack :: is_full()
{
    if(top == MAX-1) return true;
    return false;
}
int Stack :: push(int data)
{
    if( is_full() == true )
    {
        cout<<"Stack is full, data not pushed\n";
        return -1;
    }
    else
    {
        arr[++top] = data;
        cout<<"Data pushed : "<<data<<" top : "<<top<<endl;
        return 1;
    }  
}
int Stack :: pop()
{
    if( is_empty() == true )
    {
        cout<<"Stack is empty, can't pop\n";
        return -1;
    }
    else
    {
        cout<<"Data popped : "<<arr[top]<<" top : "<<top<<endl;
        return arr[top--];   
    }  
}
int Stack :: peek()
{
    if( is_empty() == true )
    {
        cout<<"Stack is empty, can't pop\n";
        return -1;
    }
    else
    {
        cout<<"Data peek : "<<arr[top]<<" top : "<<top<<endl;
        return arr[top];   
    }  
}
void Stack :: display()
{
    if( is_empty() == true )
    {
        cout<<"Stack is empty, can't pop\n";
    }
    else
    {
        cout<<"\nData in stack : ";
        for(int i=0; i<=top; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    
}
int main()
{
    Stack S;
    // for(int i=1;i<=10;i++){  S.push(i);	}
    S.display();

    int menu, cont=1;

    while(cont)
    {
        cout<<"\n1.Push 2.Pop 3.Peek 4.Display : "; cin>>menu;
        if(menu==1)
        {
            int cont_add=1;
            while(cont_add)
            {
                cout<<"\nEnter data : "; int data; cin>>data;
                S.push(data);
                cout<<"\nCont add(1) Stop add(0) : "; cin>>cont_add; 
            }
        }
        else if(menu==2) S.pop();
        else if(menu==3) S.peek();
        else if(menu==4) S.display();
        else cout<<"\nBad menu entered";

        cout<<"\nCont(1) Stop(0) : "; cin>>cont;
    }

    return 0;
}