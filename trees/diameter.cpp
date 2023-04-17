//The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
//This path may or may not pass through the root.

//time comp. is o(n^2)
//because we are calling the func calcDiam for each node,
//which is agian calling the func calcHeight for each node.

//there is an another way to solve this ques so as to decrease
// the time complexity to 0(n)
//it can be done by taking height as pointer instead of calc it in another func.
//see diameterEfficient.cpp

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
int calcHeight(node *root)
{
    if(root==NULL)
    return 0;

    return 1 + max(calcHeight(root->left),calcHeight(root->right));
}
int calcDiam(node *root)
{       
    if(root==NULL)
    return 0;

    int lheight=calcHeight(root->left);
    int rheight=calcHeight(root->right);
    int currDiam=lheight+rheight+1;

    int lDiam=calcDiam(root->left);
    int rDiam=calcDiam(root->right);  

    return max(currDiam, max(lDiam,rDiam));
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

   //height should be 5 (4,2,1,3,7) 
   //here root is a part of the diameter
   cout<<"\nthe diameter of the tree is: "<<calcDiam(root)<<endl;
    return 0;
}