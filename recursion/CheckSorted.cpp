//check if the given array is sorted or not using recursion
#include<bits/stdc++.h>
using namespace std;
bool checkSorted(int a[], int n)
{
    if (n==1)
    return true;
    return (a[0]<a[1] && checkSorted(a+1,n-1));
}
int main()
{
    int arr[]={1,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<checkSorted(arr, n);
}