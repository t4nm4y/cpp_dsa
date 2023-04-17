#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
    struct node *down;
    node(int val)
    {
        data=val;
        next=NULL;
        down=NULL;
    }
};

void printList(node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}

node *flattenColWise(node *curr)
{
    if(curr==NULL)
    return NULL;

    static node*last;
    last=curr;
    node *next=curr->next;

    if (curr->down)
       curr->next = flattenColWise(curr->down);

    if (next)
       last->next = flattenColWise(next);

    return curr;
}
int main()
{
    struct node *head= new node(1);
    head->next=new node(2);
        head->next->next=new node(3);
            head->next->next->next=new node(4);
            head->next->next->next->next=new node(5);
        head->next->next->down=new node(8);
        head->next->next->down->next=new node(9);        
    head->down=new node(6);
        head->down->next=new node(7);
        head->down->next->down=new node(10);
        head->down->next->down->next=new node(11);
        head->down->next->down->next->down=new node(12);

/* this will create this multi level list:

    head->1 - 2 - 3- 4 - 5
          |       |
          6 - 7   8 - 9
              |
              10 - 11
                    |
                    12
*/
// to print the list depth wise, we need to flatten it in this way:
//  1 6 7 10 11 12 2 3 8 9 4 5

    node* col=flattenColWise(head);
    cout<<"\nColumn wise: ";
    printList(col);
    return 0;
}