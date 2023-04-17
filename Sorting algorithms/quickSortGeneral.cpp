//we select a random element and place it at the position where it
//would have been in the sorted element.

//here pivot(pi) represents this element that we are currently working on.

//to get the pivot to its correct position means that usse pahle wale elements usse chotte h
//aur uske baad ke elements usse bde h.
    
//then we will again call the func for pi ke baad wali array and pahle waali array

//in this code: pivot=last element of array

#include<bits/stdc++.h>
using namespace std;
int c=0;
void swap(int arr[], int i, int j)
{
    if (i==j)
        return;
    
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void quickSort(int arr[], int start, int end)
{
    int i=start;
    int j=end;
    // int pi=arr[end]; //change the pivot here
    int pi=arr[(start+end)/2]; //change the pivot here
    while(j>=i)
    {
        while(arr[i]<pi)
        i++;
        while(arr[j]>pi)
        j--;
        if(i<=j)//j>=i
        {
            swap(arr,i,j);
            i++; j--;
        }
    }
    if (start < j)
        quickSort(arr, start, j);

    if (i < end)
        quickSort(arr, i, end);
    c++;
}
int main()
{
    int arr[]={80,10,70,40,60,20,30,50};
    // int arr[]={10,20,30,40,50,60,70,80};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);

    cout<<"\nThe sorted array is: ";
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
    cout<<endl<<"no. of steps taken: "<<c<<endl;
    return 0;
}