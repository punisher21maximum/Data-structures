#include<iostream>
using namespace std;
#define MAX 10
//declare stack
int arr[MAX];     
int top = -1; 


bool is_full()
{
    if(top == MAX-1) return true;
    return false;
}
bool is_empty2()
{
    if(top == -1) return true;
    return false;
}
int  push(int data)
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
int pop()
{
    if( is_empty2() )
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
int peek()
{
    if( is_empty2() )
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
void display()
{
    if( is_empty2() )
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

    display();

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
                push(data);
                cout<<"\nCont add(1) Stop add(0) : "; cin>>cont_add; 
            }
        }
        else if(menu==2)  pop();
        else if(menu==3)  peek();
        else if(menu==4)  display();
        else cout<<"\nBad menu entered";

        cout<<"\nCont(1) Stop(0) : "; cin>>cont;
    }
    
    return 0;
}