/*
an element can not be duplicate (only single element of each unique val)
by delfault set is in ascending order
but if we want it to be in descentding order then we can use this: 
set<int,greater<int>>s;
*/
#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> s1;
    set<int,greater<int>> s2;
    s1.insert(2);
    s1.insert(9);
    s1.insert(1);
    s1.insert(3);
    s1.insert(1);
    for (auto i: s1) cout<<i<<" ";
    cout<<endl;

    s2.insert(2);
    s2.insert(9);
    s2.insert(1);
    s2.insert(3);
    s2.insert(1);
    for (auto i: s2) cout<<i<<" ";
    
    
    return 0;
}