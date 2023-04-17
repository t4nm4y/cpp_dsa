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
int nodeSum(node *root)
{
    if(root==NULL)
    return 0;

    return nodeSum(root->left)+nodeSum(root->right)+root->data;
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

   //sum should be 1+2+3+4+5+6+7 = 28
   cout<<"\nSum of all nodes is: "<<nodeSum(root)<<endl;
    return 0;
}