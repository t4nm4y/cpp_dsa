//a multilist in which each node can have max of k child, i.e 0 to k, (min of 0 child)
//here k is 4;

#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node *child[4];
    node (char val)
    {
        data=val;
    }
};
void inorder(node *root)
//here inorder is defined in the ques as (0 1 root 2 3);
{
    if(root==NULL)
    return;

    for (int i = 0; i < 2; i++)
    {
        inorder(root->child[i]);
    }
    cout<<root->data<<" ";
    for (int i = 2; i < 4; i++)
    {
        inorder(root->child[i]);
    }
}
void preorder(node *root)
{
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    for (int i = 0; i < 4; i++)
    {
        preorder(root->child[i]);
    }
}
void postorder(node *root)
{
    if(root==NULL)
    return;

    for (int i = 0; i < 4; i++)
    {
        postorder(root->child[i]);
    }
    cout<<root->data<<" ";
}
int main()
{
node *root=new node('a');
    root->child[0]=new node('b');
        root->child[0]->child[0]=new node('f');
            root->child[0]->child[0]->child[0]=new node('i');
            root->child[0]->child[0]->child[1]=new node('j');
        root->child[0]->child[3]=new node('g');
            root->child[0]->child[3]->child[0]=new node('k');
    root->child[1]=new node('c');
    root->child[2]=new node('d');
        root->child[2]->child[2]=new node('h');
            root->child[2]->child[2]->child[0]=new node('l');
            root->child[2]->child[2]->child[2]=new node('m');
    root->child[3]=new node('e');

    cout<<"\nPreorder Traversal: ";
    preorder(root);
    cout<<"\nPostorder Traversal: ";
    postorder(root);
    cout<<"\nInorder Traversal: ";
    inorder(root);
    cout<<endl;
    return 0;
}