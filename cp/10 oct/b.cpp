#include<bits/stdc++.h>
using namespace std;
bool sol()
{
    int n; cin>>n;
    int prev=INT_MAX, curr;
    for(int i=0; i<n; i++) {
        cin>>curr;
        if(curr>prev) 
        {
            if(curr%prev==0)
            return false;
        }
        prev=curr;
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        if(sol()) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
    return 0;
}