/*
    (u can also check https://www.geeksforgeeks.org/find-nth-magic-number/ )

whats a magic no. -> 
the nth magic no. is:
convert n to binary
and then keep multipying by 5^index each time and sum all;
(we start the index from right end)
eg: if n=6 binary = 110 so:
     index 1=0 ->    0*5 
     index 2=1 ->  + 1*25 
     index 3=1 ->  + 1*125
                 ------------
            ans =     150 

*/
#include<iostream>
using namespace std;
int magic(int n)
{
    int ans=0;
    int base =5;
    while(n>0)
    {
        int lastDgt= n&1; //bcoz & with 0 gives 0; & with 1 gives the no. itself
                        //so all the no. except the last digit will be converted to 0
        ans+=lastDgt*base;
        base*=5;
        n>>=1; //its same as n=n>>1;
    }
    return ans; 
}
int main()
{
    //find the nth magic no.
    int n=6;
    cout<<magic(n)<<endl;
    return 0;
}
