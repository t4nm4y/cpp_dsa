#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void _insert(node *curr, int val)
{
    if (curr->next==NULL)
    {
        curr->next=new node(val);
        return;
    }
    _insert(curr->next, val);
}
void insert(node *&head, int val)
{
    if (head==NULL)
    {
        head=new node(val);
        return;
    }
    _insert(head,val);
}
void display(node *head)
{
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}
int main()
{
    node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,7);
    insert(head,4);
    display(head);
    return 0;
}