#include<iostream>
using namespace std;
bool isPow2(int n)
{
    if(n==0)return false;
    if((n&(n-1))==0) return true;
    return false;
}
int main()
{
    int n=8;
    cout<<isPow2(n)<<endl;
    return 0;
}