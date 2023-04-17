//if node is i:
// its parent=i/2
//its left child of i = 2*i
// right child of i = 2*i+1

//so here the nodes will start from 1, but the index of array will start from 0
//therefore the val in array at index i, will be the data of the node i+1;
//so the left child will be 2*i+1;
//the right child will be 2*i+2;

//if in array the val is 0 then at that insert NULL
#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *left,*right;
    int data;
    node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
node* insertValue(node* root, int value,queue<node *>& q)
{
    // if(value==0)
    // {
    //     node *temp=NULL;
    //     q.push(temp);
    //     return root;
    // }

    node* temp = new node(value);
    if (root == NULL)
        root = temp;
 
    // The left child of the current Node is
    // used if it is available.
    else if (q.front()->left == NULL)
        q.front()->left = temp;
 
    // The right child of the current Node is used
    // if it is available. Since the left child of this
    // node has already been used, the Node is popped
    // from the queue after using its right child.
    else {
        q.front()->right = temp;
        q.pop();
    }
 
    // Whenever a new Node is added to the tree, its
    // address is pushed into the queue.
    // So that its children Nodes can be used later.
    q.push(temp);
    return root;
}
 
// This function mainly calls insertValue() for
// all array elements. All calls use same queue.
node* createTree(int arr[], int n)
{
    node* root = NULL;
    queue<node*> q;
    for (int i = 0; i < n; i++)
      root = insertValue(root, arr[i], q);
    return root;
}
 
// This is used to verify the logic.
void levelOrder(node* root)
{
    if (root == NULL)
        return;
    queue<node*> n;
    n.push(root);
    while (!n.empty()) {
        cout << n.front()->data << " ";
        if (n.front()->left != NULL)
            n.push(n.front()->left);
        if (n.front()->right != NULL)
            n.push(n.front()->right);
        n.pop();
    }
}

void inorder(node *root)
{
    if (root==NULL)
    return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    int arr[] = { 10, 20, 30, 40, 50, 60 };
    // int arr[]={1,2,3,4,5,6,7,0,8,9,0,0,0,10,11,12,13,0,14,15,0,16,17};
    int n = sizeof(arr) / sizeof(arr[0]);
    node* root = createTree(arr, n);
    cout<<"\nLevelorder:\n";
    levelOrder(root);
    cout<<"\nInorder:\n";
    inorder(root);
    return 0;
}
