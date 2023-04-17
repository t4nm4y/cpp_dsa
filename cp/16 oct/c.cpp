#include<bits/stdc++.h>
using namespace std;
int sol()
{
    int n; cin>>n;
    char c; cin>>c;
    string s; cin>>s;
    if(c=='g') return 0;
    vector<int>v;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='g') v.push_back(i);
    }
    int sz=v.size();
    int ans=INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(s[i]==c)
        {
            if(i>v.back()) ans=max( ans, n-(i-v.front()) );
            else {
                auto ind=upper_bound(v.begin(), v.end(), i);
                ans=max( ans, *ind-i );
            }
        } 
    }
    return ans;
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