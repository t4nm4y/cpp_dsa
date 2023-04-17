#include<bits/stdc++.h>
using namespace std;
// int find(vector<int>&a)
int find(int a[],int n)
{
    int dp[n]={-1};
    int maxLen=1;
    dp[n-1]=1;
    for (int i = n - 2; i >= 0; i--)
    {
        if(a[i+1]>a[i]) 
        {
            dp[i]=1+dp[i+1];
            maxLen=dp[i];
        }
        else if(a[i+1]==a[i]) dp[i]=dp[i+1];
        else
        {
            int m=0;
            for(int j=i+1; j<n; j++)
            {
                if(a[j]>a[i])
                {
                    if(dp[j]>m) m=dp[j];
                }
            }
            dp[i]=m;
            if(m>maxLen) maxLen=m;
        }
    }
    return maxLen;

}
int main()
{
    // vector<int>a{6,3,7,4,6,9};
    int a[]={6,3,7,4,6,9};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<find(a,n);
    return 0;
}