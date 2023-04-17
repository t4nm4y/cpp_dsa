#include<bits/stdc++.h>
using namespace std;
void AllsubStrings(string s, string ans)
{
    if (s.empty())
    {
        cout<<ans<<" ";
        return;
    }
    char ch=s[0];
    AllsubStrings(s.substr(1), ans);
    AllsubStrings(s.substr(1), ans+ch);
}
int main()
{
    string s;
    cin>>s;
    AllsubStrings(s,"");
    cout<<endl;
    return 0;
}