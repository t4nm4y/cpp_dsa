//1. find the count of every distinct element
//2. add the elements in the sorted array acc to their count
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

void countSortint(int arr[], int n)
{
    int m=arr[0];
    for (int i = 0; i < n; i++)
    m=max(m,arr[i]);

    int countArray[m+1]={0};
    for(int i=0; i<n; i++)
    countArray[arr[i]]++;
    
    int i=0, j=0;
    while (i<=m)
    {
        if(countArray[i]>0)
        {
            arr[j]=i;
            countArray[i]--;
            j++;
        }
        else i++;
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

    //now converting the sorted intArray to char and replacing it with the original char array
    for (int i = 0; i < n; i++)
    {
        arr[i]='a'+intArr[i];
    }
}

int main()
{
    // for integer array:
    cout<<endl;
    int a[]={1,9,2,3,4,1,6,4,3};
    int n=sizeof(a)/sizeof(a[0]);
    countSortint(a,n);
    printArray(a,n);

    //for char array:
    char carr[]={'c','b','c','b','e','a','c','f','a'};
    n=sizeof(carr)/sizeof(carr[0]);
    countSortchar(carr,n);
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<carr[i]<<" ";
    }
    cout<<endl<<endl;
    
    return 0;
}
