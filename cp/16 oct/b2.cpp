#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n,q;
      cin>>n>>q;
      int o=0,e=0;
      long long sum=0;
      for(int i=0;i<n;i++)
      {
          int x;
          cin>>x;
          if(x%2) o++;
          else e++;
          sum+=x;
      }
      long long so=0,se=0;
      while(q--)
      {
          int a,b;
          cin>>a>>b;
          if(a==0)
          {
            se=e*b;
            sum+=se;
            if(b%2)
            {
            o+=e;
            e=0;
            }
          }
          else if(a==1)
          {
              so=o*b;
              sum+=so;
              if(b%2)
              {
              e+=o;
              o=0;
              }
          }
          cout<<sum<<endl;
      }
	}
}