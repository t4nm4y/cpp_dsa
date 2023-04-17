#include<iostream>
using namespace std;

int octalToDecimal(int n)
{
    int ans =0,lastDgt;
    int temp=1;
    while (n>0)
    {
        lastDgt=n%10;
        ans+=lastDgt*temp;
        temp*=8; //for binary to decimal just multiply by 2 ie. temp*=2
        n/=10;
    }
    return ans;
}
int main()
{
    cout<<endl;
    int n;
    cin>>n;

    cout<<octalToDecimal(n);   
    cout<<endl;
    return 0;
}