#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
    struct node *child;
    node(int val)
    {
        data=val;
        next=NULL;
        child=NULL;
    }
};

void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}

void flattenList(node *head)
{
    if(head==NULL)
    return;

    node *curr=head;

    node *tail=head;
    while (tail->next!=NULL)
    tail=tail->next;

    while (curr!=tail)
    {
        if (curr->child!=NULL)
        {
            //adding the child to the end of the list
            tail->next=curr->child;

            //updating the tail of the list
            node *temp=curr->child;
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            tail=temp;
        }
        curr=curr->next;
    }
    
}

int main()
{
    struct node *head= new node(10);
    head->next=new node(5);
        head->next->next=new node(12);
        head->next->next->next=new node(7);
            head->next->next->next->next=new node(11);
        head->next->next->next->child=new node(17);
            head->next->next->next->child->next=new node(6);
        head->next->next->next->child->child=new node(9);
            head->next->next->next->child->child->next=new node(8);
        head->next->next->next->child->child->child=new node(19);
            head->next->next->next->child->child->child->next=new node(15);
    head->child=new node(4);
        head->child->next=new node(20);
        head->child->next->child=new node(2);
        head->child->next->next=new node(13);
        head->child->next->next->child=new node(16);
        head->child->next->next->child->child=new node(3);

/* this will create this multi level list:

    head->10->5->12->7->11     //level 1
          /          \
          4->20->13  17->6     //level 2
             /    \    \
             2     16    9->8  //level 3
             \     \
              3    19->15      //level 4
*/
// to print the list level wise, we need to flatten it in this way:
//  10 5 12 7 11 4 20 13 17 6 2 16 9 8 3 19 15

    flattenList(head);
    printList(head);
    return 0;
}