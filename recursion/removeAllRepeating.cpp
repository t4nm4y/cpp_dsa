
#include<bits/stdc++.h>
using namespace std;
string remove(string s)
{
    if(s.empty()) return s;

    int n=s.length();
    string ans="";
    int i=0;
    int flag=-1;

    while(i<n)
    {
        while(s[i]!=s[i+1] && i<n) ans+=s[i++];    
        while (s[i]==s[i+1] && i<n) 
        {
            i++;
            flag=1;
        }
        if(flag==1) i++;
    }
    if(flag!=1) return ans;
    return remove(ans);
}
int main()
{
    string str1 = "geeksforgeeg";
    cout << remove(str1) << endl;

    string str2 = "azxxxzy";
    cout << remove(str2) << endl;

    string str3 = "caaabbbaac";
    cout << remove(str3) << endl;

    string str4 = "gghhg";
    cout << remove(str4) << endl;

    string str5 = "aaaacddddcappp";
    cout << remove(str5) << endl;

    string str6 = "aaaaaaaaaa";
    cout << remove(str6) << endl;

    string str7 = "qpaaaaadaaaaadprq";
    cout << remove(str7) << endl;

    string str8 = "acaaabbbacdddd";
    cout << remove(str8) << endl;

    string str9 = "acbbcddc";
    cout << remove(str9) << endl;  
    return 0;
}
/*

gksfor
ay

g
a

qrq
acac
a

*/