//space optimization:
/*
Time Complexity: O(N)
Reason: We are running a simple iterative loop

Space Complexity: O(1)
Reason: We are not using any extra space
*/

#include<iostream>
#include<vector>
using namespace std;

//space optimization:
//we can further reduce the space complexity by not even using vector
//by which the space complexity will reduce to constant! ie 0(1)

int main()
{
    int n=5;
    int prev2=0;
    int prev=1;
    for (int i = 2; i <=n; i++)
    {
       int curr=prev2+prev;
       prev2=prev;
       prev=curr;
    }
    cout<<prev;
    return 0;
}
