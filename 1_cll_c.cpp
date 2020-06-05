#include<iostream>
#include<stdio.h> 
#include<stdlib.h> 
using namespace std;
// csll
struct Node
{
	int data;
	struct Node * next;
};
void disp(struct Node * head)
{
	struct Node * temp=NULL; temp = (struct Node *)malloc(sizeof(struct Node));
	temp=head;cout<<"here\n";
	
	while(temp->next != head)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<temp->data<<endl;
}
struct Node *  insert(struct Node * head,int insert_index,int data)
{
	struct Node * new_node=NULL ; new_node = (struct Node *)malloc(sizeof(struct Node));
	cout<<"enter data :  "; new_node->data=data;
	struct Node * temp=NULL ; temp = (struct Node *)malloc(sizeof(struct Node));	
	cout<<"here2\n";

	if(insert_index==1)//insert at start
	{
		if(head==NULL)//empty list
		{
			head=new_node;	
		}
		else if(head->next==NULL)//only 1 one ele 
		{
			new_node->next=head;	head->next=new_node;  head=new_node; 
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}	
			temp->next=new_node;	new_node->next=head;	head=new_node;			
		}
	}
	else if(insert_index==-1)
	{
		if(head==NULL)//empty list
		{
			head=new_node;	
		}
		else if(head->next==NULL)//only 1 one ele 
		{
			head->next=new_node; new_node->next=head;
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=new_node;	 new_node->next=head;	
		}		
	}
	else
	{
		if(insert_index==1)
		{
			insert(head,1,data);
		}
		temp=head; int num_ele=0;
		for(int i=0;i<(insert_index-2);i++)
		{
			if(temp->next==head)
			{
				cout<<"number of items in list is :"<<num_ele<<endl;num_ele++;
				return head;
			}
			temp=temp->next;			
		}
		if(temp->next==head)
		{
			insert(head,-1,data);	return head;
		}
		new_node->next=temp->next;		temp->next=new_node;
	}	
	disp(head);
	return head;
}
struct Node *  del(struct Node * head,int del_index)
{
	struct Node * temp=NULL ; temp = (struct Node *)malloc(sizeof(struct Node));	
	temp=head;
	
	if(head==NULL)//zero ele
	{
		cout<<"list is empty\n"; return head;
	}
	else if(del_index==1)
	{
		if(head->next==NULL)//only one ele
		{
			head=NULL;		return head;
		}
		else if(head->next->next==head)//only 2 ele
		{
			head=head->next;	head->next=NULL;
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			head=head->next;	temp->next=head;	
		}		
	}
	else if(del_index==-1)
	{
		if(head->next==NULL)//only one ele
		{
			head=NULL;		return head;
		}
		else if(head->next->next==head)//only 2 ele
		{
			head->next=NULL;
		}
		else
		{
			temp=head;
			while(temp->next->next!=head)
			{
				temp=temp->next;
			}
			temp->next=head;	
		}	
	}
	else//index
	{
		if(del_index==1)
		{
			del(head,1);
		}
		else
		{
			temp=head;
			for(int i=0;i<(del_index-2);i++)
			{
					if(temp->next==head)
					{
						cout<<"index out of range :"<<endl;
						return head;
					}
					temp=temp->next;			
			}
			temp->next=temp->next->next;
		}				
	}
	
	disp(head);
	return head;

}

struct Node * update(struct Node * head,int update_index,int update_data)
{
	struct Node * temp=NULL; temp=(struct Node *)malloc(sizeof(struct Node));	
	
	
	if(head==NULL)//o ele
	{
		cout<<"empty list: "; 
	}
	else if(update_index==1)
	{
		head->data=update_data;
	}
	else if(update_index==-1)
	{
		temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->data=update_data;
	}
	else
	{	
		if(update_index==1)
		{
			update(head,update_index,update_data);
		}
		else
		{
			temp=head;int num_ele=0;
			for(int i=0;i<(update_index-1);i++)
			{
				if(temp->next==head)
				{
					cout<<"index out of range :"<<endl;		return head;
				}
				else
				{
				temp=temp->next;					
				}
			}
			temp->data=update_data;			
		}
	}
	disp(head);
	return head;
}

int main()
{
	struct Node * head = NULL; struct Node * second=NULL; struct Node * third=NULL;  struct Node * fourth=NULL;
	//malloc
	head = (struct Node*)malloc(sizeof(struct Node));  
  	second = (struct Node*)malloc(sizeof(struct Node)); 
  	third = (struct Node*)malloc(sizeof(struct Node)); 
  	fourth = (struct Node*)malloc(sizeof(struct Node)); 
  	//assign
  	head->data=1; head->next=second;	second->data=2; second->next=third;
	third->data=3;  third->next=fourth;   fourth->data=4;  fourth->next=head;
	
	
	
	//menu
	int cont=1;int menu;
	while(cont)
	{
		cout<<"1.insert  2.disp  3.update  4.delete"<<endl;		cin>>menu;
		if(menu==1)//insert  
		{
			int data; cout<<"enter data :  ";  cin>>data;
			int insert_key;	cout<<"1.start 2.index  3.end"<<endl;	cin>>insert_key;
			if(insert_key==1)  head=insert(head,0,data);
			else if(insert_key==2) 
			{
				int insert_index; cout<<"enter index : "<<endl;  cin>>insert_index;
				head=insert(head,insert_index,data);//convert to zero indexing				
			} 
			else if(insert_key==3) 
			{
				head=insert(head,-1,data);
			} 
		}
		else if(menu==2) //disp
		{
			disp(head);
		}		
		else if(menu==3)//update
		{
			int update_data; cout<<"enter the data for update :  ";cin>>update_data;
			int update_key;  cout<<"1.start  2.index  3.end  :  ";  cin>>update_key;
			if(update_key==1)
			{
				head=update(head,1,update_data);
			}
			else if(update_key==2)
			{
				int update_index; cout<<"enter index : ";  cin>>update_index;
				head=update(head,update_index,update_data);
			}
			else if(update_key==3)
			{
				head=update(head,-1,update_data);
			}
		}
		else if(menu==4)//delete
		{
			int del_key; cout<<"1.start 2.index  3.end  :  "; cin>>del_key;
			if(del_key==1)
			{
				head=del(head,1);
			}
			else if(del_key==2)
			{
				int del_index; cout<<"enter index : ";  cin>>del_index;
				head=del(head,del_index);
			}
			else if(del_key==3)
			{
				head=del(head,-1);
			}
		}
			
		else cout<<"key not present\n";
		
		cout<<"cont?(1) :  ";cin>>cont;
	}
	disp(head);
	
	return 0;	
}