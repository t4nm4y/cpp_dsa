#include<iostream>
using namespace std;
bool checkPrime(int n)
{
    int i=2;
    while(i*i<=n) //or i is less than sqrt(n)
    {
        if(n%i==0) return false;
        i++;
    }
    return true;
}
int main()
{
    int n=12;
    cout<<checkPrime(n);
    cout<<endl;
    return 0;
}