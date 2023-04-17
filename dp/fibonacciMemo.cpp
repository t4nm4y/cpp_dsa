/* memoization
Time Complexity: O(N)
Reason: bcoz the total number of new subproblems we solve is ‘n’. Hence total time complexity is O(N).

Space Complexity: O(N) + O(N) ≈ O(N)
Reason: We are using a recursion stack space(O(N)) and an vector array (again O(N)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)
*/
#include<iostream>
#include<vector>
using namespace std;

//by simple recursion the time complexity was o(nlogn)
//but by dp its now reduced to o(n)
//this is called Memoizaton to store all the calculated values in the array

int fibonacci(int n, vector<int>v)
{
    if(n<=1) return n;
    if(v[n]!=-1) return v[n]; //return if we have already calculated the val, else:
    v[n]=fibonacci(n-1,v)+fibonacci(n-2,v); //else store the val in the vector;
    return v[n];
}
int main()
{
    int n=5;
    vector<int>v(n+1,-1); //initializing all the values with -1
    cout<<fibonacci(n,v);
    return 0;
}
//we can further reduce the space complexity by not using recursion, 
// this new approach is called tabulation: -> see fiboTabulation.cpp
