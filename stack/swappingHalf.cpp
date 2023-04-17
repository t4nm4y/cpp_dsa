// swapping first half of no.1 with the last half of the other no. and vice versa.
// eg: no.1= 1234;  no.2: 5678 then after swapping no1= 7834, no.2=5612
#include<bits/stdc++.h>
using namespace std;
void display(stack<int>st)
{
    while (!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}
void swap(int a, int b, int size)
{
    stack<int>st1;
    stack<int>st2;
    for (int i = 0; i < size/2; i++)
    {
        st1.push(a%10);
        a/=10;
    }
    for (int i = 0; i < size/2; i++)
    {
        st1.push(b%10);
        b/=10;
    }
    for (int i = 0; i < size/2; i++)
    {
        st2.push(a%10);
        a/=10;
    }
    for (int i = 0; i < size/2; i++)
    {
        st2.push(b%10);
        b/=10;
    }
    cout<<"\n\nAfter Swapping:\nNumber 1: ";
    display(st1);
    cout<<"\nNumber 2: ";
    display(st2);
}
int main()
{
    int a,b;
    cout<<"\nEnter the two nos. of equal digits:";
    cin>>a>>b;
    cout<<"\noriginal nos:\nNumber 1: "<<a<<"\nNumber 2: "<<b;

    int temp=a;
    int size=0;
    while(temp>0)
    {
        size++;
        temp/=10;
    }
    
    swap(a,b,size);
    return 0;
}