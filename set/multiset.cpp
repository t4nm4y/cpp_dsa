/*
multiset
all the rules are same as set
only diff is that it can store duplicate elements also


    ---!!!NOTE----
 if we use delete in multiset it will delete all the duplicates also if present
 so if we want to delete only a single element in the duplicates then we can use this:

  s.delete(s.find(3))   //s.find will return the iterator to the first index of the element 
                        and delete will now delete only the single element thet will be present at the iterator
 */
#include<iostream>
#include<set>
using namespace std;
int main()
{
    multiset<int> s1;
    multiset<int,greater<int> > s2;
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