#include<iostream>
#include<stack>
#include<string>
using namespace std;
string removeDuplicates(string str)
{
    stack<char>stk;
    int n=str.length();
    int i=0;
    while (i<n)
    {
        if(str[i]!=str[i+1])
        {
            if(stk.empty()) stk.push(str[i]);
            else if(stk.top()==str[i]) stk.pop();
            else stk.push(str[i]);
            i++;
        }
        else i+=2;
    }
    int k=stk.size();
    // cout<<"size is: "<<k<<" ";
    if(k==0) return "";
    char ans[k+1];
    if(k!=0)  
    {
        for (int i = k-1; i>=0; i--)
        {
            ans[i]=stk.top();
            stk.pop();
        }
        ans[k]='\0';
    }
    
    return ans;
}
int main()
{
    string st="abbaca"; //ans should be ca
    // string st="aac"; //ans should be c
    cout<<removeDuplicates(st)<<endl;
    return 0;
}