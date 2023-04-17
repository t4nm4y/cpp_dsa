#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;

    node(int val)
    {
        data=val;
        prev=NULL;
        next=NULL;
    }
};
void insertAthead(node *&head, int val)
{
    node *n=new node(val);
    n->next=head;
    if (head!=NULL)
    {
    head->prev=n;   
    }
    head=n;
}
void insertAtTail(node* &head, int val)
{
    if(head==NULL)
    {
        insertAthead(head, val);
        return;
    }
    node *t=head;
    node*n=new node(val);
    while (t->next!=NULL)
    {
        t=t->next;
    }
    t->next=n;
    n->prev=t;
}
void display(node *head)
{
    cout<<"\nNULL<--";
    while (head!=NULL)
    {
        cout<<head->data<<"--";
        head=head->next;
    }
    cout<<">NULL";
}
void insertAtPosition(node *&head,int p, int v)
{
    int count=0;
    node *temp=head;
    if (p==0)
    {
        insertAthead(head,v);
        return;
    }
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    temp=head;
    if (p>count)
    {
        cout<<"remains the same, because the position is not present in the list.";
        return;
    }
    if (p==count)
    {
        insertAtTail(head,v);
        return;
    }
    
    node *n= new node(v);
    int i=0;
    while (i!=p-1 && temp->next!=NULL)
    {
        temp=temp->next;
        i++;
    }
    n->next=temp->next;
    temp->next=n;
    n->prev=temp;
}
int main()
{
    node *head=NULL;
    insertAthead(head,5);
    insertAtTail(head,4);
    insertAtTail(head,2);
    insertAtTail(head,8);
    insertAthead(head,9);
    cout<<"\noriginal list: ";
    display(head);
    int p,v;
    cout<<"\nenter the position at which you want to insert the element: ";
    cin>>p;
    cout<<"\nenter the val of the element: ";
    cin>>v;
    cout<<"\nlist after insertion ";
    insertAtPosition(head,p,v);
    display(head);
    cout<<endl;
    return 0;
}