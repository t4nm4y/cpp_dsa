// w3 labA q4
#include<bits/stdc++.h>
using namespace std;

int decimalToBase(int n, int base)
{
    int ans = 0;
    int x=1;
    while (x<n)
    {
        x*=base;
    }
    x/=base;

    while (x>0)
    {
        int lastDgt=n/x;
        n%=x;
        x/=base;
        ans=(ans*10+lastDgt);
        cout<<"ans is: "<<ans<<"  ";
    }
    return ans;
}
int main()
{
    cout<<endl;
    int n;
    int b; 
    cout<<"\nEnter the no.(Decimal): ";
    cin>>n;
    cout<<"Enter the new Base: ";
    cin>>b;
    if (b>=2 && b<=9)
    {
        cout<<decimalToBase(n,b);    
        cout<<endl;
    }
    else cout<<"\ninvalid base\n";
    return 0;
}