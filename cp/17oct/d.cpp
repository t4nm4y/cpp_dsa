#include<bits/stdc++.h>
using namespace std;
string sol()
{
    int n; cin>>n;
    string s; cin>>s;
    string ans;
    int start=-1, t=-1;
    for(int i=0; i<n; i++) {
        if(s[i]=='1'){
            start=i;
            break;
        }
    }
    if(start==-1) return "0";
    for(int i=start+1; i<n; i++) {
        if(s[i]=='0'){
            t=i;
            break;
        }
    }
    if(t==-1)
    {
        for(int i=start; i<n; i++) ans.push_back('1');
        return ans;
    }
    ans=s.substr(start);
    vector<int>v;
    for(int i=t; i<n; i++)
    {
        if(s[i]=='0') v.push_back(i-t);
    }
    vector<bool>f(v.size(), false);

    for(int i=t-1; i>=start; i--)
    {
        for(int j=0; j<v.size(); j++)
        {
            if(!f[j])
            {
                if(s[i+v[j]]=='1') {
                    f[j]=true;
                    
                    for(int temp=j+1; temp<f.size(); temp++) f[temp]=false;
                }
            }
            else
            {
                if(s[i+v[j]]=='1') continue;
                break;
            }
        }
    }
    for(int i=0; i<f.size(); i++)
    {
        if(f[i])
        {
            ans[t+v[i]]='1';
        }
    }
    return ans;
}
int main()
{    
    cout<<sol();
    return 0;
}