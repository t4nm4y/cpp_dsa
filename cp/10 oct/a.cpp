#include<bits/stdc++.h>
using namespace std;
int sol()
{
    int n; cin>>n;
    int a[n], b[n];
    int d=0, s=0;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    for(int i=0; i<n; i++) if(a[i]!=b[i]) d++;
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0; i<n; i++) if(a[i]!=b[i]) s++;
    if(s<d) return s+1;
    return s;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        cout<<sol();
        cout<<endl;
    }
    return 0;
}