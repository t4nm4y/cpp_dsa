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
void move(node *&head)
{
    node *temp=head;
    while (temp->next->next!=head)
    {
        temp=temp->next;
    }
    temp->next->next=head;
    head=temp->next;
    temp->next=head;
}
int main()
{
    node *head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    cout<<"\noriginal list: ";
    display(head);
    cout<<"\nModified list: ";
    move(head);
    display(head);
    cout<<"\nModified list: ";
    move(head);
    display(head);
    return 0;
}