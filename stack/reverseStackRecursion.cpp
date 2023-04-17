#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &st, int el)
{
    if (st.empty())
    {
        st.push(el);
        return;
    }
    
    int t=st.top();
    st.pop();
    insertAtBottom(st,el);
    st.push(t);
}
void reverse(stack<int> &st)
{
    if(st.empty())
    {
        return;
    }
    int el=st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,el);
}
void display(stack<int> st)
{
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl; 
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    // reverse(st);
    display(st);
    return 0;
}