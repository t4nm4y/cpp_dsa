#include<bits/stdc++.h>
using namespace std;

//in hexa decimal system we have 16 digits ie.( 0,1,2,3... 9, A, B, C, ...F ) so here 
// A,B,C,...F represents 10,11,12,...15 repectively.
//eg: 1CF= 'F'*16^0 + 'C'*16^1 + '1'*16^2 = 
//          15*1    +  12*16   +  1 *256  = 463.
int hexaDecimalToDecimal(string n)
{
    int ans =0;
    int temp=1;
    int s=n.size();
    for(int i=s-1; i>=0; i--)
    {
        if (n[i] >= '0' && n[i] <= '9')
        {
            ans+= temp*(n[i] - '0'); 
            // here n[i] is in hash value so the difference by '0' will give the actual integer eg: ('9' - '0') = (57 − 48) = 9.
        }
        else{
            ans+= temp*(n[i]-'A' + 10);
            // here for eg. n[i] is B then: 'B'-'A'= 1 and then +10 will give 11.
        }
        temp*=16;
    }
    return ans;
}
int main()
{
    cout<<endl;
    string n;
    cin>>n;

    cout<<hexaDecimalToDecimal(n);   
    cout<<endl;
    return 0;
}