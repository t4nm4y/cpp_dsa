#include<bits/stdc++.h>
using namespace std;
bool check(string s)
{
    int n=s.size();
    stack<char> st;
    bool ans=true;
    for (int i = 0; i < n; i++)
    {
        if (s[i]=='{' or s[i]=='[' or s[i]=='(')
        {
            st.push(s[i]);
        }
        if(s[i]=='/' && s[i+1]=='*')
            {
                st.push(s[i]);
                st.push(s[i+1]);
            }
        if(!st.empty())
        {
            if (s[i]=='*' && s[i+1]=='/')
            {
                if (st.top()=='*')
                {
                    st.pop();
                    st.pop();
                } 
                else
                {
                    ans=false;
                    break;
                }
            } 
            else if (s[i]=='}')
            {
                if (st.top()=='{')
                {
                    st.pop();
                }
                else
                {
                    ans=false;
                    break;
                }
            }
            else if (s[i]==')')
            {
                if (st.top()=='(')
                {
                    st.pop();
                }
                else
                {
                    ans=false;
                    break;
                }
            }
            else if (s[i]==']')
            {
                if (st.top()=='[')
                {
                    st.pop();
                }
                else
                {
                    ans=false;
                    break;
                }
            }
            else if (s[i]=='}')
            {
                if (st.top()=='{')
                {
                    st.pop();
                }
                else
                {
                    ans=false;
                    break;
                }
            }
            else if (s[i]=='}')
            {
                if (st.top()=='{')
                {
                    st.pop();
                }
                else
                {
                    ans=false;
                    break;
                }
            }
        }   
    }
    if (!st.empty())
    {
       return false;
    }
    return ans;
}
int main()
{
    string s="{(/*[]*/)}";
    if(check(s))
    cout<<"\nBalanced.";
    else cout<<"\nNot balanced";
    return 0;
}