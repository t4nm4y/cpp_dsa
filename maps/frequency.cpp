//code for finding the frequency of each element in the array(can be unsorted)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    map<int,int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++; //-->this is same as:  
                      // (
                      //  int c = freq[a[i]];
                      //  freq[a[i]] = ++c;  
                      // )
    }
    map<int,int> :: iterator it;
    for (it=freq.begin(); it!=freq.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    
    return 0;
}