#include<bits/stdc++.h>
using namespace std;
void sol()
{
    int a,b,c,d; cin>>a>>b>>c>>d;
    vector<int>xa,xb,ya,yb;
    int t=a*b;
    // bool af=false, bf=false;
    for(int i=a+1; i<=c; i++) {
        if(i%a==0) xa.push_back(i);
        if(i%b==0) xb.push_back(i);
    }
    for(int i=b+1; i<=d; i++) {
        if(i%a==0) ya.push_back(i);
        if(i%b==0) yb.push_back(i);
    }
    for(int i=0; i<xa.size(); i++)
    {
        for(int j=0; j<yb.size(); j++)
        {
            int k=xa[i]*yb[j];
            if(k%t==0)
            {
                cout<<xa[i]<<" "<<yb[j]<<endl;
                return;
            }
            else if( xa[i]%t==0 )
            {
                cout<<xa[i]<<" "<<d<<endl;
                return;
            }
            else if( yb[j]%t==0 )
            {
                cout<<c<<" "<<yb[j]<<endl;
                return;
            }
        }
    }
    for(int i=0; i<xb.size(); i++)
    {
        for(int j=0; j<ya.size(); j++)
        {
            int k=xb[i]*ya[j];
            if(k%t==0)
            {
                cout<<xb[i]<<" "<<ya[j]<<endl;
                return;
            }
            else if( xb[i]%t==0 )
            {
                cout<<xb[i]<<" "<<d<<endl;
                return;
            }
            else if( ya[j]%t==0 )
            {
                cout<<c<<" "<<ya[j]<<endl;
                return;
            }
        }
    }
    cout<<-1<<" "<<-1<<endl;
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