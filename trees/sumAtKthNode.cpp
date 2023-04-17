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
int sumAtK(node *root, int k)
{
    if(root==NULL)
    {
        cout<<"\nThe tree is empty.";
        return -1;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;

    while(!q.empty())
    {
        node *Node=q.front();
        q.pop();
        if(Node!=NULL)
        {
            if(level==k)
            sum+=Node->data;

            if(Node->left!=NULL)
            q.push(Node->left);
            if(Node->right!=NULL)
            q.push(Node->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }
    return sum;
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

   int k=2; //sum at 2nd level should be 4+5+6+7 = 22
   cout<<"\nsum at "<<k<<"th level is: "<<sumAtK(root,k)<<endl;
    return 0;
}