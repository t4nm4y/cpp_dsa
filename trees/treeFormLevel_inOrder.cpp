#include<bits/stdc++.h>
using namespace std;


//doubt!!
//doubt!!
//doubt!!
//doubt!!


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

int search(int arr[], int start, int end, int val)
{
    for (int i = start; i <=end; i++)
    {
        if(arr[i]==val)
        return i;
    }
    return -1;
}

int *extractKeys(int inorder[], int level[], int m, int n)
{
    int *temp=new int[m];
    int j=0;
    for (int i = 0; i < n; i++)
    {
        if (search(inorder,0,m-1,level[i])!=-1)
        temp[j++]=level[i];
    }
    return temp;
}
node *buildTree(int inorder[], int level[], int start, int end, int n)
{
    if (start>end)
     return NULL;
    
    node *root=new node(level[0]);
    
    if(start==end)
    return root;

    int inIndex = search(inorder, start, end, root->data);
 
    // Extract left subtree keys from level order traversal
    int* llevel = extractKeys(inorder, level, inIndex, n);
 
    // Extract right subtree keys from level order traversal
    int* rlevel = extractKeys(inorder + inIndex + 1, level, n - 1, n);
 
    /* construct left and right subtrees */
    root->left = buildTree(inorder, llevel, start, inIndex - 1,inIndex - start);
    root->right = buildTree(inorder, rlevel, inIndex + 1, end,end - inIndex);
 
    // Free memory to avoid memory leak
    delete[] llevel;
    delete[] rlevel;
 
    return root;
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
    int inorder[]={4, 8, 10, 12, 14, 20, 22 };
    int level[]={ 20, 8, 22, 4, 12, 10, 14 };
    int n=sizeof(inorder)/sizeof(inorder[0]);
 
    node *tree=buildTree(inorder,level,0,n-1,n);
    PrintInorder(tree);
    return 0;
}