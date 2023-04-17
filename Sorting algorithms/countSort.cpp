//1. find the count of every distinct element
//2. Calculating the position of each element jo uski fianlly sorted array me hogi
#include<bits/stdc++.h>
using namespace std;

void countSortint(int arr[], int n)
{
    int m=arr[0];
    for (int i = 0; i < n; i++)
    m=max(m,arr[i]);

    int countArray[m+1]={0};
    for(int i=0; i<n; i++)
    countArray[arr[i]]++;
    //now modify the countArray
    for (int i = 1; i <=m; i++)
    countArray[i]+=countArray[i-1];
    
    int sortedArray[n];
    // for(int i=n-1; i>=0; i--)
    // sortedArray[--countArray[arr[i]]]=arr[i];
    for(int i=0; i<n; i++)
    sortedArray[--countArray[arr[i]]]=arr[i];

    //now replacing the original array by the sorted array
    for (int i = 0; i < n; i++)
    {
        arr[i]=sortedArray[i];
    }  
}

void countSortchar(char arr[], int n)
{
    //converting the char arr to integer
    int intArr[n];
    for (int i = 0; i < n; i++)
    {
        intArr[i]=arr[i]-'a';
    }

    //now doing the integer count sort on the converted array
    countSortint(intArr,n);

    //now converting the sorted intArray to char
    //and replacing it with the original char array
    for (int i = 0; i < n; i++)
    {
        arr[i]='a'+intArr[i];
    }
}

int main()
{
    int a[]={1,3,2,3,4,1,6,4,3};
    int n=sizeof(a)/sizeof(a[0]);
    countSortint(a,n);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }

    char carr[]={'c','b','c','b','e','a','c','f','a'};
    n=sizeof(carr)/sizeof(carr[0]);
    countSortchar(carr,n);
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<carr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
