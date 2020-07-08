#include<iostream>
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
    void search(int data);
};
void tree::display(int order)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    else if(order==1)  inorder(root);
    // else if(order==2) preorder(root);
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
void tree::search(int data)
{
    node * temp = root;

    while(temp)
    {
        if(temp->data == data) 
        {
            cout<<"\nData is found, data : "<<data<<"  "<<temp->data;
            return;
        }
        else if(data < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    cout<<"\nData is NOT found, data : "<<data;
}
int main()
{
    tree t1; 

    t1.insert(12);
    t1.insert(3);
    t1.insert(2);
    t1.insert(66);

    t1.display(1);

    t1.search(2);

    int menu, cont=1, data;
    while(cont)
    {
        cout<<"\nMenu : 1.insert 2.search 3.display 4.Stop\n"; cin>>menu;
        if(menu==1)
        {
            cout<<"Enter data : "; int data; cin>>data;
            t1.insert(data); t1.display(1);
        }
        else if(menu==2)
        {
            cout<<"Enter data : "; int data; cin>>data;
            t1.search(data);            
        }
        else if(menu==3) t1.display(1);
        else if(menu==4) cont=0;
        else cout<<"Bad choice\n";
    }
    
    return 0;
}
