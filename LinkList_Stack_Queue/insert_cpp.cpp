#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node * next;
};

void display(Node * head)
{
	Node * temp = new Node();
	
	temp=head;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

void insert(Node ** head, int data, int insert_index)
{
	//temp node
	Node * temp = new Node();
	//new node
	Node * new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	
	if(insert_index==0)
	{
		if( (*head)==NULL )
		{
			(*head) = new_node;
		}
		else
		{
			new_node->next = (*head);
			(*head) = new_node;
		}
	}
	else if(insert_index==-1)
	{
		if( (*head)==NULL )
		{
			(*head) = new_node;
		}
		else
		{
			temp = (*head);
			while(temp->next)
				temp = temp->next;
			temp->next = new_node;
		}		
	}
	else if(insert_index>0)
	{
		temp = (*head);
		
		for(int i=0; i<insert_index-1; i++)
		{
			if(temp->next)
				temp = temp->next;
			else
			{
				printf("\nIndex greate than the list size. list size is : %d", i+1);
				return;
			}
			
		}
		if(temp->next)//if true : temp is not last node
			new_node->next = temp->next;
		else
			new_node->next = NULL;
		temp->next = new_node;
	}
	else
	{
		printf("\nEnter index : greater than -1");
	}
	
}

int main()
{
	Node * head = NULL;
	Node * second = NULL;
	Node * third = NULL;
	
	head = new Node();
	second = new Node();
	third = new Node();
	
	head->data = 1; head->next=second;
	second->data = 2; second->next=third;
	third->data=3; third->next=NULL;
	
	for(int i=0; i<10; i++)
	{
		insert(&head, i, -1);
	}
	for(int i=0; i<10; i++)
	{
		insert(&head, i+100, 0);
	}
	for(int i=0; i<10; i++)
	{
		insert(&head, i+200, i);
	}
	display(head);
	
	return 0;
}
