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
void deleteAtHead(node *&head)
{
    node *temp=head;
    head=head->next;
    delete temp;
}
void deleteNode(node *&head, int val)
{
    if(head->data==val)
    {
        deleteAtHead(head);
        return;
    }
    if(head==NULL){
        cout<<"\nthe list is empty";
        return;
    }
    node *temp=head;
    while(temp->next->data!=val && temp->next!=NULL)
    {
        temp=temp->next;
    }
    node *dlt=temp->next;
    temp->next=temp->next->next;
    delete dlt;
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
    return 0;
}