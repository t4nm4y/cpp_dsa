/*
given an array and window size
find max element in that window every time
eg: arr= 1  0  2  4  3  7  7  8   and window size 3 than ans would be:
         \_____/
           2\_____/
              4\_____/
                 4\_____/
                     7\_____/
                       7\_____/
                           8
   ans will be 2,4,4,7,7,8
*/
#include<iostream>
#include<deque>
#include<vector>
#include<set>
using namespace std;
// time comp of this approach is: o( NlogN );
//we can reduce its time complexity by using deque; see the code in deque folder;
int main()
{
    int a[]={1 , 0,  2,  4,  3, 7 , 7,  8 };
    int n=sizeof(a)/sizeof(a[0]);
    int k=3;
    
    multiset<int, greater<int> >s;
    vector<int>ans;
    for (int i = 0; i < k; i++)
    {
        s.insert(a[i]);
    }
    ans.push_back(*s.begin());
    for (int i = k; i < n; i++)
    {
        s.erase(s.find(a[i-k]));
        s.insert(a[i]);
        ans.push_back(*s.begin());
    }
    for(int i: ans) cout<<i<<" ";
    cout<<endl;

    return 0;
}