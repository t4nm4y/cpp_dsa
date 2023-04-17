#include<iostream>
using namespace std;
char findUnique(char *a, int n)
{
    int ans;
    for (int  i = 0; i < n; i++) ans^=a[i];
    return ans;
}
int main()
{
    char st[]="abbbc";
    int n=sizeof(st)/sizeof(st[0]);
    cout<<findUnique(st,n)<<endl;
    return 0;
}