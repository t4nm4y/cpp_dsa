//both right and left of leaf nodes is threaded
//left points to the inorder predecessor
//right points to the inorder successor

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int key,rbit,lbit;
    node *right, *left;
    node(int val)
    {
        key=val;
        right=left=NULL;
        lbit=rbit=0;
    }
};

void insert(node *root,int val)
{
    //if no node is present(only dummy is present)
    if(root->left==root && root->right==root)
    {
        node *p=new node(val);
        p->left = root->left;
        p->right = root->right;

        //Inserting the node in the left of the dummy node
        root->left = p;
        root->lbit = 1;
        return;
    }

    node *cur=root->left;
  while(1)
  {
    if (cur->key < val)
    {
        node* p = new node(val);
        if (cur->rbit == 0) 
        {
            p->right = cur->right;
            p->left = cur;

        //Inserting the node in the right
            cur->rbit = 1;
            cur->right = p;
            return;
        }
        else
        cur = cur->right;
    }
    if (cur->key > val)
    {
        node* p = new node(val);
        if (cur->lbit == 0)
        {
            p->left = cur->left;

        //Pointing the right child to its inorder Successor
            p->right = cur;
            cur->lbit = 1;
            cur->left = p;
            return;
        }
        else
        cur = cur->left;
    }
  }
}

node * inorderSuccessor(node *c)
{
    if (c->rbit == 0)
        return c->right;
    else
        c = c->right;
    while (c->lbit == 1) {
        c = c->left;
    }
    return c;
}
node * preorderSuccessor(node *c)
{
    if (c->lbit == 1) {
        return c->left;
    }
    while (c->rbit == 0) {
        c = c->right;
    }
    return c->right;
}
void inorder(node*root)
{
    node *c=root->left;
    while (c->lbit == 1)
        c = c->left;
 
    // Loop to traverse the tree
    while (c != root) {
        cout << " " << c->key;
        c = inorderSuccessor(c);
    }
}
void preorder(node*root)
{
    node* c = root->left;
 
    // Loop to traverse the tree in
    // the preorder fashion
    while (c != root) {
        cout << " " << c->key;
        c = preorderSuccessor(c);
    }
    
}

int main()
{
    //creating dummy node, our whole tree will be to the left of this dummy node
    node *root=new node(999);
    root->rbit=1;
    root->lbit=0;
    root->right=root;
    root->left=root;
    insert(root,6);
    insert(root,3);
    insert(root,1);
    insert(root,5);
    insert(root,8);
    insert(root,7);
    insert(root,11);
    insert(root,9);
    insert(root,13);
 
    cout << "\nInorder: ";
    inorder(root);
    cout << "\npreorder: ";
    preorder(root);
    return 0;
}