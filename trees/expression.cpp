
#include<bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    node* right;
    node* left;
    node(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    return true;
    return false;
}
node* constructTree(char a[])
{
    for (int i = 0; i < strlen(a); i++)
    {
       
    }
    
}
void printInorder(node *start)
{
    if(start)
    {
        printInorder(start->left);
        cout<<start->data;
        printInorder(start->right);
    }
}
int main()
{
    char a[]="a+b*(c^d-e)^(f+g*h)-i";
    node *start=constructTree(a);
    printInorder(start);
    return 0;
}