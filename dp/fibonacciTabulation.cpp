/* tabulation:
Time Complexity: O(N)
Reason: We are running a simple iterative loop

Space Complexity: O(N)
Reason: We are using an external array of size ‘n+1’.
*/
#include<iostream>
#include<vector>
using namespace std;

//using tabulation to solve the same problem --recursion free approach
//here the space complexity further reduces to half!
//bcoz here we will not use the n size stack that we used in recursion

int main()
{
    int n=5;
    vector<int>v(n+1,-1); //initializing all the values with -1
    v[0]=0;
    v[1]=1;
    for (int i = 2; i <=n; i++)
    {
        v[i]=v[i-1]+v[i-2];
    }
    cout<<v[n];
    return 0;
}
//space optimization:
//we can further reduce the space complexity by not even using vector
//by which the space complexity will reduce to constant! ie 0(1)-> see fibboSpaceOpt.cpp