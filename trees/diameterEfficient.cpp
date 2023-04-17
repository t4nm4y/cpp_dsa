//this is the efficient way to calc the diameter
//time complexity to o(n)
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

int calcDiam(node *root, int *ht)
{
    if(root==NULL)
    return 0;

    int lh=0;
    int rh=0;
    int lDiam=calcDiam(root->left, &lh);
    int rDiam=calcDiam(root->right, &rh);  

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