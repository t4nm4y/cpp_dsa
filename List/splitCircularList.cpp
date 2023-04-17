#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insertAthead(node *&head, int val)
{
    node *n= new node(val);
    if(head==NULL)
    {
        n->next=n;
        head=n;
    }
    node *temp=head;
    while (temp->next!=head)
    {
       temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}
void insertAtTail(node *&head, int val)
{
    if(head==NULL)
    {
        insertAthead(head,val);
        return;
    }
    node *n= new node(val);
    node *temp=head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}
void display(node *head)
{
    node *temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}
void splitList(node* head, node *&head1, node *&head2)
{
    node* fp=head;
    node* sp=head;
    if (head==NULL)
    {
        cout<<"empty list";
    }
    if (head->next==head)
    {
        cout<<"\nnot possible to split, since only one element present in the list";
        return;
    }
    while(sp->next->next!=head && sp->next!=head)
    {
        sp=sp->next->next;
        fp=fp->next;
    }
    if (sp->next!=head)
    {
        sp=sp->next;
    }
    head1=head;
    head2=fp->next;
    fp->next=head;
    sp->next=head2;
}
int main()
{
    node *head=NULL;
    node *head1=NULL;
    node *head2=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,7);
    insertAthead(head,44);
    cout<<"\noriginal list: ";
    display(head);
    cout<<"\nList after splitting: ";
    splitList(head,head1,head2);
    cout<<"\n1st list: ";
    display(head1);
    cout<<"\n2nd list: ";
    display(head2);
    return 0;
}