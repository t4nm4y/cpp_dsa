#include<bits/stdc++.h>
using namespace std;
int interpolationSearch(int a[],int n, int key)
{
    int start=0, end=n-1;
    while (start<=end && key>=a[start] && key<=a[end])
    {
        if (start==end)
        {
            return -1;
        }
        int pos= start+(key-a[start])/(a[end]-a[start])*(end-start);
        if (key==a[pos])
        {
            return pos;
        }
        else if (key>a[pos])
        {
            start=pos+1;
        }
        else end=pos-1;
    }
    return -1;
}
int main()
{
    int n,key;
    cout<<"\nEnter the size of the array: ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the elements of the array: ";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"\nenter the element u wanna search: ";
    cin>>key;
    cout<<endl<<interpolationSearch(a,n,key)<<endl;
    return 0;
}