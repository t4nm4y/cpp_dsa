#include<bits/stdc++.h>
using namespace std;

string decimalToHexaDecimal(int n)
{
    int x=1;
    string ans="";
    while (x<n)
    {
        x*=16;
    }
    x/=16;
    while (x>0){
        int lastsDgt=n/x;
        n-=lastsDgt*x;
        x/=16;
        if (lastsDgt<=9)
        {
            ans+=to_string(lastsDgt);
            //to string func converts interger to string data type eg. to_string(10) = '10'.
        }
        else{
            int temp='A'+lastsDgt-10;
            ans.push_back(temp);
            // push back func is used to add something into the last of the string.
        }
    }
    return ans;
}

int main()
{
    cout<<endl;
    int n;
    cin >> n;
    cout<<decimalToHexaDecimal(n);
    cout<<endl;
    return 0;
}