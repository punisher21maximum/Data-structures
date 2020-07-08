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
//1 
int getLength(struct Node * head)
{
	if (head == NULL)
		return 0;
		
	return 1 + getLength(head->next);
}
//2 
int searchByValueRecur(struct Node * head, int data)
{
	if (head == NULL)
		return -1;
	else if (head->data == data)
		return 1;
	return searchByValueRecur(head->next, data);
}
//3
void searchByIndex(struct Node * head, int search_index)//0 indexing
{
	struct Node * temp = head;
	
	if(search_index<0) 
	{
		printf("\nsearchByIndex Enter index >= 0");
		return;
	}
	
	int count = 0;
	while(temp)
	{
		if(count==search_index)
		{
			printf("\nFound search by index : %d : data %d", 
			search_index, temp->data);
			return;
		}
		count++;
		temp = temp->next;
	}
	
	printf("\nsearchByIndex index out of range");
}
//4
int searchByIndexRecur(struct Node * node, int search_index)
{

	if(node==NULL)
	{
		printf("\nindex out of range");
		return -1;
	}
	else if(search_index==0)
	{
		printf("\nFound search by index : data %d", node->data);
		return node->data;
	}
	return searchByIndexRecur(node->next, search_index-1);
}
//5
void nthFromLast2pointers(struct Node * head, int n)
{
	struct Node * main_ptr = head;
	struct Node * ref_ptr = head;
	//step 1 : ref_ptr reach end
	int count = 0;
	while(count!=n)
	{
		if(ref_ptr==NULL)
		{
			printf("index out of range");
			return;
		}
		ref_ptr = ref_ptr->next;
		count++;
	}	
	//step 2 :
	while(ref_ptr)
	{
		ref_ptr = ref_ptr->next;
		main_ptr = main_ptr->next;
	}
	
	printf("\nNode %d from last is %d", n, main_ptr->data);
		
}
//6
void middle2ptr(struct Node * head)
{
	struct Node * main_ptr = head;
	struct Node * ref_ptr = head;
	//step 1 : ref_ptr reach end
	while(ref_ptr and ref_ptr->next)
	{
		ref_ptr = ref_ptr->next->next;
		main_ptr = main_ptr->next;
	}	
	
	printf("\nMiddle : %d", main_ptr->data);		
}
//7
int count_data = 0;
int countDataRecur(struct Node * head, int data)
{
	if(head==NULL)
		return count_data;
	if (head->data == data)
		count_data++;
	countDataRecur(head->next, data);
}
//7(ii)
int countDataRecur2(struct Node * head, int data)
{
	if(head==NULL)
		return 0;
	if (head->data == data)
		return 1 + countDataRecur(head->next, data);
	return countDataRecur(head->next, data);
}
int main()
{
	struct Node * head = NULL;
	display(head);
	
	for(int i=1; i<=11; i++)
	{
		insert(&head, i, -1);
		display(head);
		printf("\nLength %d", getLength(head));
	}
	for(int i=1; i<=5; i++)
	{
		insert(&head, 1, -1);
		display(head);
		printf("\nLength %d", getLength(head));
	}

	display(head);
//	del_by_index(&head, 0);

	display(head);
 
	printf("\nLength %d", getLength(head));	
	printf("\nsearch %d", searchByValueRecur(head, 3));
	printf("\n+++++++++++++++++++\n");
	printf("\nsearchByIndexRecur %d", searchByIndexRecur(head, 2));
	nthFromLast2pointers(head, 3);
	middle2ptr(head);
	printf("\nCount Ele : %d", countDataRecur2(head, 1));
	return 0;
}
