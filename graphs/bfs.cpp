// psuedo code
/*
Input: A graph G, the source node(or the starting node)

- Algorithm:

- Mark all nodes unvisited

- Mark source node s as visited

enq(Q,s) //First-in first-out Queue------

- while(Q is not empty)
{
    u:=deq(Q);
    //u is the first element  of the q and then pop it form q

    for each unvisited neighbour vertex of u
    {
        mark v as visited;
        enq(Q,v); //for exploration i.e. push all the 
    //neighbours in the explortion q
    }
    

}

*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    // Initializing Queue (Array Implementation)
    queue<int>q;// exploration queue
    //q m daalo, iske sare elements visit krke, node ko 
    //q se nikaldo//mtlb exploration keke nikal do
    
    // BFS Implementation 
    int node;
    int i = 1;
    int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7] = 
    {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
    cout<<endl<<i;
    visited[i] = 1;
    q.push(i); // Enqueue i for exploration
    while (!q.empty())
    {
        int node = q.back();
        q.pop();
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] ==1 && visited[j] == 0){
                cout<<j;
                visited[j] = 1;
                q.push(j);
            }
        }
    }
    return 0;
}
