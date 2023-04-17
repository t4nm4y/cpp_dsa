#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int start, int mid, int end)
{
    //splitting the array in 2 arrays, where s1 ans s2 are the sizes of these 2 arrays
    int mix[end-start];

    int i=start, j=mid, k=0;
    while(i<mid && j<end)
    {
        if(a[i]<a[j])
        mix[k++]=a[i++];
        else
        mix[k++]=a[j++];
    }
    while(i<mid)
    mix[k++]=a[i++];
    while(j<end)
    mix[k++]=a[j++];

    for(int i=0; i<end-start; i++) a[start+i]=mix[i];
}
void mergeSort(int a[], int start, int end)
{
    if(end-start==1)
    return;
    int mid=(start+end)/2;
    mergeSort(a,start,mid);
    mergeSort(a,mid,end);
    merge(a,start,mid,end);
}
int main()
{
    int a[]={4,8,1,3,90,11,43,56};
    // int a[]={5,4,3,2,1};
    int n=sizeof(a)/sizeof(a[0]);
    mergeSort(a,0,n);
    cout<<"\nThe Sorted Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}