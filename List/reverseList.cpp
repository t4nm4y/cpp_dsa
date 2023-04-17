#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insertAtHead(node *&head, int val)
{
    node *n=new node(val);
    n->next=head;
    head=n;
}
void insertAtTail(node *&head, int val)
{
    if(head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    node *n=new node(val);
    node*temp=head; 
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=NULL;
}
node *reverseList(node *&head)
{
    node *prv=NULL;
    node *current=head;
    node *next;
    while (current!=NULL)
    {
        next=current->next;
        current->next=prv;

        prv=current;
        current=next;
    }
    return prv;
}
node *recursiveReverse(node *&head)
{
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    node *newHead= recursiveReverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}
void display(node *&head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
int main()
{
    node *head=NULL;
    insertAtTail(head,2);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,7);
    cout<<"\noriginal list:";
    display(head);
    insertAtHead(head,9);
    cout<<"\nafter inserting at head:";
    display(head);
    node *newHead=recursiveReverse(head);
    cout<<"\nafter inserting reversing:";
    display(newHead);
    return 0;
}