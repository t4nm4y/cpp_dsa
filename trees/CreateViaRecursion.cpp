#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
node* createTree()
{
    int d;
    cout<<"\nEnter the data(-1 for no data): ";
    cin>>d;
    if(d==-1)
    return NULL;

    node *n=new node(d);
    cout<<"Left child of "<<n->data<<" ";
    n->left=createTree();
    cout<<"Right child of "<<n->data<<" ";
    n->right=createTree();
    return n;
}
void inorder(struct node *root)
{
    if (root==NULL)
    return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    node *root=createTree();
    cout<<"The inorder traversal of the created tree is: ";
    inorder(root);
    return 0;
}