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
node *getlast(node *&head)
{
    node *temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    return temp;
}
void extremeSwap(node *&head,node *&last)
{
    int flag=head->data;
    node *p=head;
    node *q=last;
    while (p->next!=last)
    {
        p=p->next;
    }
    head->data=last->data;
    last->data=flag;
    head=head->next;
    last=p;
}
void display(node *&head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
int main()
{
    node *head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    cout<<"\noriginal list:";
    display(head);
    node *index=head;
    node *last=getlast(head);
    extremeSwap(head,last);
    cout<<"\nlist after first swap:";
    display(index);
    extremeSwap(head,last);
    cout<<"\nlist after second swap:";
    display(index);
    extremeSwap(head,last);
    cout<<"\nlist after third swap:";
    display(index);
    extremeSwap(head,last);
    cout<<"\nlist after fourth swap:";
    display(index);
    return 0;
}