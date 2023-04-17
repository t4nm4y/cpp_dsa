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
void printLevelWise(node *root)
{
    if(root==NULL)
    {
        cout<<"\nThe tree is empty.";
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node *Node=q.front();
        q.pop();
        if(Node!=NULL)
        {
            cout<<Node->data<<" ";
            if(Node->left!=NULL)
            q.push(Node->left);
            if(Node->right!=NULL)
            q.push(Node->right);
        }
        else if(!q.empty())
        q.push(NULL);
    }
}
int main()
{
    struct node *root= new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    //this code will create this tree:
    /* 
             1 
           /   \
          2     3 
         / \    / \
        4   5  6   7
    */

   
   printLevelWise(root);
    return 0;
}