#include<bits/stdc++.h>
using namespace std;
int kthSmallestElement(int a[], int n, int key)
{
    return a[key-1];
}
int main()
{
    int n,key;
    cout<<"\nEnter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the elements of the array: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"\nenter the key: ";
    cin>>key;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[i])
            {
                int temp=arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        } 
    }
    cout<<endl<<kthSmallestElement(arr,n,key)<<endl;
    return 0;
}