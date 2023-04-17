//eg: subset of string "abc" are total 8
//i.e:  null, a, ab, ac, abc, b, bc, c

#include<iostream>
using namespace std;
void findSubset(string ans , string st)
{
    if(st.empty())
    {
        cout<<ans<<" ";
        return;
    }

    findSubset(ans, st.substr(1)); //exclude the first letter, and pass the rest of the string
    findSubset(ans+st[0], st.substr(1)); //include the first letter, and pass the rest of the string
}
int main()
{
    string st="abc";
    string ans="";
    findSubset(ans, st);
    return 0;
}