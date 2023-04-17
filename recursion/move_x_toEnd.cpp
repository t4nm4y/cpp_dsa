//move all x in the string to the end of the string
// eg abxxcxdx will be abcdxxxx
#include<bits/stdc++.h>
using namespace std;
string moveXtoend(string s)
{
    if(s.empty())
    return "";
    char ch=s[0];
    string ans=moveXtoend(s.substr(1));
    if (ch=='x')
    return ans+ch;
    return ch+ans;
    
}
int main()
{
    string s;
    cin>>s;
    cout<<moveXtoend(s);   
    return 0;
}