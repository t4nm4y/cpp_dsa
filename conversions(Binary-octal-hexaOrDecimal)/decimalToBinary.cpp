#include<bits/stdc++.h>
using namespace std;


//this is method1:
int decimalToBinary(int n)
{
    int x=1;
    int ans = 0;
    while (x<=n)
    {
        x*=2;
    }
    x/=2;

    while (x>0)
    {
        int lastDgt=n/x;
        n%=x;
        x/=2;
        ans+=(ans*10+lastDgt);
    }
    return ans;
}


//this is method2
void decimalToBinary_method2(int n){
    int i=0;
    int a[10];
   while (n>0)
   {
       a[i]=n%2;
        n=n/2;
        i++;
   }
   //a[] array will store the remainder and it will be in reverse order
   //so for the final ans we will have to cout the reverse of the array:
   for (int j = i-1; j >= 0; j--)
   {
       cout<<a[j];
   }
   
} 


int main()
{
    cout<<endl;
    int n;
    cin >> n;
    // cout<<decimalToBinary(n);
    decimalToBinary_method2(n);
    cout<<endl;
    return 0;
}