#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<endl;
    int n;
    int mx=INT_MIN;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        mx=max(mx,arr[i]);
        cout<<mx<<" ";
    }
    
    cout<<endl;
    return 0;
}