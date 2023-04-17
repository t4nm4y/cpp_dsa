#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left, *right;
    node(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};

node* insertBST(node *root, int val)
{
    if(root==NULL)
    {
        return new node(val);
    }

    if(val<root->data)
    root->left=insertBST(root->left, val);
    else
    root->right=insertBST(root->right,val);
    return root;
}

void inorder(node*root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    node *root=NULL;
    int a[]={5,1,3,4,2,7};
    root=insertBST(root,a[0]);
    int n=sizeof(a)/sizeof(a[0]);
    for (int i = 1; i < n; i++)
    {
        insertBST(root,a[i]);
    }
    cout<<"\nInorder of BST: ";
    inorder(root);
    return 0;
}