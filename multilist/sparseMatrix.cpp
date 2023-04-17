//in sparse matrix most of the elements are 0
//each element of the matrix xontains 4 things(row,col,data,next) row ,col of the next position of non zero value
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    int row;
    int col;
    node *next;
    node(int val)
    {
        data=val;
        row=-1;
        col=-1;
        next=NULL;
    }
};
void sparseMatrix(node *head, int rows, int cols)
{
    map<int, int>rmap,cmap;
    node *curr=head;
    for (int r = 0; r < rows; r++)
    {
        rmap[r]++;
        for (int c = 0; c < cols; c++)
        {   
            cmap[c]++;
            if(curr->row==r && curr->col==c)
            {
                cout<<"\nrow:"<<r<<" col:"<<c<<" data:"<<curr->data;
                rmap[r]++;
                cmap[c]++;
            curr=curr->next;
            }
        }
         
    }
    map<int, int> :: iterator it;
    int min=99,least;
    for (it=rmap.begin(); it!=rmap.end(); it++)
    {
        if(min>it->second)
        {
            min=it->second;
            least=it->first;
        }
    }
    cout<<"\nThe least sparsed row is: "<<least;
    min=99;
    for (it=cmap.begin(); it!=cmap.end(); it++)
    {
        if(min>it->second)
        {
            min=it->second;
            least=it->first;
        }
    }
    cout<<"\nThe least sparsed coloumn is: "<<least;

}
int main()
{
    node *head=new node(0);
    head->row=0;
    head->col=2;
    

    node *a=new node(2);
    node *b=new node(3);
    node *c=new node(4);
    node *d=new node(1);
    node *e=new node(5);
    node *f=new node(4);

    head->next=a;
    a->row=0;
    a->col=4;
    a->next=b;

    b->row=1;
    b->col=2;
    b->next=c;

    c->row=3;
    c->col=1;
    c->next=d;
    
    d->row=3;
    d->col=2;
    d->next=e;
    
    e->row=4;
    e->col=4;
    e->next=f;
    sparseMatrix(head,5,5);
    return 0;
}