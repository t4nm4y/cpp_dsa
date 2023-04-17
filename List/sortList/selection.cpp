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
void display(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
int size(node *head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}
void SeleciionSortList(node*head, int n)
{
    node*temp=head;
    for(int i=0; i<n; i++)
    {
        //to get the first node of the unsorted part:
        temp=head;
        for (int j = 0; j<i; j++)
        {
            temp=temp->next;
        }
        node* first=temp;
        
        //sorting the unsorted part: 
        while(temp->next!=NULL)
        {
            if(first->data > temp->next->data)
            {
                int val=first->data;
                first->data=temp->next->data;
                temp->next->data=val;

                temp=temp->next;
            }
            else temp=temp->next;
        }
    }
}
int main()
{
    node *head=NULL;
    insertAtTail(head,9);
    insertAtTail(head,4);
    insertAtTail(head,1);
    insertAtTail(head,7);
    insertAtTail(head,2);
    cout<<"\noriginal list:";
    display(head);

    int n=size(head);
    SeleciionSortList(head,n);
    
    cout<<"\nafter sorting:";
    display(head);
    return 0;
}