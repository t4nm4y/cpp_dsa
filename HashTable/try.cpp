#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int info;
    Node *next;
};
Node *temp = NULL;
int main()
{
    temp = new Node;
    temp->info = 10;
    Node *x[10];
    x[0] = temp;

    cout<<(x[0]->info)<<"\n"; 
    

    return 0;
}