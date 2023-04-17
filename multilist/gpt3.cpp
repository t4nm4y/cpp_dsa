#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

// create a sparse matrix using list of lists and print rows and columns
int sparse_matrix(int **arr, int n, int m){
    Node *head = NULL;
    Node *curr = NULL;
    Node *temp = NULL;
    Node *prev = NULL;
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(arr[i][j] != 0){
                temp = new Node;
                temp->data = arr[i][j];
                temp->next = NULL;
                if(head == NULL){
                    head = temp;
                    curr = temp;
                }
                else{
                    curr->next = temp;
                    curr = temp;
                }
            }
        }
    }
    curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    return 0;
}

int main(){
    int n, m;
    cin >> n >> m;
    int **arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    sparse_matrix(arr, n, m);
    return 0;
}
