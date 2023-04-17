#include<bits/stdc++.h>
using namespace std;
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int getMax(int arr[], int n)
{
    int m=arr[0];
    for (int i = 0; i < n; i++)
    m=max(m,arr[i]);
    return m;
}
void countSort(int arr[], int n, int exp)
{
    int m=getMax(arr,n);
    int countArray[m+1]={0};

    for(int i=0; i<n; i++)
    countArray[(arr[i]/exp)%10]++;

    //now modify the countArray
    for (int i = 1; i <=m; i++)
    countArray[i]+=countArray[i-1];
    
    int sortedArray[n];
    for(int i=n-1; i>=0; i--)
    sortedArray[--countArray[(arr[i]/exp)%10]]=arr[i];
    //it will not work if we traverse from 0 to n-1)
    //because in this case the pahle wala element will fill the last wali position,
    //but we have to maintain the original order, ie. pahle wala pahle ana chahiye

    //now replacing the original array by the sorted array
    for (int i = 0; i < n; i++)
    {
        arr[i]=sortedArray[i];
    }
}

void radixSort(int arr[], int n)
{
    int m=getMax(arr,n);
    for (int exp = 1; m/exp>0; exp*=10)
    {
        countSort(arr,n,exp);
        cout<<"sorting acc to "<<exp<<" place: ";
        printArray(arr,n);
    }
}

int main()
{
    // for integer array:
    cout<<endl;
    int a[]={170,45,75,90,802,24,2,66};
    cout<<"original array        : ";
    int n=sizeof(a)/sizeof(a[0]);
    printArray(a,n);
    radixSort(a,n);
    cout<<endl;
    return 0;
}
