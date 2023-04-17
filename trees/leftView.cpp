#include<iostream>
#include<queue>
using namespace std;
queue<int>a;
//this code is correct, mingw ya win ke nashe h, online comp m shi chal ra h
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
void leftView(node *root)
{
    
    if(root==NULL)
    return;
    while (root)
    {
        a.push(root->data);
        if(root->left==NULL && root->right!=NULL)
        root=root->right;

        else
        root=root->left;       
    }
    return;
}

int main()
{
    node *root= new node(1);
    root->left=new node(2);
    root->right=new node(3);
    // root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->right->right=new node(9);
    /* 
            1 ---root (the start of the tree) or (the parent node)
           / \
          2   3 ---children
         / \
           5 ---leaves (the end of the tree)
    */
    leftView(root);
   cout<<"\nthe left view is: ";
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    // ans is 1 2 5
    return 0;
}