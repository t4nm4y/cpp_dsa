// w4 labA q5
#include<bits/stdc++.h>
using namespace std;
void hailstorm(int n)
{
    if (n==1)
    {
        return;
    }
    
    else if (n%2==0)
    {
        n/=2;
        cout<<n<<" ";
        hailstorm(n);
    }
    else 
    {
        n=3*n+1;
        cout<<n<<" ";
        hailstorm(n);
    }
}
int main()
{
    int n;
    cout<<"\n enter any no.: ";
    cin>>n;
    hailstorm(n);
    return 0;
}