
        //remove all adjacent duplicates elements from a string
// aabc -> bc 
// aabb -> empty
// azxxzy -> ay
// aaab -> ab

#include<bits/stdc++.h>
using namespace std;
string remove(string s)
{
    int n=s.length();
    string ans;
    int i=0;
    int flag=-1;

    while(i<n)
    {
        while(s[i]!=s[i+1] && i<n) 
        {
            ans+=s[i++];    
        }
        // while (s[i]==s[i+1] && i<n) 
        // {
        //     i++;
        //     flag=1;
        // }
        // if(flag==1) i++;
    }
    if(flag!=1) return ans;
    return remove(ans);
}
int main()
{
    string st="ay";
    cout << remove(st) << endl; 
    
    return 0;
}