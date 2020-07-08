#include<iostream>
#include<bits/stdc++.h> 
using namespace std;

class node
{
public:
    int data;
    node * left;
    node * right;
    node(int d){ left=NULL; right=NULL; data=d; };
};
class tree
{
public:
    node * root;
    tree(){ root=NULL; }
    //func
    void insert(int data);
    void insert2(node * temp, node * new_node);
    void display(int order);
    void inorder(node * ptr);
    void inorder_stack();
    void preorder(node * ptr);
    void postorder(node * ptr);
    bool search(int data);
    void delete1(int data);
};
void tree::display(int order)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    else if(order==1)  inorder(root);
    else if(order==2) preorder(root);
    // else if(order==3) postorder(root);
    else  cout<<"invalid input\n";

}
void tree::inorder(node * ptr)//l root r
{
    if (ptr)
    {
        inorder(ptr->left);
        cout<<ptr->data<<"  ";
        inorder(ptr->right);
    }
}
void tree::inorder_stack()
{
    node * curr = root;
    stack <node *> my_stack;

    while(curr != NULL || my_stack.empty() == false)
    {
        while(curr)
        {
            my_stack.push(curr); curr = curr->left;
        }

        curr = my_stack.top();        
        my_stack.pop();

        cout<<"\nData : "<<curr->data;

        curr = curr->right;
    }
}
void tree::preorder(node * ptr)
{
    if(ptr)
    {
        cout<<ptr->data<<" ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void tree::postorder(node * ptr)
{
    if(ptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->data<<" ";
    }
}
void tree::insert(int data)
{
    //create new node
    node * new_node = new node(data); //declare and allocate memory
    // new_node->data = data;      //initialise
    if(root==NULL) root = new_node;
    else insert2(root, new_node);
}
void tree::insert2(node * temp, node * new_node)//temp -- tree
{
    if(new_node->data <= temp->data)
    {
        if(temp->left==NULL)  temp->left = new_node;
        else  insert2(temp->left, new_node);
    }
    else
    {
        if(temp->right==NULL)  temp->right = new_node;
        else  insert2(temp->right, new_node);
    }
}
bool tree::search(int data)
{
    node * temp = root;

    while(temp)
    {
        if(temp->data == data) 
        {
            cout<<"\nData is found, data : "<<data<<"  "<<temp->data;
            return true;
        }
        else if(data < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    cout<<"\nData is NOT found, data : "<<data;
    return false;
}
void tree::delete1(int data)//by value
{
    node * temp = root; node * pre_temp = root;
    //search the data;
    int found = -1;
    while(temp)
    {
        if(temp->data == data) 
        {
            cout<<"\nData is found, data : "<<data<<"  "<<temp->data;
            cout<<"\nPre_temp, temp : "<<pre_temp->data<<"  "<<temp->data;
            found=1; break;
        }
        else if(data < temp->data)
        {
            pre_temp = temp;
            temp = temp->left;
        } 
        else 
        {
            pre_temp = temp;
            temp = temp->right;            
        }
    }    
    //
    if(found==-1)
    {
        cout<<"Data to delete NOT found"; return;
    }
    //found
     
    // node * to_del = temp;
    //----------------
    //leaf node
    if(temp->left == NULL and temp->right == NULL)
    {
        if(pre_temp->left == temp)
            pre_temp->left = NULL;
        else//(pre_temp->right == temp)
            pre_temp->right = NULL;
    }
    else if(temp->left != NULL and temp->right == NULL)
    {
        if(pre_temp->left == temp)
            pre_temp->left = temp->left;
        else//(pre_temp->right == temp)
            pre_temp->right = temp->left;       
    }
    else if(temp->left == NULL and temp->right != NULL)
    {
        if(pre_temp->left == temp)
            pre_temp->left = temp->right;
        else//(pre_temp->right == temp)
            pre_temp->right = temp->right;     
    }
    else//(temp->left != NULL and temp->right != NULL)
    {
        node * smallest_left = temp->right;
        node * pre_smallest_left = temp->right;

        while(smallest_left->left)
        {
            pre_smallest_left = smallest_left;
            smallest_left = smallest_left->left;
        }

        temp->data = smallest_left->data;

        if(smallest_left == temp->right)
            temp->right = temp->right->right;
        else//(smallest_left != temp->right)
            pre_smallest_left->left = smallest_left->right;
    }
    
}
int main()
{
    tree t1; 

    t1.insert(30);
    t1.insert(20);
    t1.insert(15);
    t1.insert(40);
    t1.insert(35);
    t1.insert(45);

    t1.display(1);

    t1.inorder_stack();

    int menu, cont=1, data;
    while(cont)
    {
        cout<<"\nMenu : 1.insert 2.search 3.delete 4.display 5.Stop\n"; cin>>menu;
        if(menu==1)
        {
            cout<<"Enter Insert data : "; cin>>data;
            t1.insert(data); t1.display(1);
        }
        else if(menu==2)
        {
            cout<<"Enter Search data : "; cin>>data;
            t1.search(data);            
        }
        else if(menu==3)
        {
            cout<<"Enter Delete data : "; cin>>data;
            t1.delete1(data); t1.display(1);            
        }
        else if(menu==4) t1.inorder_stack();
        else if(menu==5) cont=0;
        else cout<<"Bad choice\n";
    }
    
    return 0;
}

