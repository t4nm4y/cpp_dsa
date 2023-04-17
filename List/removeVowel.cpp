#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    char data;
    node* next;
    node(char val)
    {
        data=val;
        next=NULL;
    }
};
void insertAtHead(node *&head, char val)
{
    node *n=new node(val);
    n->next=head;
    head=n;
}
void insertAtTail(node *&head, char val)
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
void deleteNode(node *&head, char val)
{
    if(head->data==val)
    {
        deleteAtHead(head);
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
void removeVowel(node *&head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data == 'a' || temp->data == 'A' || temp->data == 'e' || temp->data == 'E' || temp->data == 'i' || temp->data == 'I' || temp->data =='o' || temp->data=='O' || temp->data == 'u' || temp->data == 'U')
        {
            deleteNode(head,temp->data);
            temp=head;
        }
        else
        {
            temp=temp->next;
        }
    }
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
    string name;
    cout<<"\nEnter the name: ";
    cin >> name;
    for (int i = 0; i < name.size(); i++)
    {
        insertAtHead(head,name[name.size()-i-1]);
    }
    cout<<"\noriginal list:";
    display(head);
    cout<<"\nlist after removing vowels: ";
    removeVowel(head);
    display(head);
    return 0;
}