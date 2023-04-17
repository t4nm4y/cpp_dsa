
#include<bits/stdc++.h>
using namespace std;
int arr[10]={0};
void insert(int n)
{
    int key;
    for(int i=0; i<7; i++){
    key=(n+i)%7;
    if (arr[key]==0)
    {
        arr[key]=n;
        break;
    }
    }
}

int main()
{
    int n;
    cout<<"\nEnter the amount of nos. u wanna insert: ";
    cin>>n;
    cout<<"Enter the nos.:\n";
    int val;
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        insert(val);
    }
    for (int i = 0; i < 7; i++)
    {
        cout<<i<<"|-> "<<arr[i];
        cout<<endl;
    }
    cout<<endl;
    return 0;
}