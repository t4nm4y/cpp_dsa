#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    char data;
    node *next;
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
void deleteHead(node *&head)
{
    node *temp=head;
    head=head->next;
    delete temp;
}
void deletion(node* &head, node *d)
{
    if(d==head)
    {
        deleteHead(head);
        return;
    }
    if(head==NULL){
        cout<<"\nthe list is empty";
        return;
    }
    node *temp=head;
    while(temp->next!=d && temp->next!=NULL)
    {
        temp=temp->next;
    }
    node *dlt=temp->next;
    temp->next=temp->next->next;
    delete dlt;
}
void remove(node *&head1,node *head2)
{
    node *temp1=head1;
    node *temp2=head2;
    node *flag1=NULL;
    while (temp1->next->next!=NULL)
    {
        int c=0;
        while (temp1->data!=temp2->data)
        {
            temp2=temp2->next;
            if(temp2->next->next==NULL)
            {
                temp1=temp1->next;
                break;
            }
        }
        if (temp1->data==temp2->data)
        {
            c++;
            flag1=temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        for (int i = 0; i < 2; i++)
        {
            if (temp1->data==temp2->data)
            {
                c++;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else break;
        }
        if (c==3)
        {
            node* flag2= flag1->next;
            node* flag3= flag2->next;
            deletion(head1,flag1);
            deletion(head1,flag2);
            deletion(head1,flag3);
            return;
        }

        temp2=head2;
        
    }
    cout<<"is not Possible.\nlist is not changed: ";
    
}
int main()
{
    node *head1=NULL;
    node *head2=NULL;
    char n;
    cout<<"\nenter any 10 characters: ";
    for (int i = 0; i < 10; i++)
    {
        cin>>n;
        insertAtTail(head1,n);
    }
    cout<<"\nEnter any 5 characters: ";
    for (int i = 0; i < 5; i++)
    {
        cin>>n;
        insertAtTail(head2,n);
    }
    cout<<"\nlist 1: ";
    display(head1);
    cout<<"\nlist 2: ";
    display(head2);
    cout<<"\nList after removing 3 consecutive elements: ";
    remove(head1,head2);
    display(head1);
    cout<<endl;
    return 0;
}