#include<iostream>
using namespace std;
int findUnique(int *a, int n)
{
    int ans=0;
    for (int  i = 0; i < n; i++) ans^=a[i];
    return ans;
}
int main()
{
    int a[]={1,2,4,2,5,1,6,4};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<findUnique(a,n)<<endl;
    return 0;
}