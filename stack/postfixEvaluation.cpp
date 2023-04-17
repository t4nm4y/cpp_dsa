#include<bits/stdc++.h>
#include<math.h>
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
int main()
{
    cout<<endl<<postfixEvaluation("46+2/5*7+")<<endl;

    return 0;
}