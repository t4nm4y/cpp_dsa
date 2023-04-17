#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int start, int mid, int end)
{
    //splitting the array in 2 arrays, where s1 ans s2 are the sizes of these 2 arrays
    
    int s1=mid-start+1;
    int s2=end-mid;
    int a1[s1];
    int a2[s2];
    for (int i = 0; i < s1; i++)
    {
        a1[i]=a[start+i];
    }
    for (int i = 0; i < s2; i++)
    {
        a2[i]=a[mid+1+i];
    }

    //now assuming that both the arrays are sorted, 
    //therefore now merging the 2 arrays as the original array(a[])
    // i is the index for a1,
    // j is the index for a2
    // k is the index for a(original array)
    int i=0, j=0,k=start;
    while(i<s1 && j<s2)
    {
        if(a1[i]<a2[j])
        a[k++]=a1[i++];
        else
        a[k++]=a2[j++];
    }
    while(i<s1)
    a[k++]=a1[i++];
    while(j<s2)
    a[k++]=a2[j++];
}
void mergeSort(int a[], int start, int end)
{
    if(start>=end)
    return;
    int mid=(start+end)/2;
    mergeSort(a,start,mid);
    mergeSort(a,mid+1,end);
    merge(a,start,mid,end);
}
int main()
{
    int a[]={4,8,1,3,90,11,43,56};
    int n=sizeof(a)/sizeof(a[0]);
    mergeSort(a,0,n-1);
    cout<<"\nThe Sorted Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}