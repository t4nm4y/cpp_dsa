#include<iostream>
using namespace std;

int binaryToDecimal(int n)
{
    int ans =0,lastDgt;
    int temp=1;
    while (n>0)
    {
        lastDgt=n%10;
        ans+=lastDgt*temp;
        temp*=2; //for octal to decimal just multiply by 8 ie. temp*=8
        n/=10;
    }
    return ans;
}
int main()
{
    cout<<endl;
    int n;
    cin>>n;

    cout<<binaryToDecimal(n);   
    cout<<endl;
    return 0;
}