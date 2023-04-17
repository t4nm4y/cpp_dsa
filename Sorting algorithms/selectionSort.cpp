//most basic sorting method in which the smallest element comes at first, each time the loop runs
//each time find the min element of the unsorted array and swap it with the first element of the unsorted array
//now only rest of the array will remaing unsorted

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<endl;
    int n;
    int arr[]={4,7,2,9,1};
    n=sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i]>arr[j])
            {
                int temp=arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        } 
    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    return 0;
}