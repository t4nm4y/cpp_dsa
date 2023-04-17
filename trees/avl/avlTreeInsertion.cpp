//bst a special type of tree in which each node has lesser value on the left side and greater vals on the right
//avl is just balanced bst

//balanced tree:
// in which the balaced factor of each node is <=1

//(balanced factor = height of left - height of right)

#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *right; 
    struct node *left;
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
    return 1+max(height(root->left),height(root->right));
}
int balanceFactor(node *root)
{
    if(root==NULL)
    return 0;
    return height(root->left)-height(root->right);
}

/*              
        x                            y
       / \      left rotaion        / \
      t1  y   --------------->     x   t3
         / \                      / \
        t2  t3                   t1  t2
*/
node *leftRotation(node *x){
    node *y=x->right;
    node *t2=y->left;

    y->left=x;
    x->right=t2;

    return y;
}

/*
        x                            y
       / \      right rotaion       / \
      y  t3   --------------->     t1  x
     / \                              / \
    t1  t2                           t2  t3
*/
node *rightRotation(node *x){
    node *y=x->left;
    node *t2=y->right;

    y->right=x;
    x->left=t2;

    return y;
}

node *insert(node *root, int key)
{
    if(root==NULL)
    return new node(key);
    
    if(key<root->data)
    root->left=insert(root->left, key);

    else if(key>root->data)
    root->right=insert(root->right, key);
    int bf=balanceFactor(root);

//case1: left left (that is when the new node is inserted in left k left mein) 
    if(bf>1 && key<root->left->data)
        return rightRotation(root);

//case2: right right (that is when the new node is inserted in right k right mein) 
    if(bf<-1 && key>root->right->data)
        return leftRotation(root);    

//case3: left right (that is when the new node is inserted in left ke right mein) 
    if(bf>1 && key>root->left->data)
       { root->left=leftRotation(root->left);
        return rightRotation(root); 
       }

//case4: right left (that is when the new node is inserted in right ke left mein) 
    if(bf<-1 && key<root->right->data)
       { root->right=rightRotation(root->right);
        return leftRotation(root); 
       }
        

    return root;
}

void preorder(node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    node * root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preorder(root);
    return 0;
}