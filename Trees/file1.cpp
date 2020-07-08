#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node * left;
    node * right;
};
class tree
{
public:
    node * root;
    tree(){ root=NULL; }
    void display();
    void inorder(node * ptr);
};
void tree::display()
{
    node * temp = root;
    temp = new node;
    inorder(temp);
}
void tree::inorder(node * ptr)
{
    if(root==NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;        
    }
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        cout<<" - "<<ptr->data<<" ";
        inorder(ptr->right);
    }
}
int main()
{
    tree t1; 
    t1.root = new node;
    t1.root->data = 1;
    t1.root->left = new node; 
    t1.root->left->data = 2;
    t1.root->right = new node;
    t1.root->right->data = 3;
    t1.root->left->left = new node;
    t1.root->left->left->data = 4;
    t1.root->left->right = new node;
    t1.root->left->right->data = 5;
    t1.root->right->left = new node;
    t1.root->right->left->data = 6;
    t1.root->right->right = new node;
    t1.root->right->right->data = 7;

    t1.display();
    
    return 0;
}
