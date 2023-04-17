#include<bits/stdc++.h>
using namespace std;


// method1
int decimalToOctal(int n)
{
    int ans = 0;
    int x =1;
    while(x<n) {
        x*=8;
    }
    x/=8;
    while (x>0)
    {
        int lastDigit=n/x;
        n-=lastDigit*x;
        x/=8;
        ans= ans*10 + lastDigit;
    }
    return ans;
}


//this is method2 similar to the decimal to binary
void decimalToOctal_method2(int n){
    int i=0;
    int a[10];
   while (n>0)
   {
       a[i]=n%8;
        n=n/8;
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
    cin>>n;
    cout<<decimalToOctal(n);  
    // decimalToOctal_method2(n);  
    cout<<endl;
    return 0;
}