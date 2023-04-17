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
bool checkDup(node *root, set<int>s)
{
    if(root==NULL)
    return false;

    if(s.find(root->data)!=s.end())
    return true;

    s.insert(root->data);

    return checkDup(root->left, s) || checkDup(root->right, s);
}

int main()
{
    struct node *root= new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    set<int>s;
    if(checkDup(root,s))
    cout<<"yes it has duplicate values.\n";
    else cout<<"no it doesnt have duplicate values.\n";
    return 0;
}