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
void display(node *head)
{
    while (head){
    cout<<"\nrow:"<<head->row<<" col:"<<head->col<<" data:"<<head->data;
    head=head->next;
    }
    cout<<endl;
}
node* sparseMatrix(int **arr, int n, int m){
    map<int, int>rmap,cmap;
    node *head = NULL;
    node *curr = NULL;
    node *temp = NULL;
    int i, j;
    for(i = 0; i < n; i++){
        rmap[i]++;
        for(j = 0; j < m; j++){
            cmap[j]++;
            if(arr[i][j] != 0){
                rmap[i]++;
                cmap[j]++;
                temp = new node(arr[i][j]);
                if(head == NULL){
                    head = temp;
                    curr = temp;
                }
                else{
                    curr->row=i;
                    curr->col=j;
                    curr->next = temp;
                    curr = temp;
                }
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
    cout<<"\nThe least sparsed row is:\n"<<least;
    least=0;
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
    return head;
}

int main()
{
    int n, m;
    cout<<"\nEnter the total rows ans colmns of the matrix resp.: ";
    cin >> n >> m;

    int **arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[m];
    }

    cout<<"Enter the values of the matrix: ";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    node *head=sparseMatrix(arr,n,m);
    display(head);
    return 0;
}