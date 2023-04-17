#include<iostream>
#include<string>
using namespace std;
void skipString(string st, string &ans, string skip, int n)
{
    if(st.empty())
    return;

    if (st.substr(0,n)==skip)
    skipString(st.substr(n), ans, skip, n);
    else 
    skipString(st.substr(1), ans+=st[0], skip, n);
}
int main()
{
    string st="tanmayanmtyranm";
    string skip="nm";
    int n=skip.length();
    string ans="";
    skipString(st,ans,skip,n);
    cout<<ans;
    return 0;
}