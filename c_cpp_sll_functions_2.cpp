#include<stdio.h>
#include<stdlib.h>
#include <bits/stdc++.h>
//stack

//stack end
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
//1 hash CPP
//bool detectLoopHash(struct Node * node)
//{
//	unordered_set<struct Node *> s; 
//	
//	while(node)
//	{
//		if(s.find(node)!=s.end())
//		{
//			printf("\nLoop found");
//			return true;
//		}
//			
//		
//		s.insert(node);
//		
//		node = node->next;
//	}
//	printf("\nLoop not found");
//	return false;	
//}
//2 loop 2 ptr
bool detectLoop2ptr(struct Node * head)
{
	struct Node * fast = head;
	struct Node * slow = head;
	//create loop
	struct Node * temp = head;
	while(temp->next->next)
	{
		temp = temp->next;
	}
	temp->next = head;
	
	while(slow and fast and fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if(slow == fast)
		{
			printf("\nLoop found");
			return true;			
		}
	}
	printf("\nLoop not found");
	return false;	
}
//3 loop 2 ptr len
bool detectLoop2ptrCount(struct Node * head)
{
	struct Node * fast = head;
	struct Node * slow = head;
	//create loop
	struct Node * temp = head;
	while(temp->next->next)
	{
		temp = temp->next;
	}
	temp->next = head;
	
	while(slow and fast and fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if(slow == fast)
		{
			printf("\nLoop found");
			//dont move fastnode
			//move slownode until it finds fastnode
			int lenn=1;
//			slow = slow->next;
			while(slow->next!=fast)
			{
				slow = slow->next;
				lenn++;
			}
			printf("\nLoop lenn %d", lenn);
			return true;			
		}
	}
	printf("\nLoop not found");
	return false;	
}
//4 print reverse
bool printReverse(struct Node * node)
{
	if(node->next)
	{
		printReverse(node->next);
	}
	printf("\nList Ele : %d", node->data);
}
//5 check pallindrome : using 2nd sll
//bool checkPallindrome(struct Node * head)
//{
//	struct Node * temp = head;
//	//step1 : store reverse of main sll in temp sll
//	stack <int> s;
//	
//	while(temp)
//	{
//	    s.push(temp->data);
//	    temp = temp->next;
//	}
//	
//	temp = head;
//	
//	while(temp)
//	{
//	    int item_s = s.pop();
//	    
//	    if(temp->data!=item_s)
//	    {
//	        printf("\nNot a pallindrome")
//	        return false
//	    }
//	    
//	    temp = temp->next;
//	}
//	
//	printf("A pallindrome");
//	return true;
//}

//6 reverse sll
void reverseSll(struct Node ** head)
{
	struct Node * prev = NULL;
	struct Node * curr = (*head);
	struct Node * next;
	
	while(curr)
	{
		next = curr->next; //create link to next node
		curr->next = prev; //reverse curr node
		//move to next node
		prev = curr;
		curr = next;
	}
	
	(*head)  = prev;
//	display(*head);
}
//7 check pallindrome
bool checkPallinMidRev(struct Node * head)
{
	//step 1: reach middle
	//Note : we go to middle+1 for right part
	//lenn 8 mid 5 ; lenn 9 mid 6
	struct Node * fast = head;
	struct Node * slow = head;
	while(fast and fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		printf("\nHere %d ", slow->data);
	}
	if(fast)
	{
		slow = slow->next; printf("\nList lenn odd");
	}
	//step 2: reverse right
	struct Node * prev = NULL;
	struct Node * curr = slow;
	struct Node * next;
	
	while(curr)
	{
		next = curr->next; //create link to next node
		curr->next = prev; //reverse curr node
		//move to next node
		prev = curr;
		curr = next;
	}
	
	struct Node * right = prev;//head  = prev;
	struct Node * left = head;
	//step 3: compare
	while(right)
	{
		if(right->data != left->data)
		{
			printf("\nNot pallindrome");
			return false;
		}
		printf("\nTest %d %d", right->data , left->data);
		right = right->next;
		left = left->next;
	}
	printf("\nA pallindrome");
	return true;
 
}



int main()
{
	struct Node * head = NULL;

	for(int i=1; i<=3; i++)
	{
		insert(&head, i, -1);
	}
//	insert(&head, 4, -1);
	for(int i=1; i<=3; i++)
	{
		insert(&head, 4-i, -1);
	}
	display(head);
	reverseSll(head);
	return 0;
}
