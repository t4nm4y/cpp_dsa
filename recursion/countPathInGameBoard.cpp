//count the total no. of ways to go from start to end point.
//(we are using a dice to move)(like we move in snakes and ladders)
//eg: if start,end= 0,3 then there are 4 ways to do so:
//1. 0,1,2,3
//2. 0,1,3
//3. 0,2,3
//4. 0,3

int countPath(int s, int e)
{
    if(s>=e)
    return 0;
    int count=1;
    for (int i = 1; i <=6; i++)
    {
        count+=countPath(s+i,e);
    }
    return count;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,e;
    cin>>s>>e;
    cout<<countPath(s,e);
    return 0;
}