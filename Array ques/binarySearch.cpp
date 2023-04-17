#include<iostream>
using namespace std;
int BinarySearch(int a[],int n, int key)
{
    int s=0, e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if (a[mid]==key)
        {
            return mid;
        }
        else if (a[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }   
    return -1;
}
int main()
{
    int n,key;
    cout<<"\nEnter the size of the array: ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the elements of the array: ";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"\nenter the element u wanna search: ";
    cin>>key;
    cout<<BinarySearch(a,n,key)<<endl;
    return 0;
}