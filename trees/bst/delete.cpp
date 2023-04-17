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
node *inorderSucc(node*root)
{
    node *curr =root;
    while (curr->left)
        curr=curr->left;

    return curr;
}
node *deleteBST(node *root,int key)
{
    if(key<root->data)
    root->left=deleteBST(root->left,key);
    else if(key>root->data)
    root->right=deleteBST(root->right,key);

    //when root->data=key
    else{
        if(root->left==NULL)
        {
            node*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node*temp=root->left;
            free(root);
            return temp;
        }
        //case 3 when it has 2 child
        //find the inorder successor of the node(it will always be the left most val in the right subtree )
        // take its val and delete the succ
        root->data=inorderSucc(root->right)->data;
        root->right=deleteBST(root->right,root->data);
    }
    return root;
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

    inorder(root);
    root=deleteBST(root,2);
    cout<<endl;
    inorder(root);
    return 0;
}