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
void deleteAtHead(node*&head)
{
    node *temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;

}
void deletion(node*&head,int val)
{
    if(head->data==val)
    {
        deleteAtHead(head);
        return;
    }

    node*temp=head;
    while (temp!=NULL && temp->data!=val)
    {
        temp=temp->next;
    }

    if(temp==NULL)
    {
        cout<<"\nnot found.";
        return;
    }
    temp->prev->next=temp->next;

    if(temp->next!=NULL)
    temp->next->prev=temp->prev;

    delete temp;
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
    cout<<"\nlist after deletetion: ";
    deletion(head,8);
    display(head);
    return 0;
}