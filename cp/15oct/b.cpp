#include<bits/stdc++.h>
using namespace std;
int sol()
{
    int n; cin>>n;
    int a[n], b[n], o=0, z=0;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b, b+n);
    for(int i=0; i<n; i++) {
        if(a[i]!=b[i])
        {
            if(a[i]==1) o++;
            else z++;
        }
    }
    return min(z,o)+abs(z-o);
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