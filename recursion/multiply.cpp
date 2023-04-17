#include<bits/stdc++.h>
using namespace std;
int multiplication(int m, int n)
{   
    if (n==0)
    {
        return 0;
    }
    n--;
    
    return m+multiplication(m,n);   
}
int main()
{
    int m,n;
    cout<<"enter the 2 nos.: ";
    cin>>n>>m;
    cout<<multiplication(m,n)<<endl<<endl;
    return 0;
}