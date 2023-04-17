#include <iostream>
using namespace std;
 
int search(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}
int main(void)
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
    cout<<endl;
    int result = search(a, n, key);
    (result == -1)?cout<<"Element is not present in array":cout << "Element is present at index " << result;
    cout<<endl;
    return 0;
}