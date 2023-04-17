//my approach
#include<iostream>
using namespace std;
int count(int n)
{
    int ans=0;
    if(n==0)return 1;
    else
    {
        int flag=n;
        n=n-2;
        while(n>=flag/2-1)
        {
            if(n==flag-n-2) ans+=count(n)*count(n);
            else
            ans+=2*(count(n)*count(flag-n-2));
            n=n-2;
        }
    }
    return ans;
}
int main()
{
    int n=22;
    cout<<count(n)<<endl;
    return 0;
}