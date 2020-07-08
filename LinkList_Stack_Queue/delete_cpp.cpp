#include<iostream>
#include <cstdlib>
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

void del(struct Node ** head, int del_index)
{
	//temp
	Node * temp = new Node();
	
	if((*head)==NULL)
	{
		printf("\nList empty");
	}
	else if(del_index==0)
	{
		temp = (*head);
		(*head) = (*head)->next;
		free(temp);
	}
	else if(del_index==-1)
	{
		temp=(*head);
		while(temp->next->next)
			temp = temp->next;
		free(temp->next);
		temp->next = NULL;
	}
	else if(del_index>0)
	{
		temp = (*head);
		for(int i=0; i<del_index-1; i++)
		{
			if(temp->next)
				temp = temp->next;
			else
			{
				printf("Index out of range, List size : %d", i+1);
				break;
			}
		}
		if (temp->next == NULL)
		{
			printf("Index 1 greater than list size.");
		}
		else  
		{
			if(temp->next->next)
			{
				temp->next = temp->next->next;
			}
			else
			{
				temp->next = NULL;
			}
		}
	}
	else
		printf("Enter index greate than -1");
}

void del_by_val(struct Node ** head, int data)
{
	Node * temp = new Node();
	
	if((*head)==NULL)
	{
		printf("\nList empty");
	}
	else if((*head)->data == data)
	{
		temp = (*head);
		(*head) = (*head)->next;
		free(temp);
	}	
	else
	{
		temp = (*head);
		while(temp->next)
		{
			if(temp->next->data == data)
			{
				temp->next = temp->next->next;
				printf("\nDeleted : %d from list", data);
				return;
			}
			temp = temp->next;
		}
		printf("\nDeleted nothing, data not found!");
	}
	
}

void del_list(struct Node ** head)
{
	Node * temp = (*head);
	Node * next_node;
	
	while(temp)
	{
		next_node = temp->next;
		free(temp);
		temp = next_node;
	}
	
	*head = NULL;
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
	
//	for(int i=0; i<10; i++)
//	{
//		insert(&head, i, -1);
//	}
//	for(int i=0; i<10; i++)
//	{
//		insert(&head, i+100, 0);
//	}
//	for(int i=0; i<10; i++)
//	{
//		insert(&head, i+200, i);
//	}
	display(head);
	printf("\n");
//	del(&head, 1);
	del_by_val(&head, 4);
	display(head);
	return 0;
}
