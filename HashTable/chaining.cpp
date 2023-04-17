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
node *arr[10];
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
void insert(int n)
{
    int index;
    index=n%10;
    insertAtTail(arr[index],n);
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
    int n;  
    cout<<"enter ten integers: ";
    
    for (int i = 0; i < 10; i++)
    {
        cin>>n;
        insert(n);
    }
    cout<<"\nthe hash table is: \n";
    for (int i = 0; i < 10; i++)
    {
        cout<<i<<"|->";
        display(arr[i]);
    }
    
}