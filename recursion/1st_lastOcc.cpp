//get the first and last occurence of an element of an array:
#include<bits/stdc++.h>
using namespace std;
int firstOcc(int arr[], int n, int i, int key)
{
    if (i==n)
    return -1;
    if (arr[i]==key)
    return i;
    return firstOcc(arr,n,i+1,key);
}
int lastOcc(int arr[], int n, int i, int key)
{
    if (i==n)
    return -1;
    int restArray=lastOcc(arr,n,i+1,key);
    if(restArray!=-1)
    return restArray;
    if (arr[i]==key)
    return i;
    return -1;
}
int main()
{
    int a[]={4,2,4,1,2,5,2,7};
    int key;
    cin>>key;
    int n=sizeof(a)/sizeof(a[0]);
    cout<<"\nfirst occ: "<<firstOcc(a,n,0,key);
    cout<<"\nlast occ: "<<lastOcc(a,n,0,key)<<endl;
    return 0;
}
