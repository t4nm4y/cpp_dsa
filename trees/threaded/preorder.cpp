// single right threaded bt
//(only right of leaf nodes are threaded)
//and it points to the inorder successor

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    node *right, *left;
    bool isThreaded;
    node(int val)
    {
        key=val;
        right=left=NULL;
        isThreaded=false;
    }
};

node *createThreaded(node *root)
{
    if ((root->left==NULL && root->right==NULL)||root==NULL)
    return root;
    if(root->left!=NULL)
    {
        node *temp=createThreaded(root->left);
        temp->right=root;
        temp->isThreaded=true;
    }
    if(root->right==NULL)
    return root;

    return createThreaded(root->right);
}
node *leftMost(node *root)
{
    while(root->left!=NULL)
    root=root->left;

    return root;
}
void preorder(node *root)
{
    if(root==NULL) return;

    node *curr=root;
    while (curr)
    {
        cout<<curr->key<<" ";
        if(curr->left)
        curr=curr->left;
        else if(!curr->isThreaded && curr->right)
        curr=curr->right;
        else
        {
            while(curr->isThreaded)
            curr=curr->right;

            if(curr->right==NULL) //last node
            break;
            else curr=curr->right;
        }
    }
    
}

int main()
{
    /*       1
            / \
           2   3
          / \ / \
         4  5 6  7   */
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
 
    createThreaded(root);
 
    cout << "\npreorder traversal of created threaded tree is: ";
    preorder(root);
    return 0;
}