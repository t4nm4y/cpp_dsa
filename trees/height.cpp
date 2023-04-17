//time comp. is o(n)
//because we are calling the func calcHeight for each node,

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
int height(node *root)
{
    if(root==NULL)
    return 0;

    return 1 + max(height(root->left),height(root->right));
}
int main()
{
    struct node *root= new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    //this code will create this tree:
    /* 
             1 
           /   \
          2     3 
         / \     \
        4   5     7
    */

   //sum should be 3
   cout<<"\nHeight of the tree is: "<<height(root)<<endl;
    return 0;
}