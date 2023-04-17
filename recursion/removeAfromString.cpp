#include<iostream>
#include<string>
using namespace std;
void removeChar(string st, string &ans, char ch)
{
    if(st.empty())
    return;

    char temp=st[0];
    if(temp==ch)

    //substr(int) func passes int index ke baad wali string eg: substr(2) of tanmay = nmay
    removeChar(st.substr(1),ans,ch);
    else
    {   
        // ans+=temp;
        removeChar(st.substr(1),ans+=temp,ch);
    }
}
int main()
{
    string st="tanmay";
    char ch='a';//the character that we want to remove form the string
    //if st is tanmay ans should be tnmy
    string ans="";
    removeChar(st, ans, ch);
    cout<<endl<<ans;
    return 0;
}