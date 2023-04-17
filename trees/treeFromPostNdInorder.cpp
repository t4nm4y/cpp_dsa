//we can't build binary tree from postorder and preorder unless its a complete binary tree
// because from the same post and preoder we can have more than one binary tree ( like for skewed binary tree we can't build)

//if its a complete binary tree(means every node has both left and right nodes)
// only then we can build it from post and preorder.

#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
int search(int a[], int start, int end, int key)
{
    for (int i = start; i<=end; i++)
    {
        if(a[i]==key)
        return i;
    }
    return -1;
}
node *buildTree(int postorder[], int inorder[], int start, int end)
{
    if(start>end)
    return NULL;

    static int idx=end;
    int curr=postorder[idx];
    node *nodePtr=new node(curr);
    idx--;

    if(start==end)
    return nodePtr;
 
    int pos=search(inorder,start,end,curr);
    nodePtr->right=buildTree(postorder,inorder,pos+1,end);
    nodePtr->left=buildTree(postorder,inorder,start,pos-1);
    return nodePtr;

}
void PrintInorder(node *root)
{
    if(root==NULL)
    return;

    PrintInorder(root->left);
    cout<<root->data<<" ";
    PrintInorder(root->right);
}
int main()
{
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};
    int n=sizeof(postorder)/sizeof(postorder[0]);
 
    node *tree=buildTree(postorder,inorder,0,n-1);
    PrintInorder(tree);
    return 0;
}