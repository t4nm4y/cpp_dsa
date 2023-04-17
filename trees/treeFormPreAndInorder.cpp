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

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <=end; i++)
    {
        if(inorder[i]==curr)
        return i;
    }
    return -1;
}

node *buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx=0;
    if (start>end)
     return NULL;
    
    int curr=preorder[idx];
    idx++;
    node *nodePtr= new node(curr);
    if(start==end)
    return nodePtr;

    int pos=search(inorder,start,end,curr);
    nodePtr->left=buildTree(preorder,inorder,start,pos-1);
    nodePtr->right=buildTree(preorder,inorder,pos+1,end);
    return nodePtr;
}

void PrintInorder(node *root)
{
    if (root==NULL)
    return;
    
    PrintInorder(root->left);
    cout<<root->data<<" ";
    PrintInorder(root->right);
}

int main()
{ 
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    int n=sizeof(preorder)/sizeof(preorder[0]);
 
    node *tree=buildTree(preorder,inorder,0,n-1);
    PrintInorder(tree);
    return 0;
}