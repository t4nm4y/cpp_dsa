//print all the permutations of a string 
// eg; abc= abc, acb, bac, bca, cab, cba
#include<bits/stdc++.h>
using namespace std;
void permString(string s, string ans)
{
    if (s.empty())
    {
        cout<<ans<<" ";
        return;
    }
    
    for (int i = 0; i < s.length(); i++)
    {
        char ch=s[i];
        string ros= s.substr(0,i)+s.substr(i+1); 
        permString(ros,ans+ch); //fix one element and call recursion to the get the permutations of rest of the string
    }
    
     
}
int main()
{
    string s;
    cin>>s;
    permString(s,"");
    return 0;
}