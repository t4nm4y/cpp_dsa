//how many digits if a number is represented in a base;
/* 
working:
eg: log   10  = 3.2, (ie, 2^(3.2)=10 ) it means how many times has 2 been multiplied to get 10,
        2                              here it is 3.2 ie(3+something) so the ans is 4

    so how do we get this 4? ->
    log   10 = (log   10 ) / (log   2) =  3.2 ----> now we need to convert it into int, 
        2           x             x                 int(3.2)=3 and finally add 1 to get the ans. //3+1= 4     
 (this is a log formula where x can be any base)

 we can verify it by seeing that binary represen. of 10 is 1010, which has 4 digits
*/
#include<iostream>
#include<math.h>
using namespace std;
int digits(int n, int b)
{
    return (int)(log(n)/log(b)) +1;
}
int main()
{
    int n=10;
    int base=2;
    cout<<digits(n,base)<<endl;
    return 0;
}