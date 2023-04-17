/*
given an array and window size
find max element in that window every time
eg: arr= 1  0  2  4  3  7  7  8   and window size 3:
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
// time comp of simple approach that is done by using multiset is: o( NlogN ); see the code in set folder;

//we can reduce its time complexity by using deque; o(LogN) 
int main()
{
    int a[]={1 , 0,  2,  4,  3, 7 , 7,  8 };
    int n=sizeof(a)/sizeof(a[0]);
    int k=3;
    
    deque<int> q;
    vector<int>ans;
    for (int i = 0; i < k; i++)
    {
        while(!q.empty() and q.back()<a[i])
        {
            q.pop_back();
        }
        q.push_back(a[i]);
    }
    ans.push_back(q.front());
    for (int i = k; i < n; i++)
    {
        if(q.front()==a[i-k]) q.pop_front();

        while (!q.empty() and q.back()<a[i])
        {
            q.pop_back();
        }
        q.push_back(a[i]);
        ans.push_back(q.front());
    }
    for(int i: ans) cout<<i<<" ";
    cout<<endl;

    return 0;
}