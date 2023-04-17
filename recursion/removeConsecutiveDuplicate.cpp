//remove all consecutive duplicate elements from a string

#include<bits/stdc++.h>
using namespace std;
string removeDuplicate(string s)
{
    if(s.empty())
    return "";
    char ch=s[0];
    string ans=removeDuplicate(s.substr(1));
    if (ans[0]==ch)
    return ans;
    return ch+ans;
    
}
int main()
{
    string s="aaabccccdadd"; //ans: abcdad
    cout<<removeDuplicate(s);   
    return 0;
}