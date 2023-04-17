#include<bits/stdc++.h>
using namespace std;
void sol()
{
    int n; cin>>n;
    int a[n], c=0;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        //if(a[i]==n) ind=i;
    }
    for(int i=n-1; i>=1; i--)
    {
        if(a[i]>=a[i-1]) continue;
        c++;
        cout<<i+1<<" ";
        a[i]+=c;
        if(a[i]<a[i-1]) i++;
    }
    while(c!=n){
        c++;
        cout<<1<<" ";
    }
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        sol();
        cout<<endl;
    }
    return 0;
}