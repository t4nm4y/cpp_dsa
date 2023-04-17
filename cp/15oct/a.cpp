#include<bits/stdc++.h>
using namespace std;
bool sol()
{
    int n, k; cin>>n>>k;
    int a[n];
    bool flag=false;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        if(a[i]==1) flag= true;
    }
    return flag;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        if(sol()) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
    return 0;
}