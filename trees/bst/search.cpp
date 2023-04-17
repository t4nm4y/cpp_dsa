//bst is a special type of tree in which each node has lesser values in the left side and greater on the right
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
node *searchBST(node *root, int val)
{
    if(root==NULL)
    return NULL;
    if(root->data==val)
    return root;
    if(root->data<val)
    return searchBST(root->left,val);
    else
    return searchBST(root->right,val);
}
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
    int k;
    cout<<"\nenter the key: ";
    cin>>k;
    if(searchBST(root,k)==NULL)
    cout<<"dne\n";
    else cout<<"key exists\n";
    return 0;
}