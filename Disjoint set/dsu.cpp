//dsu disjoint set union
#include<bits/stdc++.h>
using namespace std;
//assuming max size os 10^5
int parent[100000]; 
int rank[100000];

//this func will intialize all the nodes
void makeSet()
{
    //if there are n nodes;
    for(int i=0; i<n; i++) 
    {
        //as in starting they will all be alone and they will be parent of themselves
        parent[i]=i;
        //as they will not have any children so the rank=0;
        rank[i]=0;
    }
}

int findPar(int node)
{
    if(node==parent[node]) return node;
    return parent[node]=findPar(parent[node]); //becoz (parent of the parent of the node and so onn) till we reach the final parent. this final parent will be the ans;
    
}

void Union(int u, int v)
{
    u=findPar(u);
    v=findPar(v);

    //we can simply do
    parent[u]=v;
    
    //or we can do it more organised way: 
    // if(rank[u]<rank[v]) parent[u]=v;
    // else if(rank[v]<rank[u]) parent[v]=u;
    // else
    // { 
    //     parent[v]=u; rank[u]++;
    // }
}
int main()
{
    makeset();
    //for eg if there are m edges in a graph
    cin>>m;
    while(m--)
    {
        int u, v; cin>>u>>v;
        Union(u,v);
    }

    //to check if a,b belong to the same component or not:
    if(findPar(a)==findPar(b)) return true; else false;
    return 0;
}