#include <iostream>
using namespace std;
 
int search(string arr[], int n, string key)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}
int main(void)
{
    int n;
    string key;
    cout<<"\nEnter the size of the array: ";
    cin>>n;
    string a[n];
    cout<<"\nEnter the strings of the array: ";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"\nenter the string u wanna search: ";
    cin>>key;
    cout<<endl;
    int result = search(a, n, key);
    (result == -1)?cout<<"string is not present in array":cout << "string is present at index " << result;
    cout<<endl;
    return 0;
}