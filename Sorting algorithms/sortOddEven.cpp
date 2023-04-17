//given an int array, sort such that first portion of the array contains all odd in descending order, and
//the rest portion contains all even in ascending order

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
void insertionSortDecs(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
       int current = arr[i];
       int j=i-1;
       while (arr[j]<current && j>=0) 
       {
           arr[j+1]=arr[j];
           j--;
       }
       arr[j+1]=current; 
    }
}
void insertionSortAcs(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
       int current = arr[i];
       int j=i-1;
       while (arr[j]>current && j>=0) 
       {
           arr[j+1]=arr[j];
           j--;
       }
       arr[j+1]=current; 
    }
}
void sortArray(int a[], int n)
{
    //creating seperate odd array and sorting it
    int c=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]%2!=0)
        c++;
    }
    int oddCount=c;
    int oddArray[c];
    int j=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]%2!=0)
        oddArray[j++]=a[i];
    }
    insertionSortDecs(oddArray,c);

    //creating seperate even array and sorting it
    int evenArray[n-c];
    j=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]%2==0)
        evenArray[j++]=a[i];
    }
    insertionSortAcs(evenArray,n-c);

    //combining the odd and even sorted arrays
    j=0;
    for (int i = 0; i < n; i++)
    {
        if (i<oddCount)
        a[i]=oddArray[i];
        else
        a[i]=evenArray[j++];
    }
}
int main()
{
    int a[]={1,2,3,4,5,8,7,6,10};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<"\nOriginal array: ";
    printArray(a,n);

    cout<<"\nSorted array: ";
    sortArray(a,n);
    printArray(a,n);
    return 0;
}