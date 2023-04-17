#include<bits/stdc++.h>
using namespace std;
bool comp(const pair<char,int>&a, const pair<char,int>&b)
{
    return a.second>b.second;
}
int main()
{
    string s; cin>>s;
    vector<pair<char,int> >v(26);
    int n=s.length();
    for(int i=0; i<n; i++) 
    {
        v[s[i]-'a'].first=s[i];
        v[s[i]-'a'].second++;
    }
    sort(v.begin(), v.end(), comp);
    
    int ans=0, i=0;
    while(i<26 && v[i].second>0) ans+=v[i].second*(i++/9+1);
    cout<<ans<<endl;
    return 0;
}

// for(int i=0; i<26; i++)
    // {
    //     cout<<v[i].first<<" -> "<<v[i].second<<endl;
    // }