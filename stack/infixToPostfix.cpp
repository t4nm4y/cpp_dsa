//w3 lab a q5
#include<bits/stdc++.h>
using namespace std;
int postfixEvaluation(string s)
{
    stack<int> st;
    for (int i = 0; i<s.length(); i++)
    {
        if (s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0'); 
        }
        else
        {
            int a,b;
            b=st.top();
            st.pop();
            a=st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(a+b);
                break;
            case '-':
                st.push(a-b);
                break;
            case '*':
                st.push(a*b);
                break;
            case '/':
                st.push(a/b);
                break;
            case '^':
                st.push(pow(a,b));
                break;
            
            default:
                break;
            }
        }
    }
    return st.top();
}
int precedance(char c)
{
    if (c=='^')
        return 3;
    else if(c=='*' or c=='/')
        return 2;
    else if (c=='+' or c=='-')
    {
        return 1;
    }
    else return -1;
}
string infixToPostfix(string s)
{
    stack<int> st;
    string postfix;
    for(int i=0; i<s.length(); i++)
    {
        if (s[i]=='(')
        {
            st.push(s[i]);
        }
        else if (s[i]>='0' && s[i]<='9')
        {
            postfix+=s[i];
        }
        else if (s[i]==')')
        {
            while (!st.empty() && st.top()!='(')
            {
                postfix+=st.top();
                st.pop();
            }
            if(!st.empty())
            st.pop();
        }
        else
        {
            while (!st.empty() && precedance(st.top())>precedance(s[i]))
            {
                postfix+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }   
    }
    while (!st.empty())
        {
            postfix+=st.top();
            st.pop();
        }
    return postfix;
}
string convert_Postfix_Prefix(string s)
{
    stack<char>st;
    string temp;
    for(int i=0; i<s.length(); i++)
    {
        st.push(s[i]);
    }
    while (!st.empty())
    {
        temp+=st.top();
        st.pop();
    }
    return temp;
}
int main()
{
    string s="(4+9*6)-((8-6)/2*4)*9/3";
    cout<<"\nthe orginal exp: "<<s;
    s=infixToPostfix(s);
    cout<<"\npostfix exp: "<< s;
    s=convert_Postfix_Prefix(s);
    cout<<"\nconverted postfix to prefix exp: "<<s;
    s=convert_Postfix_Prefix(s);
    cout<<"\nconverted prefix to postfix exp: "<<s;
    cout<<"\nThe answer is: "<<postfixEvaluation(s);
    cout<<endl;
    return 0;
}