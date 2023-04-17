#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left,*right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

//since it will run till idx is less than n,
//so the time complexity is O(n).
node *bst(int preorder[], int *idx, int key, int min, int max, int n)
{
    if(*idx>=n)
    return NULL;

    node*root=NULL;
    if(key>min && key<max)
    {
        root=new node(key);
        *idx+=1;

        if(*idx<n)
        root->left=bst(preorder, idx, preorder[*idx], min, key, n);
    
        if(*idx<n)
        root->right=bst(preorder, idx, preorder[*idx], key, max, n);
    }
    return root;
}

void preorder(node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    //preorder seq
    int a[]={10,2,1,13,11};
    int n=sizeof(a)/sizeof(a[0]);
    int idx=0;
    node *root=bst(a, &idx, a[0], INT_MIN, INT_MAX, n);
    cout<<endl;
    preorder(root);
    return 0;
}