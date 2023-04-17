#include<iostream>
using namespace std;
struct node{
    int key;
    node *right, *left;
    node(int val)
    {
        key=val;
        right=NULL;
        left=NULL;
    }
};
node *inorderSucc(node* root)
{
    node *curr =root;
    while (curr->left)
        curr=curr->left;

    return curr;
}
node *insert(node *root, int val)
{
    if(root==NULL)
        root= new node(val);
    else if(val<root->key)
        root->left=insert(root->left, val);
    else root->right=insert(root->right, val);

    return root;
}
node *node_delete(node *root, int val)
{
    if (root==NULL)
        return NULL;
    
    if(val<root->key)
        root->left=node_delete(root->left, val);
    else if(val>root->key)
        root->right=node_delete(root->right, val);

    //when root->key=val
    else
    {
        //case 1: when its leaf node
        if (root->left==NULL && root->right==NULL)
            return NULL;
        
        //case 2: when it has only left child
        else if (root->left==NULL)
         {   node *temp=root->right;
            delete(root);
            return temp;
         }

        //case 3: when it has only right child
        else if (root->left!=NULL)
         {   node *temp=root->left;
            delete(root);
            return temp;
         }

        //case 4: when it has both child
        //find the inorder successor of the node(it will always be the left most val in the right subtree )
        // take its val and delete the succ
        else
        {
            root->key=inorderSucc(root->right)->key;
            root->right=node_delete(root->right, root->key);
        }
    }
    return root;
}
void inorder(node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}
int main()
{
    //create a bst
    node *root=NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    //inorder traversal of the original tree
    cout<<"\ninorder traversal of the original tree: ";
    inorder(root);

    cout << "\nDelete 20\n";
    root = node_delete(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    cout << "\nDelete 30\n";
    root = node_delete(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    cout << "\nDelete 50\n";
    root = node_delete(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
    return 0;
}