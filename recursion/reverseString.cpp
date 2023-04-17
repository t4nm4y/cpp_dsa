#include<bits/stdc++.h>
using namespace std;
void reverse(string s)
{
    if(s.empty())
    return;
    //s.substr will return the rest of the string after in the index(including the index)
    // eg: if s=abcdef, then s.substr(2)=cdef, s.substr(4)=ef
    reverse(s.substr(1));
    cout<<s[0];
}
int main()
{
    string s;
    cin>>s;
    reverse(s);   
    return 0;
}