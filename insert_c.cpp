#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;	
};

void display(struct Node * head)
{
	struct Node * temp;
	temp = head;
	
	while(temp)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
}

void insert(struct Node ** head, int data)
{
	//temp node
	struct Node * temp = NULL;
	temp=(struct Node *)malloc(sizeof(struct Node));
	//new node 
	struct Node * new_node = NULL;
	new_node=(struct Node *)malloc(sizeof(struct Node));	
	new_node->data = data; new_node->next = NULL;
	
	//reach end
	temp = (*head);
	while(temp->next)//reach last
	{
		temp=temp->next;
	}
	
	temp->next = new_node;
	
		
}

int main()
{
	struct Node * head = NULL;
	struct Node * second = NULL;
	struct Node * third = NULL;
		
	head = (struct Node *)malloc(sizeof(struct Node));
	second = (struct Node *)malloc(sizeof(struct Node));
	third = (struct Node *)malloc(sizeof(struct Node));
	
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next = NULL;
	
	insert(&head, 4);
	insert(&head, 5);
	display(head);
	
	return 0;
}
