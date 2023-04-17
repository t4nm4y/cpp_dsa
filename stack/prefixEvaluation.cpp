#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int prefixEvaluation(string s)
{
    stack<int> st;
    for (int i = s.length()-1; i>=0; i--)
    {
        if (s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            int a,b;
            a=st.top();
            st.pop();
            b=st.top();
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
                st.pop();
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
    cout<<endl<<prefixEvaluation("-+7*45+20")<<endl;

    return 0;
}