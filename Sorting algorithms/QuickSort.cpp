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
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int findPosition(int arr[], int start, int end)
{
    int i=start-1;
    int pi=arr[end];
    for (int j = start; j < end; j++)
    {
        if (arr[j]<pi)
        {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,end);
    return i+1; 
}

//this not working correctly:
// int findPositionMid(int arr[], int start, int end)
// {
//     int i=start-1;
//     int pi=arr[(end+start)/2];
//     for (int j = start; j < end; j++)
//     {
//         if (arr[j]<pi)
//         {
//             i++;
//             swap(arr,i,j);
//         }
//     }
//     swap(arr,i+1,end);
//     return i+1; 
// }

void quickSort(int arr[], int start, int end)
{
    if (start<end)
    {
        int pi= findPosition(arr,start,end);
        quickSort(arr,start,pi-1);
        quickSort(arr,pi+1,end);
    }
    c++;
}
int main()
{
    int arr[]={10,20,30,40,50,60,70,80};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);

    cout<<"\nThe sorted array is: ";
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
    cout<<endl<<"no. of steps taken: "<<c<<endl;
    return 0;
}