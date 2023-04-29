//dsu disjoint set union
// very good tuturial    https://www.youtube.com/watch?v=aBxjDBC4M1U&ab_channel=takeUforward
#include<bits/stdc++.h>
using namespace std;

//creating a template
class DisjointSet{
    vector<int>rank,parent;
    vector<int>size; //if doing by size

public:
    //constructor
    DisjointSet(int n){ // making the size n+1 so it can work for both 1 and 0 based indexing
        parent.reserve(n+1);
        rank.resize(n+1,0); //as they will not have any children so the rank=0;
        size.resize(n+1,1); //as they only have one node so the size=1;
        for(int i=0; i<=n; i++) parent[i]=i; //as in starting they will all be alone so, they will be  parent of themselves
    }

    int findPar(int node){
        if(parent[node]==node) return node;

        //since we are updating the parent of the nodes while finding them , this is callled path compression
        return parent[node]=findPar(parent[node]); //(parent of the parent of the node and so onn) till we reach the final parent. this final parent will be the ans;
    }

    void unionByRank(int u, int v){  //rank is basically the height
        int pu=findPar(u), pv=findPar(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]) parent[pu]=pv; //since smaller is getting attatched to larger the rank will not increase
        if(rank[pv]<rank[pu]) parent[pv]=pu;
        else {
            parent[pv]=pu;
            rank[pu]++;
        }
    }

    void unionBysize(int u, int v){ // size is the no. of nodes in a group
        int pu=findPar(u), pv=findPar(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]) {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

//trying the template
int main(){
    DisjointSet ds(7);
    ds.unionBysize(1,2);
    ds.unionBysize(2,3);
    ds.unionBysize(4,5);
    ds.unionBysize(6,7);
    ds.unionBysize(5,6);
    if(ds.findPar(3)==ds.findPar(7)) cout<<1; else cout<<0<<" ";
    ds.unionBysize(3,7);
    if(ds.findPar(3)==ds.findPar(7)) cout<<1;
    return 0;
}