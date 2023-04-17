#include<bits/stdc++.h>
using namespace std;
int sol()
{
    int n; cin>>n;  
    string s; cin>>s;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    int ans=0;
    for(int i=0; i<n-1; i++)
    {
        if(s[i]=='1') ans+=a[i];
        else
        {
            if(s[i+1]=='0') continue;
            int j=i+1, ind=i+1;
            while(j<n && s[j]=='1'){
                if(a[j]<a[ind]) ind=j;
                j++;
            }
            if(a[i]>a[ind]){
                 ans+=a[i];
                s[ind]='0';
            }
        }
    }
    if(s[n-1]=='1') ans+=a[n-1];
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