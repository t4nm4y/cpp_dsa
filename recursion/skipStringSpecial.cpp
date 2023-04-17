//the special condition is for eg: skip the string "app" from the given string only if its not apple
//eg if string = "tappnmyapplendapp" then ans should be "tnmyapplend"

#include<iostream>
using namespace std;

void skipStringSpecial(string st, string &ans, string skip, string dontSkip, int sslen, int dslen)
{
    if(st.empty())
    return;
    
    if (st.substr(0,sslen)==skip && st.substr(0,dslen)!=dontSkip)
    skipStringSpecial(st.substr(sslen), ans, skip,dontSkip,sslen,dslen);
    else 
    skipStringSpecial(st.substr(1), ans+=st[0], skip,dontSkip,sslen,dslen);
}
int main()
{
    
    //given
    string st="tappnmyapplendapp";
    string skip="app";
    string dontSkip="apple"; //skip app but not apple
    
    string ans="";
    int sslen=skip.length();
    int dslen=dontSkip.length();
    skipStringSpecial(st, ans, skip, dontSkip, sslen, dslen);
    cout<<ans;
    return 0;
}