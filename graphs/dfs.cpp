//pseudo code
/*
DFS(G, u)  //where u is the selected node at that time
{
    cout<<u;
    u.visited = true

    for each v € (belongs to)  G.Adj[u]  //that is sare vo elements jinpe u se edge hei
        if v.visited == false  //agar its not visited then we will run dfs on it
            DFS (G,v)
}

initialization() 
{
    For each u or vertex belongs to G //make all the node unvisited
        u.visited = false

    //select any node and run dfs function on it
        DFS (G, u)
}
*/
#include<bits/stdc++.h>
using namespace std;
 
int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0}, 
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
 
//here since recursion already use stack data type , therefore hame usse manually krne ki zarurat nhi padi
void DFS(int i){
    cout<<i;
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if(a[i][j]==1 && !visited[j]){
            DFS(j);
        }
    }
}
 
int main(){ 
    cout<<endl;
    // DFS Implementation 

    //we can start from any node eg:
    //DFS(2); this will start from 2 (or)
    //DFS(4); this will start from 4 (or)
    
    DFS(0); //this will start from 0 etc...

    return 0;
}
