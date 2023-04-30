#include<bits/stdc++.h>
using namespace std;
int findPar(const int &node){
        return node;
    }
int main()
{
    // cout<<("abcdef"-"bacdef");
    int a=3;
    int b=findPar(a);
    b++;
    cout<<"a: "<<a;
    cout<<" b: "<<b;
    return 0;
}