//Given a 2xn board and tiles of size 2x1, count the no. of ways to tile
// the given board using these tiles
#include<bits/stdc++.h>
using namespace std;
int tiling(int n)
{
    if(n==1)
    return 1;
    if(n==0)
    return 0;
    
    //if we place the tile vertically, then the rest of the board reduces to n-1 size
    //if we place the tile horizintally, then the rest of the board reduces to n-2 size
    //now adding the 2 ways gives the ans;
    return tiling(n-1)+tiling(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<tiling(n);
    return 0;
}