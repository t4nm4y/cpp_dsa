//you can only move like a haathi in a chess, and have to reach the end of the maze
//apna colg
#include<bits/stdc++.h>
using namespace std;
int countPathMaze(int n, int m, int i, int j)
{
    if(i==m-1 && j==n-1)
    return 1;
    if (i>=m || j>=n)
    return 0;
    
    return countPathMaze(n,m,i+1,j)+ countPathMaze(n,m,i,j+1); 
}
int main()
{
    int n,m;
    cout<<"\nenter the no. of rows: ";
    cin>>n;
    cout<<"enter the no. of columns: ";
    cin>>m;
    cout<<countPathMaze(n,m,0,0);
    return 0;
}