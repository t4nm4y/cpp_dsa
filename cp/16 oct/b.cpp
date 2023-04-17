#include<bits/stdc++.h>
using namespace std;
void sol()
{
    go_fast
    
    int n,q; cin>>n>>q;
    int a[n], e=0, o=0;
    long long int ans=0;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        ans+=a[i];
        if( (a[i]&1)==0 ) e++;
        else o++;
    }
    int t,c;
    for(int j=0; j<q; j++)
    {
        cin>>t>>c;
        if(t==0)
        {
            for(int i=0; i<n; i++)
            {
                if( (a[i]%2)==0 ) {
                    a[i]+=c;
                    ans+=c;
                }
            }
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                if( (a[i]%2)==1 ) {
                    a[i]+=c;
                    ans+=c;
                }
            }
        }
        cout<<ans<<endl;
    }

}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        sol();
        // cout<<endl;
    }
    return 0;
}