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
	printf("\n");
	while(temp)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
}

void insert(struct Node ** head, int data, int insert_index)
{
	//temp node
	struct Node * temp = NULL;
	temp=(struct Node *)malloc(sizeof(struct Node));
	//new node 
	struct Node * new_node = NULL;
	new_node=(struct Node *)malloc(sizeof(struct Node));	
	new_node->data = data; new_node->next = NULL;
	

	//at start : index == 0
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
			temp=(*head);
			while(temp->next)
			{
				temp=temp->next;
			}	
			temp->next=new_node;
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

		
}

void del_by_index(struct Node ** head, int del_index)
{
	//temp
	struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
	
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
 

 

int main()
{
//	struct Node * head = NULL;
//	struct Node * second = NULL;
//	struct Node * third = NULL;
		
//	head = (struct Node *)malloc(sizeof(struct Node));
//	second = (struct Node *)malloc(sizeof(struct Node));
//	third = (struct Node *)malloc(sizeof(struct Node));
	
//	head->data = 1;
//	head->next = second;
//	
//	second->data = 2;
//	second->next = third;
//	
//	third->data = 3;
//	third->next = NULL;

	struct Node * head = NULL;
	display(head);
	
	for(int i=0; i<10; i++)
	{
		insert(&head, i, -1);
	}
//	display(head);
//	del(&head, 0);
//	display(head);
//	del(&head, 0);
//	display(head);
//	del(&head, 0);
//	display(head);
//	del(&head, -1);
//	del(&head, 3);
	display(head);
	del_by_index(&head, 0);
	del_by_val(&head, 5);
	display(head);
 
	
	return 0;
}
