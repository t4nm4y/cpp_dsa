#include<bits/stdc++.h>
using namespace std;
int sol()
{
    int n; cin>>n;
    int a[n];
    bool flag;
    int c=n;
    for(int i=0; i<n; i++) 
    {
        cin>>a[i];
        while((a[i]&1)==0)
        {
            c--;
            a[i]/=2;
        }
    }
    if(c<=0) return 0;
    int ans=0;
    vector<int>v;
    for(int i=2; i<=n; i+=2)
    {
        int k=i, t=0;
        while((k&1)==0)
        {
            t++;
            k/=2;
        }
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for(int i=v.size()-1; i>=0; i--)
    {
        ans++;
        c-=v[i];
        if(c<=0) return ans;
    }
    return -1;
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