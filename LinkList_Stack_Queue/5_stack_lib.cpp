// CPP program to demonstrate working of STL stack 
#include <bits/stdc++.h> 
using namespace std; 
void display(stack <int> my_stack)
{
    while(my_stack.empty() == false)
    {
        cout<<"\nData :"<<my_stack.top(); my_stack.pop();
    }
}
int main () 
{ 
	stack <int> my_stack;
	my_stack.push(10); 
	my_stack.push(30); 
	my_stack.push(20); 
	my_stack.push(5); 
	my_stack.push(1); 

	cout<<"\nsize : "<<my_stack.size();
    cout<<"\ntop : "<<my_stack.top();
    my_stack.pop(); 
    cout << "\nempty : "<<my_stack.empty();
    display(my_stack);
	return 0; 
} 
