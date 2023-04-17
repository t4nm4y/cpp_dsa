// w4 labA q1
#include<bits/stdc++.h>
#include<array>
using namespace std;
void display(stack<int> st)
{
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl; 
}
void SortedInsert(stack<int> &st, int t)
{
    if (st.empty() or st.top()<t)
    {
        st.push(t);
    }
    else
    {
        int top= st.top();
        st.pop();
        SortedInsert(st,t);
        st.push(top);
    } 
}
void sort(stack <int> &st)
{
    if (!st.empty())
    {
        int top=st.top();
        st.pop();
        sort(st);
        SortedInsert(st,top);
    }
    
    
}

int main()
{
    stack <int> st;
    st.push(5);
    st.push(-2);
    st.push(9);
    st.push(-7);
    st.push(3);
    cout<<"\noriginal stack: ";
    display(st);
    sort(st);
    cout<<"\nsorted stack: ";
    display(st);
    return 0;
}