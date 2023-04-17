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
int main()
{
    struct node *root= new node(1);
    root->left=new node(2);
    root->right=new node(3);
    //this code will create this tree:
    /* 
            1 ---root
           / \
          2   3 
    */

    root->left->left=new node(4);
    root->left->right=new node(5);
    //now this will add 2 new child after 2:
    //and the tree will become this:
    /* 
            1 ---root (the start of the tree) or (the parent node)
           / \
          2   3 ---children
         / \
        4   5 ---leaves (the end of the tree)
    */

    return 0;
}